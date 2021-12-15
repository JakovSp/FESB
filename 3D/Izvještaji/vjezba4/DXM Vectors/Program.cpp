#include<iostream>
#include<windows.h>
#include<DirectXMath.h>
#include<xmmintrin.h>
#include"Functions.h"

using namespace std;
using namespace DirectX;

int main(){
	if(!XMVerifyCPUSupport())
		return 0;
	__m128 x{1.0};
	XMFLOAT4 f4{ 1.0f,1.0f,1.0f,0.0f };
	cout << "f4: " << ToString(f4) << endl;

	XMVECTOR u = XMLoadFloat4(&f4);
	cout << "Duljina: " << XMVector3Length(u).m128_f32[0] << endl;

	XMVECTOR v = XMLoadFloat4(&f4);
	XMVECTOR w = XMVector3Cross(u, v);
	XMStoreFloat4(&f4,w);
	cout << "v x w = " << ToString(f4) << endl;
	
	float scalar = XMVector3Dot(u, v).m128_f32[0];
	cout << "v . w = " << scalar << endl;

	const XMVECTORF32 v32{ 1.0f,2.0f,3.0f,0.0f };
	XMMATRIX M = XMMatrixSet(
		1.0f, 2.0f, 3.0f, 0.0f,
		5.0f, 6.0f, 7.0f, 0.0f,
		8.0f, 7.0f, 6.0f, 0.0f,
		4.0f, 3.0f, 2.0f, 1.0f
	);
	XMVECTOR* p = f(v, v, v, v, v, v, v, v);
	u = XMVector3Transform(v, M);
	XMStoreFloat4(&f4, u);
	cout << "v * M = " << ToString(f4) << endl;

	u = XMVector3TransformNormal(v, M);
	XMStoreFloat4(&f4, u);
	cout << "v * M = " << ToString(f4) << endl;
	
	u = XMVector3TransformCoord(v, M);
	XMStoreFloat4(&f4, u);
	cout << "v * M = " << ToString(f4) << endl;

	C c{ v, v, v, v, v, v, v, v };

	return 0;
}
