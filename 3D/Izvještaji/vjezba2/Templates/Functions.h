#pragma once
#include<iostream>

namespace tpl {
	template<typename T>
	T Max(T a, T b) {
		return { a > b ? a : b };
	}
}