#pragma once
#include<iostream>

namespace fin {
	class Account : public IAccount {
	private:
		double _balance;
	public:
		Account(double balance) :_balance{ balance } {};
		virtual bool Deposit(double amount) override {
			_balance += amount;
			std::cout << "Deposit: " << amount << std::endl;
			return _balance;
		}
		virtual bool Withdraw(double amount) override {
			_balance -= amount;
			std::cout << "Withdraw: " << amount << std::endl;
			return _balance;
		}
		virtual void Balance(double balance) override {
			_balance = balance;
			std::cout << "New balance: " << balance << std::endl;
		}
		virtual double Balance() const override { return _balance; }
	};
}