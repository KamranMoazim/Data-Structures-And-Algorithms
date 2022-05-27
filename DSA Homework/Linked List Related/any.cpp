#pragma once

#include "any.h"
#include<iostream>

using namespace std;



template <typename T>
LinkedList<T>::LinkedList(){
    head = NULL;
}



template <typename T>
void LinkedList<T>::displayList(){

    Node<T>* curr = head;

    while(curr != NULL){
        cout<<curr->data<<"\t";
        curr = curr->next;    
    }
    cout<<endl;
}




template <typename T>
bool LinkedList<T>::insertAtStart(T val){
    Node<T>* temp = new Node<T>;
    temp->data = val;
    temp->next = head;
    head = temp;
    return true;
}



template <typename T>
bool LinkedList<T>::insertAtEnd(T val){

    Node<T>* temp = new Node<T>;
    temp->data = val;
    temp->next = NULL;

    if(head == NULL){
        insertAtStart(val);
        return true;
    }

    Node<T>* curr = head;

    while(curr->next != NULL){
        curr = curr->next;    
    }

    curr->next = temp;
    
    return true;
}


// HomeWork 1
template <typename T>
void LinkedList<T>::displayReverseListUsingLoop(){

    int nodeCount = 0;
    Node<T>* curr = head;

    while(curr != NULL){
        nodeCount++;
        curr = curr->next;    
    }

    for(int i=0; i<nodeCount; i++){

        curr = head;
        int j = nodeCount-(i+1);
        while(j > 0){
            curr = curr->next;
            j--;
        }
        cout<<curr->data<<"\t";
        
    }

    cout<<endl;
}



// HomeWork 2
template <typename T>
bool LinkedList<T>::search(T key){

    Node<T>* curr = head;

    while(curr != NULL){
        if(curr->data == key){
            return true;
        }
        curr = curr->next;
    }

    return false;
}



// HomeWork 3
template <typename T>
T LinkedList<T>::findMax(){

    // * make sure if there is no node?????
    // ! make sure if there is no node?????
    // ? make sure if there is no node?????

    T max = head->data;

    Node<T>* curr = head->next;

    while(curr != NULL){
        if(curr->data > max){
            max = curr->data;
        }
        curr = curr->next;    
    }

    return max;
}


// HomeWork 5 
template <typename T>
LinkedList<T>::~LinkedList(){
    Node<T>* curr;
    while(head != NULL){
        curr = head->next;
        delete head;
        head = curr;
    }
}
