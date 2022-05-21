#pragma once

#include "any.h"
#include<iostream>

using namespace std;


template <typename T>
bool Queue<T>::isEmpty(){
    return noOfElements == 0 ? true : false;
}
template <typename T>
bool Queue<T>::isFull(){
    return maxSize == noOfElements ? true : false;
}

template <typename T>
Queue<T>::Queue(int s){

    maxSize = s > 0 ? s : 10;
    noOfElements = 0;
    front = 0;
    rear = 0;
    que = new T[maxSize];
}

template <typename T>
Queue<T>::~Queue(){
    if(que != NULL){
        delete[] que;
    } 
}

template <typename T>
bool Queue<T>::enqueue(T val){
    if(isFull()){
        // cout<<"Queue is full!"<<endl;
        return false;
    } else {
        noOfElements++;
        que[rear] = val;
        rear = ((rear+1)%(maxSize));
        return true;
    }
}

template <typename T>
bool Queue<T>::dequeue(T& val){
    if(isEmpty()){
        // cout<<"Queue is empty!"<<endl;
        return false;
    } else {
        noOfElements--;
        val = que[front];
        front = ((front+1)%(maxSize));
        return true;
    }
}

template <typename T>
bool Queue<T>::peek(T& val){
    if(isEmpty()){
        // cout<<"Queue is empty!"<<endl;
        return false;
    } else {
        val = que[front];
        return true;
    }
}

template <typename T>
void Queue<T>::print(){
    if(isEmpty()){
        cout<<"Queue is empty!"<<endl;
    } else {
        int j=front;
        // cout<<"Elements : "<<noOfElements<<endl;
        for(int i=0; i<noOfElements; i++){
            cout<<que[j]<<"\t";
            j = ((j+1)%(maxSize));
        }
        cout<<endl;
    }
}