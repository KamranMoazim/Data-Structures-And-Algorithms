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

