#pragma once

#include<iostream>

using namespace std;


template <typename T>
class MaxHeap {
    T* arr;
    int maxSize;
    int currentSize;
public:
    bool isFull();
    bool isEmpty();
    MaxHeap(int );
    MaxHeap(const MaxHeap& );
    ~MaxHeap();
    bool insert(T);
    bool removeMax(T& );
    void heapify(int );
    void buildHeap(T*, int);
};

