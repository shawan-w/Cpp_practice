#pragma once

class Node
{
public:
    int data;   // the value of node
    Node* next; // a pointer inside of each node, to point the next node / NULL


    friend class LinkedList;
};

class LinkedList
{
private:
    Node* head;
public:
    LinkedList() { head = NULL; }  // initialization
    LinkedList(int A[], int n);
    ~LinkedList();

    void DisplayList();
    int CountNodes();
    void InsertNode(int index, int x);
    void DeleteNode(int index);

    Node* getHead();    // return the address of list's head
    void Display_recursive(Node* ptr);           // return numbers from top (= head node)
    void Display_reversedRecursive(Node *ptr);   // return numbers from bottom (= tail node)
};
