// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon


#pragma once

#include<iostream>

using namespace std;



class Deque {
private:
    int* que;
    int maxSize;
    int currSize;
    int front;
    int back;
public:
    Deque (int n); // Constructor to create a Deque which can contain up to n integers.
    ~Deque (); // Destructor to destroy the Deque.
    bool isEmpty (); // returns true if the Deque is empty, and false otherwise.
    bool isFull (); // returns true if the Deque is full, and false otherwise.
    void display (); // to display the elements of Deque from front to back.
    void makeEmpty (); // to make the Deque empty.
    bool insertAtFront (int val); // to insert val at the front of the queue.
    bool insertAtBack (int val); // to insert val at the back of the queue.
    bool removeFromFront (int& val); // to remove an integer from the front of the queue and store it in the variable val.
    bool removeFromBack (int& val); // to remove an integer from the back of the queue and store it in the variable val.
};
