#pragma once
#include<cassert>
#include"IAccount.h"
#include"Account.h"

namespace fin {
	inline IAccount* CreateAccount(double balance){
		return new Account(balance);
	}
	inline void CreateAccount(IAccount** pp, double balance) {
		*pp = new Account(balance);
	}
	inline void TestAccount(IAccount* acc, double dep, double wit) {
		std::cout << "Balance: " << acc->Balance() << std::endl;
		double initial = acc->Balance();
		acc->Deposit(dep);
		acc->Withdraw(wit);
		// acc->Withdraw(wit+1);
		std::cout << "Balance: " << acc->Balance() << std::endl;
		assert(acc->Balance() == initial);
	}
}