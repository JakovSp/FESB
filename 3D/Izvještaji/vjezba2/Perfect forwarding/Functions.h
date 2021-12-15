#pragma once
#include<iostream>
#include<string>
#include"../Operators/Smart Pointer.h"

namespace abc {
	void f(int& lref) {
		std::wcout << L"Prenesena vrijednost: " << lref << std::endl;
	}
	void f(int&& lref) {
		std::wcout << L"Prenesena vrijednost: " << lref << std::endl;
	} 

	template<typename T>
	void Forward(T&& value) {
		f(std::forward<int&&>(value));
	}

	template<typename T, typename ...Ts>
	inline mem::SmartPtr<T> MakeSmart(Ts&&... rest){
		std::cout << "Broj parametara: " << sizeof...(rest) << std::endl;
		return mem::SmartPtr<T>{new T{ std::forward<Ts>(rest)... }};
	}
}