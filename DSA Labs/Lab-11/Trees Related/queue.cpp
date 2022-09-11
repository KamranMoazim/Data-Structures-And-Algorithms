#pragma once

#include <iostream>

using namespace std;




// ************ LinkedListQueue

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
public:
    bool isEmpty();
    LinkedListQueue();
    LinkedListQueue(const LinkedListQueue& );
    LinkedListQueue operator= (const LinkedListQueue& );
    ~LinkedListQueue();
    bool enqueue(T);
    bool dequeue(T&);
    void print();
};













template <typename T>
bool LinkedListQueue<T>::isEmpty(){
    return front == NULL ? true : false;
}


template <typename T>
LinkedListQueue<T>::LinkedListQueue(){

    front = NULL;
    back = NULL;
}



template <typename T>
LinkedListQueue<T>::LinkedListQueue(const LinkedListQueue& queue){

    if(queue.front == NULL){
        front = NULL;
        back = NULL;
    } else if(queue.front == queue.back) {
        Node<T>* temp = new Node<T>;
        temp->data = queue.front->data;
        temp->next = NULL;
        front = temp;
        back = temp;
    } else {

        Node<T>* temp = new Node<T>;
        temp->data = queue.front->data;
        temp->next = NULL;
        front = temp;
        back = temp;

        Node<T>* curr = queue.front->next;
        while(curr != NULL){

            Node<T>* temp = new Node<T>;
            temp->data = curr->data;
            temp->next = NULL;
            back->next = temp;
            back = back->next;

            curr = curr->next;
        }
    }

}




template <typename T>
LinkedListQueue<T> LinkedListQueue<T>::operator = (const LinkedListQueue& queue){

    if(this == &queue){
        return *this;
    }

    Node<T> curr = front;
    while(curr != NULL){
        curr = front->next;
        delete front;
        front = curr;
    }
    back = NULL;

    if(queue.front == NULL){
        front = NULL;
        back = NULL;
    } else if(queue.front == queue.back) {
        Node<T>* temp = new Node<T>;
        temp->data = queue.front->data;
        temp->next = NULL;
        front = temp;
        back = temp;
    } else {

        Node<T>* temp = new Node<T>;
        temp->data = queue.front->data;
        temp->next = NULL;
        front = temp;
        back = temp;

        Node<T>* curr = queue.front->next;
        while(curr != NULL){

            Node<T>* temp = new Node<T>;
            temp->data = curr->data;
            temp->next = NULL;
            back->next = temp;
            back = back->next;

            curr = curr->next;
        }
    }

    return *this;
    
}


template <typename T>
LinkedListQueue<T>::~LinkedListQueue(){
    Node<T>* curr = front;
    while(curr != NULL){
        curr = front->next;
        delete front;
        front = curr;
    }
    back = NULL;
}

template <typename T>
bool LinkedListQueue<T>::enqueue(T val){

    Node<T>* temp = new Node<T>;
    temp->data = val;
    temp->next = NULL;

    if(back == NULL){
        back = temp;
        front = temp;
    } else {
        back->next = temp;
        back = back->next;
    }

    return true;
}

template <typename T>
bool LinkedListQueue<T>::dequeue(T& val){
    if(isEmpty()){
        cout<<"Queue is empty!"<<endl;
        return false;
    } else {
        
        val = front->data;
        Node<T>* curr = front;
        front = front->next;
        if(front == NULL){
            back = NULL;
        }
        delete curr;
        
        return true;
    }
}



template <typename T>
void LinkedListQueue<T>::print(){
    if(isEmpty()){
        cout<<"Queue is empty!"<<endl;
    } else {
        Node<T> curr = front;
        while(curr != NULL){
            cout<<curr->data<<"\t";
            curr = front->next;
        }
    }
}


