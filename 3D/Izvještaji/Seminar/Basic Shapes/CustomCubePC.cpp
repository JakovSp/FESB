
#include "pch.h"
#include "CustomCube.h"

using namespace vxe;
using namespace std;

using namespace DirectX;

CustomCube<VertexPositionColor, uint16_t>::CustomCube()
{
	DebugPrint(string("\t Cube<VertexPositionColor, uint16_t>::Ctor ...\n"));
}

concurrency::task<void> CustomCube<VertexPositionColor, uint16_t>::CreateAsync(_In_ ID3D11Device2* device)
{
	DebugPrint(string("\t Cube<PositionColorVertex, uint16_t>::CreateAsync() ...\n"));

	float x = _depth / 2;
	float y = _height / 2;
	float z = _width / 2;
	float r = _red;
	vector<VertexPositionColor> vertices = {
		VertexPositionColor(XMFLOAT3(-x, y, -z),		XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f)),
		VertexPositionColor(XMFLOAT3(x, y, -z),			XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f)),
		VertexPositionColor(XMFLOAT3(x, y, z),			XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f)),
		VertexPositionColor(XMFLOAT3(-x, y, z),			XMFLOAT4(r, 0.0f, 0.0f, 1.0f)),
		VertexPositionColor(XMFLOAT3(-x, -y, -z),		XMFLOAT4(r, 0.0f, 1.0f, 1.0f)),
		VertexPositionColor(XMFLOAT3(x, -y, -z),		XMFLOAT4(r, 1.0f, 0.0f, 1.0f)),
		VertexPositionColor(XMFLOAT3(x, -y, z),			XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f)),
		VertexPositionColor(XMFLOAT3(-x, -y,z),			XMFLOAT4(r, 0.0f, 0.0f, 1.0f))
	};

	vector<uint16_t> indices = {
		3, 1, 0,
		2, 1, 3,
		0, 5, 4,
		1, 5, 0,
		3, 4, 7,
		0, 4, 3,
		1, 6, 5,
		2, 6, 1,
		2, 7, 6,
		3, 7, 2,
		6, 4, 5,
		7, 4, 6,
	};

	return Mesh::CreateAsync(device, vertices, indices, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

concurrency::task<void> CustomCube<VertexPositionColor, uint16_t>::LoadAsync(_In_ ID3D11Device2* device, const wstring&)
{
	DebugPrint(string("\t CustomCube<VertexPositionColor, uint16_t>::LoadAsync() ...\n"));

	vector<VertexPositionColor> vertices{};
	vector<uint16_t> indices{};

	// Loading ...

	return Mesh::CreateAsync(device, vertices, indices);
}


concurrency::task<void> CustomCube<VertexPositionColor, uint16_t>::CreateAsync(_In_ ID3D11Device2* device, const vector<char>&)
{
	DebugPrint(string("\t CustomCube<VertexPositionColor1, uint16_t>::CreateAsync() ...\n"));

	vector<VertexPositionColor> vertices{};
	vector<uint16_t> indices{};

	// Extract (parse) vertices from memory

	return Mesh::CreateAsync(device, vertices, indices);
}