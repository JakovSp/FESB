#pragma once
#include "Employee.h"
namespace com
{
	class Worker : public Employee
	{
	private:
		double _wage;
		int _hours;
	public:
		Worker(std::wstring name, double wage, int hours) :
			Employee{ name },
			_wage{ wage },
			_hours{ hours }
		{
			std::wcout << L"Zaposlenik() " << ToString() << std::endl;
		}

		virtual double CalculatePay() override
		{
			return Employee::CalculatePay() + _wage * _hours;
		}

		virtual std::wstring ToString() const override
		{
			return Employee::ToString() + L", " + std::to_wstring(_wage * _hours);
		}

		virtual ~Worker()
		{
			std::wcout << L"~Radnik() " << ToString() << std::endl;
		}
	};
}