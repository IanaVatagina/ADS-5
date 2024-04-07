// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
	T data[size];
	int top;
public:
	TStack() :top(-1) {}
	T get() const {
		if (!isEmpty())
			return data[top];
		else
			throw std::string("Empty");
	}
	bool isEmpty() const {
		return top == 0;
	}
	bool isFull() const {
		return top == size - 1;
	}
	T pop() {
		if (top >= 0)
			return data[top--];
		else
			throw std::string("End");
	}
	void push(T item) {
		if (top <= size-1)
			data[++top] = item;
		else
			throw std::string("Full");
	}
};

#endif  // INCLUDE_TSTACK_H_
