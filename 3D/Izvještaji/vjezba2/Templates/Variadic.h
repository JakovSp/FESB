#pragma once
#include<iostream>

namespace tpl {
	void Print() {
		std::wcout << std::endl;
	}
	
	template<typename T, typename... Ts>
	inline void Print(T head, Ts... rest) {
		std::wcout << head << L" ";
		Print(rest...);
	}
}