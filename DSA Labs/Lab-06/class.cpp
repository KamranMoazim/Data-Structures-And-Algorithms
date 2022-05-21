// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon

#pragma once

#include "class.h"
#include<iostream>
#include <cstring>

using namespace std;



Deque::Deque (int n) { // Constructor to create a Deque which can contain up to n integers.

    maxSize = n > 0 ? n : 10;
    que = new int[maxSize];
    front = 0;
    back = 0;
    currSize = 0;
}

Deque::~Deque () { // Destructor to destroy the Deque.

    if(que != NULL){
        delete[] que;
        que = NULL;
    }
}

bool Deque::isEmpty () { // returns true if the Deque is empty, and false otherwise.

    return currSize == 0 ? true : false;
}

bool Deque::isFull () { // returns true if the Deque is full, and false otherwise.

    return maxSize == currSize ? true : false;
}


void Deque::display () { // to display the elements of Deque from front to back.

    if(isEmpty()){
        cout<<"Queue is empty!"<<endl;
    } else {
        cout<<"Contents of Queue are : ";
        int j=front;
        for(int i=0; i<currSize; i++){
            cout<<que[j]<<"\t";
            j = ((j+1)%(maxSize));
        }
        cout<<endl;
    }
}


void Deque::makeEmpty () { // to make the Deque empty.

    front = 0;
    back = 0;
    currSize = 0;
}



bool Deque::insertAtFront (int val) { // to insert val at the front of the queue.

    if(isFull()){
        // cout<<"Queue is full!"<<endl;
        return false;
    } else {
        currSize++;
        front = front-1 < 0 ? (maxSize-1) : (front-1);
        que[front] = val;
        return true;
    }
}


bool Deque::insertAtBack (int val) { // to insert val at the back of the queue.

    if(isFull()){
        // cout<<"Queue is full!"<<endl;
        return false;
    } else {
        currSize++;
        que[back] = val;
        back = ((back+1)%(maxSize));
        return true;
    }
}


bool Deque::removeFromFront (int& val) { // to remove an integer from the front of the queue and store it in the variable val.

    if(isEmpty()){
        // cout<<"Queue is empty!"<<endl;
        return false;
    } else {
        currSize--;
        val = que[front];
        front = ((front+1)%(maxSize));
        return true;
    }
}

bool Deque::removeFromBack (int& val) { // to remove an integer from the back of the queue and store it in the variable val.

    if(isEmpty()){
        // cout<<"Queue is empty!"<<endl;
        return false;
    } else {
        currSize--;
        back = back-1 < 0 ? (maxSize-1) : (back-1) ;
        val = que[back];
        return true;
    }
}
