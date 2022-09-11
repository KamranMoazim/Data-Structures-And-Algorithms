#pragma once

#include<iostream>

using namespace std;



class MaxHeap {
    int* arr;
    int maxSize;
    int currentSize;
public:
    bool isFull();
    bool isEmpty();
    MaxHeap(int );
    MaxHeap(const MaxHeap& );
    ~MaxHeap();
    bool insert(int);
    bool removeMax(int& );
    void heapify(int );
    void buildHeap(int*, int);
};

