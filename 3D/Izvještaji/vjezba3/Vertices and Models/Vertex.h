#pragma once
#include<sstream>
#include"../Vectors and Matrices/Vector4.h"

struct Vertex {
	float4 position, color;
	std::string ToString() const {
		std::stringstream info;
		info << "Pozicija: " << position.ToString()<< "  " << "Boja: " << color.ToString();
		return info.str();
	}
};