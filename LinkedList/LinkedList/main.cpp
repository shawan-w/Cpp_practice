#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    int A[] = { 1, 2, 3, 4, 5, 6 };
    LinkedList list1(A, 6);

    list1.DisplayList();
    cout << "Length of the linked list: " << list1.CountNodes() << endl;

    list1.InsertNode(3, 99);
    list1.InsertNode(7, 99);
    list1.InsertNode(10, 99);
    list1.DisplayList();

    list1.DeleteNode(0);
    list1.DisplayList();

    list1.DeleteNode(3);
    list1.DeleteNode(0);
    list1.DeleteNode(10);
    list1.DeleteNode(4);
    list1.DisplayList();
    cout << "Length of the linked list: " << list1.CountNodes() << endl;

    return 0;
}