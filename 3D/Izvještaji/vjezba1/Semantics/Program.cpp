#include<iostream>
#include"Something.h"

using namespace abc;
using namespace std;

int main()
{
	Something a{ 1 };
	Something b{ 2 };
	Something c{ 3 };

	cout << endl;
	Something d{ a };
	a = c;

	Something e{ move(c) };

	e = move(d);

	cout << endl;

	return 0;
}