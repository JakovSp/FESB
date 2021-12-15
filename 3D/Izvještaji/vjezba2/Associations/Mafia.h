#pragma once
#include<iostream>
#include<string>

namespace mob {
	class Mafia {
	private:
		std::wstring _name;
		std::wstring _buisness = nullptr;
	public:
		Mafia(std::wstring name, std::wstring buisness) :_name{ name }, _buisness{ buisness } {
			std::wcout << "Konstruktor Mafia(): " << _name << std::endl;
		}
		virtual std::wstring ToString() const {
			return _name + L" " + _buisness;
		}
		virtual void DoIt() {
			std::wcout << "Buisness: " << _buisness << std::endl;
		}
		virtual ~Mafia() {
			std::wcout << "Dekonstruktor ~Mafia(): " << _name << std::endl;
		}
	};
}