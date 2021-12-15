#include<iostream>
#include"Functions.h"
#include"Types.h"
#include"Helpers.h"

using namespace std;
using namespace abc;

int main() {
	SetUTF8(wcout);
	int a = 1;
	int& l = a;
	f(l);
	int&& r = 2;
	f(r);
	f(3);
	Forward(a);
	Forward(r);

	cout << endl;
	auto something = MakeSmart<Something>(10);
	wcout << "Vrijednost: " << something->_value << endl;
	
	cout << endl;
	auto nešto = MakeSmart<Nešto>(10, 29.98, L"abc");
	wcout << "Vrijednost: " << nešto->_value<< " " << nešto->_number << " " << nešto->_name << endl;


	return 0;
}
