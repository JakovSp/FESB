#include<iostream>
#include"Circle.h"
#include"Helpers.h"


using namespace std;
using namespace abc;

int main() {
	SetUTF8(wcout);
	double radius;

	Circle a = Circle(1.0);
	wcout << to_wstring(a.Area()) << endl;
	Circle b;
	try {
		wcout << L"Unesi novi radijus: ";
		cin >> radius;
		b = Circle(radius);
	}catch(exception e){
		wcout << e.what() << endl;
	}

	wcout << b.ToString() << endl;

	auto c = f(a);
	wcout << L"površina od c: " << c.Area() << endl; // hello LaTeX
	
	Circle* const p = new Circle(3.0);
	g(p);
	delete(p);
	Circle* q = h();
	cout << q->Area() << endl;
	delete(q);

	return 0;
}