#include <iostream>
#include "Stack_LL.h"
using namespace std;


Stack_LL::Stack_LL() {
	top = nullptr;
}

Stack_LL::~Stack_LL() {
	Node* p = top;
	while (top) {
		top = top->next;
		delete p;
		p = top;
	}
}

void Stack_LL::push(int value)
{
	Node* temp = new Node;
	if (temp == nullptr)
		cout << "Stack overflow" << endl;
	else
	{
		temp->data = value;
		temp->next = top;
		top = temp;
	}

}

int Stack_LL::pop()
{
	Node* temp = new Node;
	int value = -1;

	if (top == nullptr)
		cout << "Stack is empty." << endl;
	else
	{
		value = top->data;
		temp = top;
		top = top->next;
		delete temp;
	}
	return value;
}

void Stack_LL::display()
{
	Node* p = new Node;
	if (p == nullptr)
		cout << "Stack is empty." << endl;
	else
	{
		p = top;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}
	cout << endl;
}

int Stack_LL::isEmpty()
{
	return top ? 0:1;	// if top != nullptr => Stack is not empty => return 0
}

int Stack_LL::isFull()
{
	Node* p = new Node;
	int result = p ? 0 : 1;		// if p != nullptr => Stack is not full yet => return 0
	delete p;
	return result;	
}

int Stack_LL::stackTop()
{
	int value = -1;
	if (top != nullptr)
		value = top->data;
	return value;
}

int Stack_LL::peek(int pos)
{
	Node* p = top;

	if (isEmpty())
	{
		cout << "Stack is empty" << endl;
		return -1;
	}
	else if (pos == 1)
		return p->data;
	else
	{
		for (int i = 1; i < pos; i++)
		{
			if (p!=nullptr)	p = p->next;
			else
			{
				cout << "Invalid position." << endl;
				return -1;
			}
		}
		return p->data;
	}
}

