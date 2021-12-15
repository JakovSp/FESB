#include<iostream>
#include"../Vertices and Models/Vertex.h"
#include"../Vertices and Models/Model.h"
#include"Transforms.h"
#include"Pipeline.h"

using namespace std;

constexpr float PI = 3.14159265f;

int main() {
	Vertex a{ float4{-1,1,0,1}, float4{255,0,0,0} };
	Vertex b{ float4{1,1,0,1}, float4{0,255,0,0} };
	Vertex c{ float4{1,-1,0,1}, float4{0,0,255,0} };
	Vertex d{ float4{-1,-1,0,1}, float4{125,125,125,0} };

	Model model{ a,b,c,d };

	cout << "Model: " << endl << model.ToString() << endl;

	float4x4 S = CreateScaleMatrix(10.0, 10.0, 10.0);
	float4x4 R = CreateRotateZMatrix(PI / 4);
	float4x4 T = CreateTransalteMatrix();
	float4x4 W = S * R * T;

	cout << "Scale Matrix: " << S.ToString() << endl;
	cout << "RotateZ Matrix: " << R.ToString() << endl;
	cout << "Translate Matrix: " << T.ToString() << endl;
	cout << "World Transform Matrix: " << W.ToString() << endl;

	return 0;
}