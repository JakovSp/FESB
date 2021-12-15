#include<iostream>
#include<string>
#include<cmath>
#include<windows.h>
#include<DirectXMath.h>

using namespace std;
using namespace DirectX;

int Compare(float a, float b, const float epsilon) {
	float c = a - b;
	if (c < epsilon)
		return 0;

	return c>0? 1 : -1;
}

int main() {
	XMVECTOR v = XMVectorSet(1.0, 1.0, 1.0, 0.0);
	XMVECTOR n = XMVector3Normalize(v);
	float length = XMVector3Length(n).m128_f32[0];
	
	float exponent{ 10.0 };
	for (int i = 0; i < 6; i++) {
		length = pow(length, exponent);
		exponent *= 10;
		cout << i+1 << ". length: " << length << endl;
	}

	float a{ 1.0001 };
	float b{ 1.0000 };
	
	cout << "a: " << a << ", b: " << b << endl;
	cout << "Compare(a, b) = " << Compare(a, b, 0) << endl;
	XMVECTOR u = XMVectorSet(1.0001, 1.0, 1.0, 0.0);
	XMVECTOR e = XMVectorSet(0.0002, 0.0001, 0.0001, 0.0);

	bool ok = XMVector3NearEqual(u, v, e);
	cout << "u and e near equal? " << (ok?"true":"false") << endl;

	return 0;
}