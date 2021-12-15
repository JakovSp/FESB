#include<vector>
#include<iostream>
#include<typeinfo>
#include"Helpers.h"
#include"Employee.h"
#include"Worker.h"
#include"Manager.h"

using namespace com;
using namespace std;

int main()
{
	SetUTF8(wcout);

	auto manager = new Manager{ L"Šef",10000.0 };
	cout << "Tip: " << typeid(*manager).name() << endl << endl;

	vector<Employee*> stuff;
	stuff.push_back(manager);
	stuff.push_back(new Worker{ L"Ana",100.0, 176 });
	stuff.push_back(new Worker{ L"Zoi",200.0, 176 });
	stuff.push_back(new Worker{ L"Žak",300.0, 176 });

	cout << "stuff: " << endl;
	for (const auto& e : stuff)
		wcout << e->ToString() << endl;

	double total = 0.0;
	for (const auto& e : stuff)
		total += e->CalculatePay();
	cout << endl;

	auto employee = new Employee(L"DŽo");
	//manager = const_cast<Employee*>(employee);
	delete employee;

	employee = manager;
	cout << "Plaća: " << to_string(employee->CalculatePay()) << endl << endl;

	for (const auto& p : stuff)
		delete p;

	return 0;
}