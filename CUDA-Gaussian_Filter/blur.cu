#include <iostream>
#include <time.h>
#include <chrono>
#include <ctime>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stdbool.h>
#include <math.h>

#include "include/types.h"
#include "include/stb_image.h"
#include "include/stb_image_write.h"
#include "include/gaussian.h"

using namespace std;
using namespace std::chrono;


float h_GaussianKernel[25] = {2, 4, 5, 4, 2,
							  4, 9, 12, 9, 4,
							  5, 12, 15, 12, 5,
							  4, 9, 12, 9, 4,
							  2, 4, 5, 4, 2};

#define KERNEL_RADIUS 2
#define TILE_SIZE (TILE_W + KERNEL_RADIUS * 2) * (TILE_W + KERNEL_RADIUS * 2)
#define KERNEL_SIZE 25
#define KERNEL_STRIDE 5

__device__ __constant__ float d_GaussianKernel[KERNEL_SIZE];

////////////////////////////////////////////////////////////

__global__ void Grayscale(Pixel3* dev_mem, uint8_t* out)
{
	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	uint8_t gray = (dev_mem[tid].red + dev_mem[tid].green + dev_mem[tid].blue) / 3;
	out[tid] = gray;
}

__global__ void convolutionGPU(uint8_t *d_Result, uint8_t *d_Data, int dataW, int dataH){

	// global mem address for this thread
	const int gLoc = threadIdx.x +
					 blockIdx.x * blockDim.x +
					 threadIdx.y * dataW +
					 blockIdx.y * blockDim.y * dataW;

	float sum = 0;
	float value = 0;

	for (int i = -KERNEL_RADIUS; i <= KERNEL_RADIUS; i++){
		for (int j = -KERNEL_RADIUS; j <= KERNEL_RADIUS; j++){
			
			if (blockIdx.x == 0 && (threadIdx.x + i) < 0)
				value = 0;
			else if ((blockIdx.x == (gridDim.x + 1)) && ((threadIdx.x + i) > blockDim.x + 1))
				value = 0;
			else
			{
				if ((blockIdx.y == 0) && ((threadIdx.y + j) < 0))
					value = 0;
				else if ((blockIdx.y == (gridDim.y + 1)) && ((threadIdx.y + j) > blockDim.y + 1))
					value = 0;
				else
					value = d_Data[gLoc + i + j * dataW];
			}
			sum += (value * d_GaussianKernel[KERNEL_RADIUS + i + KERNEL_STRIDE * (KERNEL_RADIUS + j)]);
		}
	}
	d_Result[gLoc] = (uint8_t)(sum / 159.0f);
}

void cpuGrayscale(Pixel3* in, uint8_t* out, int width, int height){

	int x, y;
	for (y = 0; y < height; ++y){
		for (x = 0; x < width; ++x){
			uint8_t gray = (in[x + y * width].red + in[x + y * width].green + in[x + y * width].blue) / 3;
			out[x + y * width] = gray;
		}
	}
}

void cpuConvolution(unsigned char* in, unsigned char* out, float* kernel, int nx, int ny, int radius){

	for (int m = radius; m < nx - radius; m++)
		for (int n = radius; n < ny - radius; n++){
			float pixel = 0.0;
			size_t c = 0;
			for (int j = -radius; j <= radius; j++)
				for (int i = -radius; i <= radius; i++){
					pixel += in[(n - j) * nx + m - i] * kernel[c];
					c++;
				}
			out[n * nx + m] = (unsigned char)(pixel / 159.0f);
		}
}


int main()
{

	cudaEvent_t start, stop;
	float time;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);

	int width, height, channels;
	Pixel3* h_Image = (Pixel3*)stbi_load("Slike/FESB1.jpg", &width, &height, &channels, STBI_rgb);
	unsigned char* GrayImage =	(unsigned char*)malloc(width * height);
	unsigned char* BlurImage =	(unsigned char*)malloc(width * height);

	auto startCPU = high_resolution_clock::now();

	cpuGrayscale(h_Image, GrayImage, width, height);
	cpuConvolution(GrayImage, BlurImage, h_GaussianKernel, width, height, KERNEL_RADIUS);

	auto stopCPU = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stopCPU - startCPU);
	cout << "CPU Execution Time: " << duration.count() << endl;

	stbi_write_jpg("blurCPU.jpg", width, height, 1, BlurImage, 100);

	///////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned char* h_GPUBlur =	(unsigned char*)malloc(width * height);
	Pixel3* d_SourceImage;
	uint8_t* d_GrayChannel;
	uint8_t* d_BlurChannel;

	cudaMalloc((void **)&d_SourceImage, width * height * channels * sizeof(uint8_t));
	cudaMalloc((void **)&d_GrayChannel, width * height * sizeof(uint8_t));
	cudaMalloc((void **)&d_BlurChannel, width * height * sizeof(uint8_t));
	cudaMemcpy(d_SourceImage, h_Image, width * height * channels * sizeof(unsigned char), cudaMemcpyHostToDevice);
	cudaMemset(d_BlurChannel, 0, width * height);
	cudaMemcpyToSymbol(d_GaussianKernel, h_GaussianKernel, KERNEL_SIZE * sizeof(float));

	dim3 blocks(TILE_W, TILE_H);
	dim3 grids(width / TILE_W + 1, height / TILE_H + 1);

	cudaEventRecord(start, 0);

	Grayscale<<<height, width>>>(d_SourceImage, d_GrayChannel);
	convolutionGPU<<<grids, blocks>>>(d_BlurChannel, d_GrayChannel, width, height);
	cudaMemcpy(BlurImage, d_BlurChannel, width * height, cudaMemcpyDeviceToHost);

	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&time, start, stop);
	cudaEventDestroy(start);
	cudaEventDestroy(stop);
	printf("GPU Execution Time = %f\n", time);

 	stbi_write_jpg("blurGPU.jpg", width, height, 1, BlurImage, 100);

	///////////////////////////////////////////////////////////////////////////////////////////////////

	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	uint8_t* d_BlurChannelFinal = d_GrayChannel;

	cudaMemcpyToSymbol(d_filtGauss, h_filtGauss, KERNEL_SIZE_SEP*sizeof(float));

	cudaEventRecord(start, 0);
	convolutionRowGPU<<<grids, blocks>>>(d_BlurChannel, d_GrayChannel, width, height );
	// cudaMemset(  d_BlurChannelFinal, 0, width * height);
	convolutionColGPU<<<grids, blocks>>>(d_BlurChannelFinal, d_BlurChannel, width, height );
	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&time, start, stop);
	cudaEventDestroy(start);
	cudaEventDestroy(stop);

	printf("GPU Sep Execution Time = %f\n", time);

	cudaMemcpy(BlurImage, d_BlurChannelFinal, width * height, cudaMemcpyDeviceToHost );

 	stbi_write_jpg("blurGPUSep.jpg", width, height, 1, BlurImage, 100);

	///////////////////////////////////////////////////////////////////////////////////////////////////

	cudaFree(d_SourceImage);
	cudaFree(d_GrayChannel);
	cudaFree(d_BlurChannel);

 	stbi_image_free(h_Image);
}
