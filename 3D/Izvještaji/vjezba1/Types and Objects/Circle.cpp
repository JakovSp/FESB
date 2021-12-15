#include<iostream>
#include<string>
#include"Circle.h"

using namespace std;
using namespace abc;

#define PI 3.1415926535897;

Circle::Circle(double radius) :
	_radius{ radius }
{
	wcout << ToString() << endl;
}

double Circle::Area() const {
	return _radius * _radius * PI;
}

wstring Circle::ToString() const {
	return L"Circle, radijus: " + to_wstring(_radius) + L"\tPovršine: " + to_wstring(Area());
}

Circle::~Circle() {
	wcout << L"Desktruktor je pozvan" << endl;
}

Circle abc::f(Circle C) {
	Circle newCircle = Circle((double)(C._radius + 10.0));
	return newCircle;
}


void abc::g(Circle* C) {
	C->_radius += 100;
	wcout << to_wstring(C->_radius) << endl;
}

Circle* abc::h() {
	Circle* newCircle = new Circle(0);
	return newCircle;
}
