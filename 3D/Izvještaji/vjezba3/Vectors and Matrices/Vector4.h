#pragma once
#include<string>
#include<cmath>
#include<sstream>

template<typename T>
struct Matrix4x4;

template<typename T>
struct Vector4 {
	union {
		T v[4];
		struct {
			T x, y, z, w;
		};
		struct {
			T r, g, b, a;
		};
	};

	Vector4(T t1, T t2, T t3, T t4){
		v[0] = t1;
		v[1] = t2;
		v[2] = t3;
		v[3] = t4;
	}

	T& operator[](uint32_t i){
		return v[i];
	}
	const T& operator[](uint32_t i) const {
		return (const T)(v[i]);
	}

	Vector4<T> inline operator*(const Matrix4x4<T>& mat){
		return Vector4<T>{
				v[0] * mat[0][0] + v[1] * mat[1][0] + v[2] * mat[2][0] + v[3] * mat[3][0],
				v[0] * mat[0][1] + v[1] * mat[1][1] + v[2] * mat[2][1] + v[3] * mat[3][1],
				v[0] * mat[0][2] + v[1] * mat[1][2] + v[2] * mat[2][2] + v[3] * mat[3][2],
				v[0] * mat[0][3] + v[1] * mat[1][3] + v[2] * mat[2][3] + v[3] * mat[3][3],
		};
	}

	Vector4<T> inline operator-(const Vector4<T>& vec){
		return Vector4<T>(
			v[0] - vec[0],
				v[1] - vec[1],
				v[2] - vec[2],
				v[3] - vec[3]
		);
	}

	Vector4<T> inline operator/(const T& k) {
		return Vector4<T>(
			v[0]/k,
			v[1]/k,
			v[2]/k,
			v[3]/k
			);
	}

	std::string ToString() const {
		std::stringstream output;
		output << "[" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << "]";
		return output.str();
	}
};

template<typename T>
T Length(Vector4<T>& vec){
	return std::sqrt(vec[0]* vec[0]+ vec[1]* vec[1]+ vec[2]* vec[2]+ vec[3]* vec[3]);
}

template<typename T>
T Dot(Vector4<T>& v1,Vector4<T>& v2){
	return v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2];
}

template<typename T>
Vector4<T> Cross(Vector4<T>& v1,Vector4<T>& v2){
	return 	Vector4<T>{
		(v1[1] * v2[2]) - (v1[2] * v2[1]),
		(v1[2] * v2[0]) - (v1[0] * v2[2]),
		(v1[0] * v2[1]) - (v1[1] * v2[0]),
		T()
	};
}

template<typename T>
Vector4<T> Normalize(Vector4<T>& vec){
	return Vector4<T>(
		vec[0] / Length(vec),
			vec[1] / Length(vec),
			vec[2] / Length(vec),
			vec[4] / Length(vec)
	);
}

typedef Vector4<float> float4;
