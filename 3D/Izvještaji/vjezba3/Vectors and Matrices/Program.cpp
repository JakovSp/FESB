#include<iostream>
#include"Vector4.h"
#include"Matrix4x4.h"

using namespace std;

int main() {
	float4 u{ 1.0f, 1.0f, 1.0f, 0.0f };
	cout << "u: " << u.ToString() << endl;

	float length = Length(u);
	cout << "||u||: " << length << endl;

	float4 v{ 1.0f, 1.0f, 1.0f, 0.0f };
	cout << "v: " << v.ToString() << endl;
	float4 w = Cross(u,v);
	cout << "w = u x v " << w.ToString() << endl;

	float f = Dot(u,v);
	cout << "u . v = " << f << endl;

	float4x4 A{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	float4x4 B{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	cout << "A: " << A.ToString() << endl;
	cout << "B: " << B.ToString() << endl;

	float4x4 C = Multiply(A, B);
	cout << "C = Multiply(A, B): " << C.ToString() << endl;

	float4x4 D = A * B;
	cout << "D = A*B: " << D.ToString() << endl;

	float4x4 M{ 1.0f, 2.0f, 3.0f, 0.0f, 
				5.0f, 6.0f, 7.0f, 0.0f,
				8.0f, 7.0f, 6.0f, 0.0f,
				4.0f, 3.0f, 2.0f, 1.0f };

	u = v * M;
	cout << "u = v * M: " << u.ToString() << endl;

	v.w = 1.0f;
	cout << endl << "v.w = 1" << endl;
	u = v * M;
	cout << "u = v * M: " << u.ToString() << endl;


	return 0;
}
