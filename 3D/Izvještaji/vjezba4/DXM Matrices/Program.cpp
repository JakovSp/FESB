#include<iostream>
#include<windows.h>
#include<DirectXMath.h>
#include<xmmintrin.h>
#include"Functions.h"

using namespace std;
using namespace DirectX;

constexpr float PI = 3.14159265f;

int main() {
	if (!XMVerifyCPUSupport())
		return 0;

	XMFLOAT4X4 f4x4 = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	cout << "f4x4: " << ToString(f4x4) << endl;
	XMMATRIX A = XMLoadFloat4x4(&f4x4);
	XMMATRIX B = XMLoadFloat4x4(&f4x4);
	XMMATRIX C = XMMatrixMultiply(A, B);
	XMStoreFloat4x4(&f4x4, C);
	cout << "C = A * B = " << ToString(f4x4) << endl;

	XMMATRIX R = XMMatrixRotationX(PI / 4);
	XMStoreFloat4x4(&f4x4, R);
	cout << "Rotation = " << ToString(f4x4) << endl;

	XMMATRIX I = GetInverseMatrix(R);
	XMStoreFloat4x4(&f4x4, I);
	cout << "Inverse = " << ToString(f4x4) << endl;

	XMMATRIX T = XMMatrixTranspose(R);
	XMStoreFloat4x4(&f4x4, T);
	cout << "Transpose = " << ToString(f4x4) << endl;

	I = XMMatrixTranspose(R);
	XMStoreFloat4x4(&f4x4, I);
	cout << "Identity = " << ToString(f4x4) << endl;
	
	XMMATRIX* q = f(A, B, C);

	D d{ A, B, C };
}