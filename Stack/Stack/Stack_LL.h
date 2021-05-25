#pragma once

// LL: Linked list
class Node {
public:
	int data;
	Node* next;
};

class Stack_LL {
private:
	Node* top;	// index of the top element

public:
	Stack_LL();		// non-parameterized constructor, since there is no size for linked-list
	~Stack_LL();

	void push(int value);
	int pop();
	void display();
	int isEmpty();
	int isFull();
	int stackTop();
	int peek(int pos);	// pos: count from top of the stack (start from 1)

};
