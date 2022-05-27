#pragma once

#include<iostream>

using namespace std;

template <typename T>
class LinkedList;

template <typename T>
class Node {
private:
    T data;
    Node* next;
public:
    friend LinkedList<T>;
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList();
    void displayList();
    bool insertAtStart(T );
    bool insertAtEnd(T );
    void displayReverseListUsingLoop();
    bool search(T );
    T findMax();
    ~LinkedList();
};

