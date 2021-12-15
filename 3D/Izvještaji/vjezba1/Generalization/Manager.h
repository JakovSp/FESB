#pragma once
#include "Employee.h"
namespace com
{
	class Manager :public Employee {
	private:
		double _salary;
	public:
		Manager(std::wstring name, double salary) : Employee{ name }, _salary{ salary } {
			std::wcout << L"Menadžer() " << ToString() << std::endl;
		}

		virtual double CalculatePay() override
		{
			return Employee::CalculatePay() + _salary;
		}

		virtual std::wstring ToString() const override
		{
			return Employee::ToString() + L"," + std::to_wstring(_salary);
		}

		virtual ~Manager()
		{
			std::wcout << L"~Menadžer() " << ToString() << std::endl;
		}
	};
}