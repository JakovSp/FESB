#pragma once
#include<string>
#include<iostream>

namespace abc {
	class Something {
	private:
		std::wstring _name;
	public:
		Something(std::wstring newname) : _name(newname) {};
		const auto Name() {
			return _name;
		}
		virtual ~Something() {
		}
	};
}