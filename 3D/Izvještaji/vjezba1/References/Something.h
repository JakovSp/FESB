#pragma once
#include<iostream>

namespace abc {
	class Something
	{
	public:
		Something(int v = -1) : value{ v } {
			std::cout << "Konstruktor je pozvan" << std::endl;
		}
		virtual ~Something()
		{
			std::cout << "Destruktor je pozvan" << std::endl;
		}

		int value;
	};

	void f(const Something& S) {
		// S.value++; const lvalue ref
		std::cout << "Vrijednost lref: " << S.value << std::endl;
	}

	void g(Something&& S) {
		S.value++;
		std::cout << "Vrijednost rref: " << S.value << std::endl;
	}

	void h(const Something& S) {
		std::cout << "Vrijednost clref: " << S.value << std::endl;
	}

	void h(Something&& S) {
		S.value++;
		std::cout << "Vrijednost rref: " << S.value << std::endl;
	}

}
