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
    // TASK 0
    SinglyLinkedList();
    ~SinglyLinkedList();
    bool insertAtStart(int );
    void displayList();
    int countNodes();

    // TASK 1
    bool removeKthNode (int , int& );

    // TASK 2
    void combine(SinglyLinkedList& , SinglyLinkedList& );

    // TASK 3
    void shuffleMerge (SinglyLinkedList& , SinglyLinkedList& );

    // TASK 4
    bool removeLastNode (int& );
    bool removeSecondLastNode (int& );

    // TASK 5
    int findMin();
    int findMax();

    // TASK 6
    int findMinRecursively();

    // TASK 7
    int countEvens();
};
