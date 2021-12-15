#pragma once
#include<iostream>
#include<string>

namespace abc {
	struct Date {
		int day, month, year;
		Date(int d, int m, int y) : day{ d }, month{ m }, year{ y } {
			std::cout << "Konstruktor Date(): " << d << " | " << m << " | " << y << std::endl;
		}
	};
}