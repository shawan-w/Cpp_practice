#pragma once

class Node
{
public:
    int data;
    Node* next; // node pointer inside of each node, purpose is to point another node in the list
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
};
