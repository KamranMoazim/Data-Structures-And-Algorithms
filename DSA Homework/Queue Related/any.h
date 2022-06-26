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





template <typename T>
class LinkedListQueue;

template <typename T>
class Node {
private:
    T data;
    Node* next;
public:
    friend LinkedListQueue<T>;
};


template <typename T>
class LinkedListQueue {
private:
    Node<T>* front;
    Node<T>* back;
    bool isEmpty();
public:
    LinkedListQueue();
    LinkedListQueue(const LinkedListQueue& );
    LinkedListQueue operator= (const LinkedListQueue& );
    ~LinkedListQueue();
    bool enqueue(T);
    bool dequeue(T&);
    void print();
};




template <typename T>
class Deque {
private:
    T* que;
    int maxSize;
    int currSize;
    int front;
    int back;
public:
    Deque (int n);
    ~Deque ();
    bool isEmpty ();
    bool isFull ();
    void display (); 
    void makeEmpty ();
    bool insertAtFront (T val);
    bool insertAtBack (T val);
    bool removeFromFront (T& val);
    bool removeFromBack (T& val);
};