#pragma once
#include<windows.h>
#include<string>

namespace vtl {

#ifdef DEBUG
	void Log() {
		OutputDebugStringW(L"\n");
	}

	template<typename T, typename... Ts>
	inline void Log(const T& head, const Ts&... tail) {
		OutputDebugStringW(head);
		OutputDebugStringW(L" ");
		Log(tail...);
	}

	template<typename T, typename... Ts>
	inline void Log(const T& head, const Ts&... tail, int a, int b) {
		if (a && b)
			Log(head, tail...);

	}
#else
#define Log(x, ...);
#endif 
}