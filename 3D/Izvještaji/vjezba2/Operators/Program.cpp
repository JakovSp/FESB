#include<iostream>
#include"Something.h"
#include"Smart Pointer.h"

using namespace std;
using namespace abc;
using namespace mem;

int main() {
	try {
		Something* p = new Something(1);
		Something* q = new Something(2);
		SmartPtr<Something> sp = new Something{ 10 };
		SmartPtr<Something> sq = new Something{ 20 };

		cout << endl;
		sp->m();

		cout << endl << "(*sq).m()" << endl;
		(*sq).m();

		cout << endl << "sp = sq" << endl;
		sq = sp;
		sq->m();
		// sp->m(); Read access violation - null pointer assigned

		// throw std::exception("exception");

	} catch (exception e){
		cout << endl << e.what() << endl;
	}

	return 0;
}