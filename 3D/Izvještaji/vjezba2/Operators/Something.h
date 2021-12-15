#pragma once
#include<iostream>

namespace abc {
	struct Something {
	private:
		int _value;
	public:
		Something(int value = 0) : _value{value} {
			std::cout << "Something konstruktor: "<< _value << std::endl;
		}
		void m() {
			std::cout << "vrijednost: " << _value << std::endl;
		}
		~Something() {
			std::cout << "Something destruktor " << _value << std::endl;
		}
	};
}