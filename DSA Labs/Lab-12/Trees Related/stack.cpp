

#pragma once

#include <iostream>

using namespace std;










template <typename T>
class LinkedListStack;

template <typename T>
class Node {
private:
    T data;
    Node* next;
public:
    friend LinkedListStack<T>;
};


template <typename T>
class LinkedListStack {
private:
    Node<T>* top;
    bool isEmpty();
public:
    LinkedListStack();
    ~LinkedListStack();
    bool push(T);
    bool pop(T&);
    bool getTop(T&);
    void print();
};







// *************************** LINKED-LIST STACK

template <typename T>
bool LinkedListStack<T>::isEmpty(){
    return top == NULL ? true : false;
}


template <typename T>
LinkedListStack<T>::LinkedListStack(){
    top = NULL;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack(){
    Node<T>* curr;
    while(top != NULL){
        curr = top->next;
        delete top;
        top = curr;
    }
}

template <typename T>
bool LinkedListStack<T>::push(T val){   // it is like insertAtStart in LinkedList
    Node<T>* temp = new Node<T>;
    temp->data = val;
    temp->next = top;
    top = temp;
    return true;
}

template <typename T>
bool LinkedListStack<T>::pop(T& val){   // it is like removeFromStart in LinkedList
    if(isEmpty()){
        cout<<"Stack is empty!"<<endl;
        return false;
    } else {
        Node<T>* temp;
        val = top->data;
        temp = top->next;
        delete top;
        top = temp;
        return true;
    }
}

template <typename T>
bool LinkedListStack<T>::getTop(T& val){
    if(isEmpty()){
        cout<<"Stack is empty!"<<endl;
        return false;
    } else {
        val = top->data;
        return true;
    }
}

template <typename T>
void LinkedListStack<T>::print(){
    if(isEmpty()){
        cout<<"Stack is empty!"<<endl;
    } else {
        Node<T>* curr = top;

        while(curr != NULL){
            cout<<curr->data<<"\t";
            curr = curr->next;    
        }
        cout<<endl;
    }
}


