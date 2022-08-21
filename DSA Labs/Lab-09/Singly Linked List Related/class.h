#pragma once

#include<iostream>

using namespace std;


class SinglyLinkedList;


class Node {
private:
    int data;
    Node* next;
public:
    friend class SinglyLinkedList;
};


class SinglyLinkedList {
private:
    Node* head;
    int findMinPrivate(Node* , int );
    int countEvensPrivate(Node* , int );
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    bool insertAtStart(int );
    void displayList();
    int countNodes();
    bool removeKthNode (int , int& );
    void combine(SinglyLinkedList& , SinglyLinkedList& );
    void shuffleMerge (SinglyLinkedList& , SinglyLinkedList& );
    bool removeLastNode (int& );
    bool removeSecondLastNode (int& );
    int findMin();
    int findMax();
    int findMinRecursively();
    int countEvens();

    // TASK 1
    int removeAll (int );
};
