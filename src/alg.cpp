// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int priorityOperations(char operSymb) {
	switch (operSymb)
	{
	case '(':
		return 0;
	case ')':
		return 1;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 3;
	default:
		break;
	}
}

bool isOperation(char nowSymb) {
	return (nowSymb == '+' || nowSymb == '-' || nowSymb == '*' || nowSymb == '/');
}

std::string infx2pstfx(std::string inf) {
	std::string pstfxString;
	TStack<char, 100> stack1;
	for (int i = 0; i < inf.size(); i++) {
		char currentElement = inf[i];
		if (currentElement >= '0' && currentElement <= '9') {
			pstfxString.push_back(currentElement);
			pstfxString.push_back(' ');
		} else if (isOperation(currentElement)) {
			if (currentElement == '(')
				stack1.push(currentElement);
			else if (!stack1.isEmpty() && priorityOperations(currentElement) > priorityOperations(stack1.get()))
				stack1.push(currentElement);
			else if ((!stack1.isEmpty()) && (priorityOperations(currentElement) <= priorityOperations(stack1.get()))) {
				while ((!stack1.isEmpty()) && (priorityOperations(currentElement) > priorityOperations(stack1.get()))) {
					pstfxString.push_back(stack1.pop());
					pstfxString.push_back(' ');
				}
				stack1.push(currentElement);
			} else if (stack1.isEmpty())
				stack1.push(currentElement);
		} else if (currentElement == ')') {
			while ((!stack1.isEmpty()) && (stack1.get() != '(')) {
				pstfxString.push_back(stack1.pop());
				pstfxString.push_back(' ');
			}
		}
	}
	while (!stack1.isEmpty()) {
		pstfxString.push_back(stack1.pop());
		pstfxString.push_back(' ');
	}
    return pstfxString;
}

int eval(std::string pref) {
  // добавьте код
  return 0;
}
