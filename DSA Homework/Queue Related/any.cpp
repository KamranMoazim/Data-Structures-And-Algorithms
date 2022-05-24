#pragma once

#include "any.h"
#include<iostream>

using namespace std;

// ************ QUEUE

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






















// ************ DEQUE


template <typename T>
Deque<T>::Deque (int n) {

    maxSize = n > 0 ? n : 10;
    que = new T[maxSize];
    front = 0;
    back = 0;
    currSize = 0;
}

template <typename T>
Deque<T>::~Deque () {
    
    if(que != NULL){
        delete[] que;
        que = NULL;
    }
}

template <typename T>
bool Deque<T>::isEmpty () {
    return currSize == 0 ? true : false;
}

template <typename T>
bool Deque<T>::isFull () {
    return maxSize == currSize ? true : false;
}

template <typename T>
void Deque<T>::display () {
    
    if(isEmpty()){
        cout<<"Deque is empty!"<<endl;
    } else {
        cout<<"Contents of Deque are : ";
        int j=front;
        for(int i=0; i<currSize; i++){
            cout<<que[j]<<"\t";
            j = ((j+1)%(maxSize));
        }
        cout<<endl;
    }
}

template <typename T>
void Deque<T>::makeEmpty () {
    
    front = 0;
    back = 0;
    currSize = 0;
}


template <typename T>
bool Deque<T>::insertAtFront (T val) {
    
    if(isFull()){
        // cout<<"Deque is full!"<<endl;
        return false;
    } else {
        currSize++;
        front = front-1 < 0 ? (maxSize-1) : (front-1);
        que[front] = val;
        return true;
    }
}

template <typename T>
bool Deque<T>::insertAtBack (T val) {
    
    if(isFull()){
        // cout<<"Deque is full!"<<endl;
        return false;
    } else {
        currSize++;
        que[back] = val;
        back = ((back+1)%(maxSize));
        return true;
    }
}

template <typename T>
bool Deque<T>::removeFromFront (T& val) {
    
    if(isEmpty()){
        // cout<<"Deque is empty!"<<endl;
        return false;
    } else {
        currSize--;
        val = que[front];
        front = ((front+1)%(maxSize));
        return true;
    }
}

template <typename T>
bool Deque<T>::removeFromBack (T& val) {
    
    if(isEmpty()){
        // cout<<"Deque is empty!"<<endl;
        return false;
    } else {
        currSize--;
        back = back-1 < 0 ? (maxSize-1) : (back-1) ;
        val = que[back];
        return true;
    }
}