#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<xmmintrin.h>
#include<windows.h>
#include<DirectXMath.h>


inline DirectX::XMVECTOR* XM_CALLCONV 
f(	DirectX::FXMVECTOR v1, DirectX::FXMVECTOR v2, 
	DirectX::FXMVECTOR v3, DirectX::GXMVECTOR v4,
	DirectX::HXMVECTOR v5, DirectX::HXMVECTOR v6,
	DirectX::CXMVECTOR v7, DirectX::CXMVECTOR v8){	
	std::cout << typeid(v1).name() << std::endl;
	return new DirectX::XMVECTOR;
}


std::string ToString(DirectX::XMFLOAT4& vec){
	std::stringstream out;
	out << "[" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << "]";
	return out.str();
}
	
class C {
public:
	C(	DirectX::FXMVECTOR v1, DirectX::FXMVECTOR v2,
		DirectX::FXMVECTOR v3, DirectX::GXMVECTOR v4,
		DirectX::HXMVECTOR v5, DirectX::HXMVECTOR v6,
		DirectX::CXMVECTOR v7, DirectX::CXMVECTOR v8) {
		std::cout << typeid(v1).name() << std::endl;
	}
};