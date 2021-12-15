#pragma once
#include<cmath>
#include"../Vectors and Matrices/Matrix4x4.h"

float4x4 CreateScaleMatrix(float sx = 1, float sy = 1, float sz = 1) {
	return float4x4{
		sx,0,0,0,
		0,sy,0,0,
		0,0,sz,0,
		0,0,0,1
	};
}

float4x4 CreateRotateZMatrix(float angle = 0.0f) {
	return float4x4{
		std::cos(angle),std::sin(angle),0,0,
		-std::sin(angle),std::cos(angle),0,0,
		0,0,1,0,
		0,0,0,1
	};
}

float4x4 CreateRotateZMatrix(float tx = 0.0f, float ty = 0.0f, float tz = 0.0f) {
	return float4x4{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		tx,ty,tz,1
	};
}
