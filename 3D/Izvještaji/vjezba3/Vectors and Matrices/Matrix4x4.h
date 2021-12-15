#pragma once
#include<string>
#include<sstream>

template<typename T>
struct Matrix4x4{
	union {
		struct {
			T a, b, c, d,
				e, f, g, h,
				i, j, k, l,
				m, n, o, p;
		};
		T M[4][4];
	};
	Matrix4x4() {
		M[4][4] = {};
	}
	Matrix4x4(T ta, T tb, T tc, T td, T te, T tf, T tg, T th, T ti, T tj, T tk, T tl, T tm, T tn, T to, T tp){
		a=ta; b=tb; c=tc; d=td;
		e=te; f=tf; g=tg; h=th;
		i=ti; j=tj; k=tk; l=tl;
		m=tm; n=tn; o=to; p=tp;
	}

	T* operator[](uint32_t i) {
		return M[i];
	}
	const T* operator[](uint32_t i) const {
		return (const T*)M[i];
	}
	
	Matrix4x4<T> operator*(const Matrix4x4<T>& mat){
		return Multiply(*this,mat);
	}
	
	std::string ToString() const{
		std::stringstream mat;
		mat << std::endl;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				mat << M[i][j] << " ";
			}
			mat << std::endl;
		}
		return mat.str();
	}
};

template<typename T>
inline Matrix4x4<T> Multiply(const Matrix4x4<T>& mat1,const Matrix4x4<T>& mat2){
	Matrix4x4<T> mat {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				mat[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return mat;
}

typedef Matrix4x4<float> float4x4;
