#pragma once
#include<cmath>
#include"../Vectors and Matrices/Vector4.h"
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

float4x4 CreateViewMatrix(float4& eye, float4& target, float4& up) {
	float4 v = eye - target;
	v = Normalize(v);
	float4 r = Cross(v, up);
	r = Normalize(r);
	float4 u = Cross(v, r);
	return float4x4{
		r.x,	u.x,	v.x,	0,
		r.y,	u.y,	v.y,	0,
		r.z,	u.z,	v.z,	0,
		-Dot(eye, r), -Dot(eye,u), -Dot(eye,v), 1
	};
}

float4x4 CreateProjectionMatrix(float angle, float ratio, float n, float f){
	return float4x4{
		1/(ratio*tan(angle/2)), 0, 0, 0,
		0, 1 / (tan(angle / 2)), 0, 0,
		0, 0, f/(f-n), 1,
		0, 0, -(n*f)/(f-n), 0
	};
}
