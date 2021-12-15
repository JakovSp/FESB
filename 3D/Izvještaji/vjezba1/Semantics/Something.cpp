#include<iostream>
#include"Something.h"

using namespace std;
using namespace abc;

Something::Something(int i): _ptr{ new int{i} } {
	cout << *_ptr << endl;
}

Something::Something(const Something& S) : _ptr{ S._ptr } {
	cout << "CC" << endl;
}

Something::Something(Something&& S) noexcept : _ptr{move(S._ptr)} {
	cout << "MC" << endl;
	S._ptr = nullptr;
}


Something& Something::operator = (const Something& S) {
	cout << "CAO" << endl;
	if (this != &S) {
		this->_ptr = S._ptr;
	}
	return *this;
}

Something& Something::operator = (Something&& S) noexcept {
	cout << "MAO" << endl;
	if (this != &S) {
		_ptr = move(S._ptr);
	}
	S._ptr = nullptr;
	return *this;
}

Something::~Something(){
	if (_ptr) {
		cout << "Destruktor je pozvan " << *_ptr << endl;
	} else {
		cout << "Destruktor je pozvan " << 0 << endl;
	}

	delete _ptr;
}