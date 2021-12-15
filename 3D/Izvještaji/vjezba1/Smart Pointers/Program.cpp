#include<iostream>
#include<memory>
#include"Something.h"
#include"Helpers.h"

using namespace abc;
using namespace std;


void main() {
	SetUTF8(wcout);
	auto s = make_shared<Something>(L"s");
	wcout << s->Name() << L" ima "<< to_wstring(s.use_count()) << endl;

	auto s1{ s };
	wcout << s1->Name() << L" ima " << to_wstring(s1.use_count()) << endl;

	auto s2{ s1 };
	wcout << s2->Name() << L" ima " << to_wstring(s2.use_count()) << endl;

	weak_ptr<Something> w{ s2 };
	wcout << L"Weak pointer ima " << to_wstring(w.use_count()) << endl;

	auto u = make_unique<Something>(L"u");
	wcout << (*u).Name() << endl;

	auto u1{ move(u) };
	wcout << (*u1).Name() << endl;

	auto u2{ move(u1) };
	wcout << (*u2).Name() << endl;

	return;
}