#pragma once
#include<iostream>

namespace mem {
	template<typename T>
	class SmartPtr {
	private:
		T* _pointee;
	public:
		SmartPtr(T* pT = nullptr) : _pointee{ pT } {}
		SmartPtr& operator=(SmartPtr&);
		T const operator*() const;
		T operator*();
		T const* operator->() const;
		T* operator->();
		~SmartPtr();
	};
	
	template<typename T>
	SmartPtr<T>& SmartPtr<T>::operator=(SmartPtr<T>& p) {
		std::cout << "SmartPtr::operator=()" << std::endl;
		if (this != &p) {
			delete(_pointee);
			_pointee = std::move(p._pointee);
			p._pointee = nullptr;
		}
		return *this;
	}

	template<typename T>
	const T SmartPtr<T>::operator*() const {
		std::cout << "SmartPtr::operator*()" << std::endl;
		return *_pointee;
	}

	template<typename T>
	T SmartPtr<T>::operator*() {
		std::cout << "SmartPtr::operator*()" << std::endl;
		return *_pointee;
	}

	template<typename T>
	const T* SmartPtr<T>::operator->() const {
		std::cout << "SmartPtr::operator->()" << std::endl;
		return _pointee;
	}

	template<typename T>
	T* SmartPtr<T>::operator->() {
		std::cout << "SmartPtr::operator->()" << std::endl;
		return _pointee;
	}

	template<typename T>
	SmartPtr<T>::~SmartPtr() {
			delete(_pointee);
			_pointee = nullptr;
	}
}