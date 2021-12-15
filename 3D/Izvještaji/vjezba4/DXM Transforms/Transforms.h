#pragma once
#include<DirectXMath.h>
#include<iostream>
#include<sstream>

inline std::string ToString(const DirectX::XMFLOAT4X4& M) {
	std::stringstream mat;
	mat << std::endl;
	
	mat << "[ " << M._11 << " " << M._12 << " " << M._13 << " " << M._14 << " ]" << std::endl;
	mat << "[ " << M._21 << " " << M._22 << " " << M._23 << " " << M._24 << " ]" << std::endl;
	mat << "[ " << M._31 << " " << M._32 << " " << M._33 << " " << M._34 << " ]" << std::endl;
	mat << "[ " << M._41 << " " << M._42 << " " << M._43 << " " << M._44 << " ]" << std::endl;

	return mat.str();
}

inline void DisplayXMMatrix(const std::string& message, const DirectX::CXMMATRIX& M) {
	DirectX::XMFLOAT4X4 mat;
	DirectX::XMStoreFloat4x4(&mat, M);
	std::cout << message << std::endl;
	std::cout << ToString(mat);
}

inline DirectX::XMMATRIX CreateViewportMatrix(int x, int y, float width, float height, float zmin, float zmax) {
	return DirectX::XMMATRIX{
		width / 2, 0, 0, 0,
		0, -height / 2, 0, 0,
		0, 0, zmax - zmin, 0,
		x + width / 2, y + height / 2, zmin, 1
	};
}

DirectX::XMMATRIX CreateInverseMatrix(DirectX::CXMMATRIX mat) {
	DirectX::XMMATRIX mat2 = mat;
	mat2.r[3] = DirectX::XMVECTOR{ 0,0,0,1 };
	DirectX::XMVECTOR Inverse = DirectX::XMMatrixDeterminant(mat2);
	return XMMatrixInverse(&Inverse, mat2);
}