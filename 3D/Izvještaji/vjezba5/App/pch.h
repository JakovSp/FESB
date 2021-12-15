#pragma once
#include <agile.h>
#include <wrl.h>
#include <string>

#if defined (_DEBUG)
inline void DebugPrint(){
	OutputDebugStringW(L"\n");
}

template<typename T, typename... Tail>
inline void DebugPrint(const T& text, const Tail& ...tail)
{
	//OutputDebugStringW(text.c_str());
	OutputDebugStringW(L" ");
	DebugPrint(tail...);
}
#else
#define DebugPrint(x);
#endif