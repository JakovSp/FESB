#pragma once
#include<iostream>
#include<string>
#include"Mafia.h"

namespace mob {
	class Boss {
	private:
		std::wstring _name;
		Mafia* _mafia = nullptr;
	public:
		Boss(std::wstring name) : _name{ name } {
			std::wcout << "Konstruktor Boss(): " << name << std::endl;
		}
		virtual std::wstring ToString() const {
			return _name;
		}
		void SetMafia(Mafia* mafia) {
			_mafia = mafia;
			// std::wstring << "Boss -> " << mafia->ToString() << std::endl;
		}
		virtual void Order(void) {
			_mafia->DoIt();
		}

		virtual ~Boss() {
			std::wcout << "Dekonstruktor ~Boss(): " << _name << std::endl;
		}

	};
}