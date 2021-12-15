#include<iostream>
#include"Vertex.h"
#include"Model.h"
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
	float4x4 T = CreateTranslateMatrix();
	float4x4 W = S * R * T;

	cout << "Scale Matrix: " << S.ToString() << endl;
	cout << "RotateZ Matrix: " << R.ToString() << endl;
	cout << "Translate Matrix: " << T.ToString() << endl;
	cout << "World Transform Matrix: " << W.ToString() << endl;

	Model object = Transform(model, W);
	cout << "World Object: " << object.ToString() << endl;

	float4 eye{ 0.0f, 0.0f, -5.0f, 1.0f };
	float4 target{ 0.0f, 0.0f, 0.0f, 1.0f };
	float4 up{ 0.0f, 1.0f, 0.0f, 0.0f };

	float4x4 V = CreateViewMatrix(eye, target, up);
	cout << "View Transform Matrix: " << V.ToString() << endl;
	object = Transform(object, V);
	cout << "View Object: " << object.ToString() << endl;

	float width = 40.0f;
	float height = 25.0f;

	float4x4 P = CreateProjectionMatrix(PI / 3, width/height, 0.1, 100);
	cout << "Projection Matrix: " << P.ToString() << endl;
	object = Transform(object, P);
	cout << "Clip Object: " << object.ToString() << endl;

	object = PerspectiveDivide(object);
	cout << "Normalized Object: " << object.ToString() << endl;

	float4x4 D = CreateViewportMatrix(0, 0, 40, 25, 0, 1);
	cout << "Viewport Matrix: " << D.ToString() << endl;
	object = Transform(object, D);
	cout << "Screen Object: " << object.ToString() << endl;


	return 0;
}