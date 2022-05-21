#pragma once

#include<iostream>

using namespace std;

template <typename T>
class Queue {
private:
    T* que;
    int maxSize;
    int noOfElements;
    int front;
    int rear;
    bool isEmpty();
    bool isFull();
public:
    Queue(int);
    ~Queue();
    bool enqueue(T);
    bool dequeue(T&);
    bool peek(T&);
    void print();
};

