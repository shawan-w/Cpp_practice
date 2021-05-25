#pragma once

// Stack - store data wit array
class Stack_array {
private:
	int size;
	int top;		// index of the top element
	int* s;		// pointer to array

public:
	Stack_array(int size);
	~Stack_array();

	void push(int value);	// if array is not full, push a new element to the top
	int pop();				// if array is not empty, pop element on the top
	int peek(int pos);		// pos: count from top of the stack (start from 1)
	int isEmpty();			// return 1 if ture; otherwise return 0
	int isFull();			// return 1 if ture; otherwise return 0
	void display();
	int stackTop();			// if array is empty return -1; return value on the top of the stack
};
