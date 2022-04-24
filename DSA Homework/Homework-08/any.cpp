#pragma once

#include "any.h"
#include<iostream>

using namespace std;


template <typename T>
bool Stack<T>::isEmpty(){
    return top == -1 ? true : false;
}
template <typename T>
bool Stack<T>::isFull(){
    return maxSize-1 == top ? true : false;
}

template <typename T>
Stack<T>::Stack(int s){

    maxSize = s >= 0 ? s : 10;

    top = -1;
    stk = new T[maxSize];
}

template <typename T>
Stack<T>::~Stack(){
    if(stk != NULL){
        delete[] stk;
    } 
}

template <typename T>
bool Stack<T>::push(T val){
    if(isFull()){
        // cout<<"Stack is full!"<<endl;
        return false;
    } else {
        top++;
        stk[top] = val;
        return true;
    }
}

template <typename T>
bool Stack<T>::pop(T& val){
    if(isEmpty()){
        // cout<<"Stack is empty!"<<endl;
        return false;
    } else {
        val = stk[top];
        top--;
        return true;
    }
}

template <typename T>
bool Stack<T>::getTop(T& val){
    if(isEmpty()){
        // cout<<"Stack is empty!"<<endl;
        return false;
    } else {
        val = stk[top];
        return true;
    }
}

template <typename T>
void Stack<T>::print(){
    if(isEmpty()){
        cout<<"Stack is empty!"<<endl;

    } else {
        // cout<<endl;
        for(int i=0; i<=top; i++){
            cout<<stk[i]<<"\t";
        }
        cout<<endl;
    }
}