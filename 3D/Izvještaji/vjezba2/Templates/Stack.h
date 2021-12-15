#pragma once
#include<iostream>
#include<array>
#include<cassert>

namespace tpl {
	template<typename T, size_t N>
	class Stack {
	private:
		std::array<T, N> _elements;
		size_t _count;
	public:
		Stack() :_count{ 0 }, _elements() {};
		void Push(const T&);
		void Pop();
		const T& Top() const;
		bool Empty() const {
			return _count; // size_t jest >= 0
		}
		size_t Size() const { return _count; }
	};

	template<typename T, size_t N>
	void Stack<T, N>::Push(const T& element) {
		_elements.at(_count) = element;
		_count++;
	}

	template<typename T, size_t N>
	void Stack<T, N>::Pop() {
		_count--;
	}

	template<typename T, size_t N>
	const T& Stack<T, N>::Top() const {
		return _elements.at(Size()-1);
	}
	
	template<typename T, size_t N>
	inline void Show(Stack<T, N> stack, int size) {
		while (stack.Size()) {
			std::wcout << stack.Top() << L" ";
			stack.Pop();
		}
		std::cout << std::endl;
	}
}