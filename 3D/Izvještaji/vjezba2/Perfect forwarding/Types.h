#pragma once
#include<iostream>
#include<string>

namespace abc {
	struct Something {
		int _value;
			Something(int value) : _value{ value } {
			std::wcout << L"Konstruktor Something()" << std::endl;
		}
		~Something() {
			std::wcout << L"Destrkutor ~Something()" << std::endl;
		}
	};

	struct Ne�to {
		int _value;
		double _number;
		std::wstring _name;
		Ne�to(int value, double number, std::wstring name):
		_value{value}, _number{number}, _name{name}
		{
			std::wcout << L"Konstruktor Ne�to()" << std::endl;
		}
		~Ne�to() {
			std::wcout << L"Destruktor ~Ne�to()" << std::endl;
		}
	};
}