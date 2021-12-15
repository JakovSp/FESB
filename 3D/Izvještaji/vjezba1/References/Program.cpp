#include<iostream>
#include"Something.h"

using namespace std;
using namespace abc;

int main() {

	int u = 1;
	int v = 2;
	cout << "v:" << v << endl;
	int* p = &v;
	(*p)++;
	cout << "v:" << v << endl;

	int* pi = (int* const)100; // ok

	int& l = v;

	l = u;
	u++;
	cout << endl << "l = u; u++;" << endl;
	cout << "v:" << v << endl;
	cout << "l:" << l << endl;

	//l++;
	//cout << endl << "l++" << endl;
	//cout << "v:" << v << endl;
	//cout << "u:" << u << endl;

	v = (const int&)40;

	cout << endl << "v = cl" << endl;
	cout << "v:" << v << endl;

	l++;
	cout << endl << "l++" << endl;
	cout << "v:" << v << endl;

	// lvalue referenca se ne može inicijalizirati sa konstantom
	// int& li = 100;
	l = 80; // ok
	cout << "l = 100" << endl;

	const int& cl = 100;
	// cl++;

	int&& r = 100;
	r++;
	cout << endl << "r++" << endl;
	cout << "r:" << r << endl;

	int&& ri = static_cast<int&&>(v);
	// int&& ri = (int&&)(v);

	int&& ri2 = move(v);
	ri2++;
	cout << endl << "ri2++" << endl;
	cout << "ri2:" << ri2 << endl;
	ri++;
	cout << endl << "ri++" << endl;
	cout << "ri:" << ri << endl;

	///////////////////////////////////////////////

	Something a{2};
	f(a);
	f(Something{ 10 });
	g(Something{ 10 });
	g(move(a));

	h(a);
	h(Something{ 20 });
	h(move(a));

	return 0;
}