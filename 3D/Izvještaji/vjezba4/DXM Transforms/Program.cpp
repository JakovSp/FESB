#include<iostream>
#include<DirectXMath.h>
#include"Vertex.h"
#include"Model.h"
#include"Transforms.h"
#include"Pipeline.h"

using namespace std;
using namespace DirectX;

constexpr float PI = 3.14159265f;

int main() {
	
	Vertex a{ XMFLOAT4{-1,1,0,1},	XMFLOAT4{255,0,0,0} };
	Vertex b{ XMFLOAT4{1,1,0,1},	XMFLOAT4{0,255,0,0} };
	Vertex c{ XMFLOAT4{1,-1,0,1},	XMFLOAT4{0,0,255,0} };
	Vertex d{ XMFLOAT4{-1,-1,0,1},	XMFLOAT4{125,125,125,0} };
	Model model{ a,b,c,d };
	cout << model.ToString() << endl;

	XMMATRIX S = XMMatrixScaling(2.0, 2.0, 2.0);
	XMMATRIX R = XMMatrixRotationZ(PI/4);
	XMMATRIX T = XMMatrixTranslation(0.0, 0.0, 0.0);
	XMMATRIX W = XMMatrixMultiply(XMMatrixMultiply(S, R), T);

	DisplayXMMatrix(string("World Transform"), W);
	Model object = Transform(model, W);
	cout << "World objekt: " << object.ToString() << endl;

	XMVECTOR eye = XMVectorSet(0.0f, 0.0f, -6.0f, 1.0f);
	XMVECTOR target = XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	XMVECTOR up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	XMMATRIX V = XMMatrixLookAtLH(eye, target, up);
	DisplayXMMatrix(string("Camera Transform"), W);
	object = Transform(object, V);
	cout << "Camera objekt: " << object.ToString() << endl;

	XMMATRIX P = XMMatrixPerspectiveFovLH(PI / 3, 40.0f / 25.0f, 0.1, 100);
	DisplayXMMatrix(string("Perspective Transform"), P);
	object = Transform(object, P);
	cout << "Clip objekt: " << object.ToString() << endl;

	object = PerspectiveDivide(object);
	cout << "NDC objekt: " << object.ToString() << endl;

	XMMATRIX D = CreateViewportMatrix(0, 0, 40, 25, 0, 1);
	DisplayXMMatrix(string("Viewport Transform"), D);
	object = Transform(object, D);
	cout << "Screen objekt: " << object.ToString() << endl;

	XMMATRIX M = CreateInverseMatrix(D);
	object = Transform(object, D);
	cout << "NDC objekt: " << object.ToString() << endl;

	return 0;
}