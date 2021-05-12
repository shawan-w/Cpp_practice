#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    T* stk;
    int top;
    int size;

public:
    Stack(int sz) {
        size = sz;
        top = -1;
        stk = new T[sz];
    }
    void showStack();
    void push(T x);
    T pop();
};


int main()
{
    int size = 3;
    Stack<double> stack1(size);     // data types e.g. int double float can be freely chosen
    stack1.push(0);
    stack1.showStack();
    stack1.push(1);
    stack1.showStack();
    stack1.push(2.2);
    stack1.showStack();
    stack1.push(3);
    stack1.showStack();
    cout << stack1.pop() << endl;
    stack1.showStack();
}

template <class T>
void Stack<T>::showStack()
{
    for (int i = 0; i < size; i++)
        cout << stk[i] << " ";
    cout << "\n";
}

template <class T>
void Stack<T>::push(T x)
{
    if (top == size - 1)
        cout << "Stack is full." << endl;
    else
    {
        top++;
        stk[top] = x;
    }
}

template <class T>
T Stack<T>::pop()
{
    T x = 0;
    if (top == -1)
        cout << "Stack is empty" << endl;
    else
    {
        x = stk[top];
        top--;
    }
    return x;
}
