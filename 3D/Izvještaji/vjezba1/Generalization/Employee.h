#pragma once
#include<iostream>
#include<string>
namespace com
{
	class Employee {
	private:
		std::wstring _name;
	public:
		explicit Employee(std::wstring name) : _name{ name } {
			std::wcout << _name << std::endl;
		}

		virtual double CalculatePay() {
			return 0.0;
		}

		virtual std::wstring ToString() const {
			return _name;
		}
		virtual ~Employee();
	};

	Employee::~Employee() {
		std::wcout << L"~Zaposlenik() " << ToString() << std::endl;
	}

}