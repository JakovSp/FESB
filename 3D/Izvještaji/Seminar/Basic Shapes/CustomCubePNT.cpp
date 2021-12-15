
//
//	CubePN.cpp
//  Defining a cube with a position and normal 
//
//  � VanityXS - DirectX 11.2 Student Engine. Zoraja Consulting d.o.o. All rights reserved.
//	vMay21
//

#include "pch.h"

#include "CustomCube.h"

using namespace vxe;
using namespace std;

using namespace DirectX;

CustomCube<VertexPositionNormalTexture, uint16_t>::CustomCube()
{
	DebugPrint(string("\t Cube<VertexPositionNormalTexture, uint16_t>::Ctor ...\n"));
}

concurrency::task<void> CustomCube<VertexPositionNormalTexture, uint16_t>::CreateAsync(ID3D11Device2* device)
{
	DebugPrint(string("\t Cube<VertexPositionNormalTexture, uint16_t>::CreateAsync() ...\n"));

	float x = _depth / 2;
	float y = _height / 2;
	float z = _width / 2;

	vector<VertexPositionNormalTexture> vertices = {

		// +Y (top face)
		VertexPositionNormalTexture{ XMFLOAT3(-x, y, -z), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(x, y, -z), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(x, y, z), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(-x, y, z), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },

		// -Y (bottom face)
		VertexPositionNormalTexture{ XMFLOAT3(-x, -y, z), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(x, -y, z), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(x, -y, -z), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(-x, -y, -z), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },

		// +X (right face)
		VertexPositionNormalTexture{ XMFLOAT3(x, y, z), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(x, y, -z), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(x, -y, -z), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(x, -y, z), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },

		// -X (left face)
		VertexPositionNormalTexture{ XMFLOAT3(-x, y, -z), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT2(0.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(-x, y, z), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT2(1.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(-x, -y, z), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT2(1.0f, 1.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(-x, -y, -z), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT2(0.0f, 1.0f) },

		// +Z (front face)
		VertexPositionNormalTexture{ XMFLOAT3(-x, y, z), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(0.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(x, y, z), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(1.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(x, -y, z), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(1.0f, 1.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(-x, -y, z), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(0.0f, 1.0f) },

		// -Z (back face)
		VertexPositionNormalTexture{ XMFLOAT3(x, y, -z), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT2(0.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(-x, y, -z), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT2(1.0f, 0.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(-x, -y, -z), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT2(1.0f, 1.0f) },
		VertexPositionNormalTexture{ XMFLOAT3(x, -y, -z), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT2(0.0f, 1.0f) }
	};

	vector<uint16_t> indices = {
		0, 1, 2,
		0, 2, 3,
		4, 5, 6,
		4, 6, 7,
		8, 9, 10,
		8, 10, 11,
		12, 13, 14,
		12, 14, 15,
		16, 17, 18,
		16, 18, 19,
		20, 21, 22,
		20, 22, 23
	};

	return Mesh::CreateAsync(device, vertices, indices);
}

concurrency::task<void> CustomCube<VertexPositionNormalTexture, uint16_t>::LoadAsync(_In_ ID3D11Device2* device, const wstring&)
{
	DebugPrint(string("\t Cube<VertexPositionNormal, uint16_t>::LaodAsync() ...\n"));

	vector<VertexPositionNormalTexture> vertices;
	vector<uint16_t> indices;

	// Loading from a file

	return Mesh::CreateAsync(device, vertices, indices);
}

concurrency::task<void> CustomCube<VertexPositionNormalTexture, uint16_t>::CreateAsync(_In_ ID3D11Device2* device, const vector<char>&)
{
	DebugPrint(string("\t Cube<VertexPositionNormal, uint16_t>::CreateAsync() ...\n"));

	vector<VertexPositionNormalTexture> vertices;
	vector<uint16_t> indices;

	// Extract (parse) vertices from memory

	return Mesh::CreateAsync(device, vertices, indices);
}
