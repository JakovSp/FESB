#pragma once
#include<iostream>
#include"Date.h"
#include<string>

namespace abc {
	struct Person {
		std::wstring _name;
		const Date _birhtday;
		Person(std::wstring name, const Date birthday) : _name{ name }, _birhtday{ birthday }{
			std::wcout << L"Konstruktor Person(): " << _name << std::endl;
		}
		~Person() {
			std::wcout << L"Dekonstruktor ~Person(): " << _name << std::endl;
		}
	};
}