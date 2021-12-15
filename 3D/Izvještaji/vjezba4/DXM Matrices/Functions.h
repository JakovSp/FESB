#pragma once
#include<iomanip>
#include<string>
#include<iostream>
#include<sstream>
#include<xmmintrin.h>
#include<windows.h>
#include<DirectXMath.h>

DirectX::XMMATRIX GetInverseMatrix(DirectX::FXMMATRIX mat) {
	DirectX::XMMATRIX mat2 = mat;
	mat2.r[3] = DirectX::XMVECTOR{0,0,0,1};
	DirectX::XMVECTOR Inverse = DirectX::XMMatrixDeterminant(mat2);
	return XMMatrixInverse(&Inverse, mat2);
}

inline DirectX::XMMATRIX* XM_CALLCONV 
f(	DirectX::FXMMATRIX mat1,
	DirectX::FXMMATRIX mat2,
	DirectX::FXMMATRIX mat3	){
	std::cout << typeid(mat1).name();
	return new DirectX::XMMATRIX{};
}

inline std::string ToString(DirectX::XMFLOAT4X4& mat) {
	std::stringstream out;
	out << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			out << mat.m[i][j] << " ";
		}
		out << std::endl;
	}
	return out.str();
}

class D {
public:
	D(DirectX::FXMMATRIX mat1, DirectX::CXMMATRIX mat2, DirectX::CXMMATRIX mat3){
		std::cout << typeid(mat1).name();
	}
};