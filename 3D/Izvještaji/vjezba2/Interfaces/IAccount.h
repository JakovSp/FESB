#pragma once
#include<iostream>

namespace fin {
	struct IAccount {
		virtual bool Deposit(double) = 0;
		virtual bool Withdraw(double) = 0;
		virtual void Balance(double) = 0;
		virtual double Balance() const = 0;
		~IAccount();
	};

	inline IAccount::~IAccount() {
		std::cout << __func__ << std::endl;
	}
}