#include "pch.h"

#include "CustomCube.h"

using namespace vxe;
using namespace std;

using namespace DirectX;

CustomCube<VertexPositionNormalColor, uint16_t>::CustomCube()
{
	DebugPrint(string("\t CustomCube<VertexPositionNormalColor, uint16_t>::Ctor ...\n"));
}

concurrency::task<void> CustomCube<VertexPositionNormalColor, uint16_t>::CreateAsync(ID3D11Device2* device)
{
	DebugPrint(string("\t CustomCube<VertexPositionNormalColor, uint16_t>::CreateAsync() ...\n"));

	float x = _depth / 2;
	float y = _height / 2;
	float z = _width / 2;

	vector<VertexPositionNormalColor> vertices = {

		// +Y (top face)
		VertexPositionNormalColor{ XMFLOAT3(-x, y, -z), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(x, y, -z), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(x, y, z), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(-x, y, z), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },

		// -Y (bottom face)
		VertexPositionNormalColor{ XMFLOAT3(-x, -y, z), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(x, -y, z), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(x, -y, -z), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(-x, -y, -z), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },

		// +X (right face)
		VertexPositionNormalColor{ XMFLOAT3(x, y, z), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(x, y, -z), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(x, -y, -z), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(x, -y, z), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },

		// -X (left face)
		VertexPositionNormalColor{ XMFLOAT3(-x, y, -z), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(-x, y, z), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(-x, -y, z), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(-x, -y, -z), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT4(_red, _green, _blue, _alpha) },

		// +Z (front face)
		VertexPositionNormalColor{ XMFLOAT3(-x, y, z), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(x, y, z), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(x, -y, z), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(-x, -y, z), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT4(_red, _green, _blue, _alpha) },

		// -Z (back face)
		VertexPositionNormalColor{ XMFLOAT3(x, y, -z), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(-x, y, -z), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(-x, -y, -z), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(_red, _green, _blue, _alpha) },
		VertexPositionNormalColor{ XMFLOAT3(x, -y, -z), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT4(_red, _green, _blue, _alpha) }
	};

	vector<uint16_t> indices = {
		0, 2, 1,
		0, 3, 2,
		4, 6, 5,
		4, 7, 6,
		8, 10, 9,
		8, 11, 10,
		12, 14, 13,
		12, 15, 14,
		16, 18, 17,
		16, 19, 18,
		20, 22, 21,
		20, 23, 22
	};

	return Mesh::CreateAsync(device, vertices, indices);
}

concurrency::task<void> CustomCube<VertexPositionNormalColor, uint16_t>::LoadAsync(_In_ ID3D11Device2 * device, const wstring&)
{
	DebugPrint(string("\t CustomCube<VertexPositionNormal, uint16_t>::LaodAsync() ...\n"));

	vector<VertexPositionNormalColor> vertices;
	vector<uint16_t> indices;

	// Loading from a file

	return Mesh::CreateAsync(device, vertices, indices);
}

concurrency::task<void> CustomCube<VertexPositionNormalColor, uint16_t>::CreateAsync(_In_ ID3D11Device2 * device, const vector<char>&)
{
	DebugPrint(string("\t CustomCube<VertexPositionNormal, uint16_t>::CreateAsync() ...\n"));

	vector<VertexPositionNormalColor> vertices;
	vector<uint16_t> indices;

	// Extract (parse) vertices from memory

	return Mesh::CreateAsync(device, vertices, indices);
}
