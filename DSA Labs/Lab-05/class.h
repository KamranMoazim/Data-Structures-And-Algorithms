// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon


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
