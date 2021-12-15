#include<iostream>
#include"IAccount.h"
#include"Factory.h"

using namespace std;
using namespace fin;

int main() {
	IAccount* account = CreateAccount(100);
	TestAccount(account, 100, 100);
	delete(account);
	CreateAccount(&account, 1000);
	TestAccount(account, 100, 100);
	delete(account);
	
	return 0;
}