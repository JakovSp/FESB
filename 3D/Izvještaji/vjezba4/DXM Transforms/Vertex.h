#pragma once
#include<DirectXMath.h>

#include<sstream>
#include"../DXM Vectors/Functions.h"

struct Vertex {
	DirectX::XMFLOAT4 position, color;
	std::string ToString() const {
		std::stringstream info;
		info << "[ "<< position.x << " " << position.y << " " << position.z << " " << position.w << " ]";
		return info.str();
	}
};