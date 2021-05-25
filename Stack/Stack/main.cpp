#include <iostream>
#include "Stack_array.h"
#include "Stack_LL.h"

using namespace std;

int main()
{
    int A[] = { 1, 3, 5, 7, 9 };

    // ----- Stack using Array ----- //
    cout << "----- Stack using Array -----" << endl;

    Stack_array stk1(sizeof(A) / sizeof(A[0]));

    // Populate stack with array elements
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        stk1.push(A[i]);
    }
    stk1.push(11);

    cout << "Stack full: " << stk1.isFull() << endl;

    // Display stack;
    cout << "Stack: " << flush;
    stk1.display();

    // Peek
    cout << "Peek at 1st: " << stk1.peek(1) << endl;
    cout << "Peek at 3rd: " << stk1.peek(3) << endl;
    cout << "Peek at 10th: " << stk1.peek(10) << endl;

    // Top element
    cout << "Top element: " << stk1.stackTop() << endl;

    // Pop out elements from stack
    cout << "Popped out elements: " << flush;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        cout << stk1.pop() << ", " << flush;
    }
    cout << endl;
    stk1.pop();

    cout << "Stack empty (1/0): " << stk1.isEmpty() << endl;


    // ----- Stack using Linked List ----- //
    cout << "\n----- Stack using Linked List -----" << endl;

    Stack_LL stk2;

    // Populate stack
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        stk2.push(A[i]);
    }
    stk2.push(11);

    cout << "Stack full: " << stk2.isFull() << endl;

    // Display stack;
    cout << "Stack: " << flush;
    stk2.display();

    // Peek
    cout << "Peek at 1st: " << stk2.peek(1) << endl;
    cout << "Peek at 3rd: " << stk2.peek(3) << endl;
    cout << "Peek at 10th: " << stk2.peek(10) << endl;

    // Top element
    cout << "Top element: " << stk2.stackTop() << endl;

    // Pop out elements from stack
    cout << "Popped out elements: " << flush;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        cout << stk2.pop() << ", " << flush;
    }
    cout << endl;
    cout << "Popped out element: " <<stk2.pop()<< endl;

    cout << "Stack empty (1/0): " << stk2.isEmpty() << endl;

    return 0;

}