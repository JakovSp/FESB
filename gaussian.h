#include"types.h"

#define KERNEL_SIZE_SEP 5
#define KERNEL_RADIUS_SEP 2

float h_filtGauss[KERNEL_SIZE_SEP] = { 1/13.0f, 3/13.0f, 5/13.0f, 3/13.0f, 1/13.0f }; 
__device__ __constant__ float d_filtGauss[KERNEL_SIZE_SEP];

__global__ void convolutionRowGPU( uint8_t *d_Result, uint8_t *d_Data, int dataW, int dataH)
{
	__shared__ uint8_t data[TILE_W + KERNEL_RADIUS_SEP * 2][TILE_H];

	// global mem address for this thread
	const int gLoc = threadIdx.x +
		IMUL(blockIdx.x, blockDim.x) +
		IMUL(threadIdx.y, dataW) +
		IMUL(blockIdx.y, blockDim.y) * dataW;

	int x;
	const int x0 = threadIdx.x + IMUL(blockIdx.x, blockDim.x);

	// case1: left
	x = x0 - KERNEL_RADIUS_SEP;
	if ( x < 0 )
		data[threadIdx.x][threadIdx.y] = 0;
	else
		data[threadIdx.x][threadIdx.y] = d_Data[ gLoc - KERNEL_RADIUS_SEP];

	__syncthreads();
	//case2: right
	x = x0 + KERNEL_RADIUS_SEP;
	if ( x > dataW-1 )
		data[threadIdx.x + 2*KERNEL_RADIUS_SEP][threadIdx.y] = 0;
	else
		data[threadIdx.x + 2*KERNEL_RADIUS_SEP][threadIdx.y] = d_Data[gLoc + KERNEL_RADIUS_SEP];

	__syncthreads();

	//convolution
	float sum = 0;
	x = KERNEL_RADIUS_SEP + threadIdx.x;
	for (int i = -KERNEL_RADIUS_SEP; i <= KERNEL_RADIUS_SEP; i++)
		 sum += ( data[x + i][threadIdx.y] * d_filtGauss[KERNEL_RADIUS_SEP  + i] ); 

	d_Result[gLoc] = (uint8_t)(sum);

}

__global__ void convolutionColGPU( uint8_t *d_Result, uint8_t *d_Data, int dataW, int dataH ){

	__shared__ uint8_t data[TILE_W][TILE_H + KERNEL_RADIUS_SEP * 2];

	// global mem address for this thread
	const int gLoc = threadIdx.x +
		IMUL(blockIdx.x, blockDim.x) +
		IMUL(threadIdx.y, dataW) +
		IMUL(blockIdx.y, blockDim.y) * dataW;

	int y;
	const int y0 = threadIdx.y + IMUL(blockIdx.y, blockDim.y);

	// case1: top
	y = y0 - KERNEL_RADIUS_SEP;
	if ( y < 0 )
		data[threadIdx.x][threadIdx.y] = 0;
	else
		data[threadIdx.x][threadIdx.y] = d_Data[ gLoc - IMUL(dataW,KERNEL_RADIUS_SEP) ];

	__syncthreads();
	//case2: bottom
	y = y0 + KERNEL_RADIUS_SEP;
	if ( y > dataH-1 )
		data[threadIdx.x][threadIdx.y + 2*KERNEL_RADIUS_SEP] = 0;
	else
		data[threadIdx.x][threadIdx.y + 2*KERNEL_RADIUS_SEP] = d_Data[ gLoc + IMUL(dataW,KERNEL_RADIUS_SEP) ];

	__syncthreads();

	//convolution
	float sum = 0;
	y = KERNEL_RADIUS_SEP + threadIdx.y;
	for (int i = -KERNEL_RADIUS_SEP; i <= KERNEL_RADIUS_SEP; i++)
		 sum += ( data[threadIdx.x][y + i] * d_filtGauss[KERNEL_RADIUS_SEP  + i] ); 

	d_Result[gLoc] = (uint8_t)(sum);
}
