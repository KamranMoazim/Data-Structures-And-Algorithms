#pragma once

#include<iostream>

using namespace std;

template <typename T>
class Stack {
private:
    T* stk;
    int maxSize;
    int top;
    bool isEmpty();
    bool isFull();
public:
    Stack(int);
    ~Stack();
    bool push(T);
    bool pop(T&);
    bool getTop(T&);
    void print();
};


template <typename T>
class LinkedListStack;

template <typename T>
class Node {
private:
    T data;
    Node* next;
public:
    friend LinkedListStack<T>;
};


template <typename T>
class LinkedListStack {
private:
    Node<T>* top;
    bool isEmpty();
public:
    LinkedListStack();
    ~LinkedListStack();
    bool push(T);
    bool pop(T&);
    bool getTop(T&);
    void print();
};

