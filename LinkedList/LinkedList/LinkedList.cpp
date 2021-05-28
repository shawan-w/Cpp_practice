#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList(int A[], int n)
{
    Node* tail, * temp;
    int i = 0;

    head = new Node;
    head->data = A[0];
    head->next = NULL;
    tail = head;

    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

LinkedList::~LinkedList()
{
    Node* delPtr = head;

    while (head)
    {
        head = head->next;
        delete delPtr;      // delete node after head node moves to next node
        delPtr = head;
    }
}

void LinkedList::DisplayList()
{
    Node* ptr = head;

    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int LinkedList::CountNodes()
{
    int count = 0;
    Node* ptr = head;

    while (ptr)     // true if ptr != NULL
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void LinkedList::InsertNode(int index, int x)
{
    Node* newNode, * ptr = head;

    if (index<0 || index>CountNodes())
    {
        cout << "invaild index." << endl;
        return;
    }

    newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
    }
    else
        for (int i = 0; i < index-1; i++)
        {
            ptr = ptr->next;
        }
    newNode->next = ptr->next;
    ptr->next = newNode;

    cout << "Value " << x << " at index " << index << " has been inserted." << endl;
}

void LinkedList::DeleteNode(int index)
{
    Node* delNode = head, * ptr;
    int x = -1;

    if (index < 0 || index > CountNodes()-1)
    {
        cout << "Invalid index." << endl;
        return;
    }

    ptr = new Node;

    if (index == 0)
    {
        head = head->next;
        x = delNode->data;
        delete delNode;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            ptr = delNode;
            delNode = delNode->next;
        }

        x = delNode->data;
        ptr->next = delNode->next;
        delete delNode;

    }
    cout << "Value " << x << " at index " << index << " has been deleted." << endl;
}

Node* LinkedList::getHead()
{
    return head;
}

void LinkedList::Display_recursive(Node* ptr)
{
    if (ptr != NULL)
    {
        cout << ptr->data << " ";
        Display_recursive(ptr->next);
    }
}

void LinkedList::Display_reversedRecursive(Node* ptr)
{
    if (ptr != NULL)
    {
        Display_reversedRecursive(ptr->next);
        cout << ptr->data << " ";
    }
}
