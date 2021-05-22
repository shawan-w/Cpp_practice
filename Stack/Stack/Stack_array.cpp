#include <iostream>
#include "Stack_array.h"

using namespace std;

Stack_array::Stack_array(int size)
{
	this->size = size;
	top = -1;
	s = new int[size];
}

Stack_array::~Stack_array()
{
	delete[]s;
}

void Stack_array::push(int value)
{
	if (isFull())
		cout << "Stack overflow." << endl;
	else
	{
		top++;
		s[top] = value;
	}
}

int Stack_array::pop()
{
	int x = -1;
	if (isEmpty())
		cout << "Stack underflow." << endl;
	else
	{
		x = s[top];
		top--;
	}
	return x;
}

int Stack_array::peek(int pos)
{	
	int x = -1;
	// index = top + 1 - pos
	if (isEmpty())
		cout << "Stack is empty!" << endl;
	else if (top + 1 - pos < 0 || top + 1 - pos == size)
		cout << "Invalid position!" << endl;
	else
	{
		x = s[top + 1 - pos];
	}
	return x;
}

int Stack_array::stackTop()
{
	if (isEmpty()) return -1;
	return s[top];
}

int Stack_array::isEmpty()
{
	if (top == -1) return 1;
	return 0;
}

int Stack_array::isFull()
{
	if (top == size - 1) return 1;
	return 0;
}

void Stack_array::display()
{
	if (isEmpty())
		cout << "Stack is empty!" << endl;
	else
	{
		for (int i = top; i >=0 ; i--)
			cout << s[i] << " ";
		cout << endl;
	}
}
