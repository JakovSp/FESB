#include<iostream>
#include<string>
#include"Helpers.h"
#include"Functions.h"
#include"Stack.h"
#include"Variadic.h"

using namespace std;
using namespace tpl;

template<typename T>
using WStack_t = Stack<T, 4>;

int main() {

	SetUTF8(wcout);
	int a = 1;
	int b = 2;
	wcout << to_wstring(Max(a, b)) << endl;

	wstring w1 = L"a";
	wstring w2 = L"b";
	wcout << Max(w1, w2) << endl;

	Stack<int, 10> istack;
	for (int i = 0; i < 8; i++) {
		istack.Push(i);
	}
	Show(istack, 8);

	WStack_t<wstring> wstack;
	for (int i = 0; i < 3; i++) {
		wstack.Push(L"a");
	}
	Show(wstack, 3);

	Print(1);
	Print(1, "a");
	Print(L"a", 1, 1.0, L"b");

	return 0;
}