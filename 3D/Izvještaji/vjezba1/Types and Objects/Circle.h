#pragma once
#include<string>

namespace abc{
	class Circle {		// hello LaTeX
	public:
		double _radius;
		Circle(double=1.0);
		virtual double Area() const;
		virtual std::wstring ToString() const;
		virtual ~Circle();
	};

	Circle f(Circle C);
	void g(Circle* C);
	Circle* h(void);
}