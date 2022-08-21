#pragma once

#include "any.h"
#include<iostream>

using namespace std;









// !!!
// ???
// ***
//TODO 

// template <typename T>
// void SinglyLinkedList<T>::unionLists(SinglyLinkedList<T>& list1, SinglyLinkedList<T>& list2){
// }





template <typename T>
CDLLD<T>::CDLLD(){
    head.next = &head;
    head.prev = &head;
}


template <typename T>
CDLLD<T>::CDLLD(const CDLLD& list){

    head.next = &head;
    head.prev = &head;

    DNode<T>* curr = list.head.next;

    while(curr != &list.head){

        DNode<T>* temp = new DNode<T>();
        temp->data = curr->data;

        temp->prev = head.prev;
        temp->next = &head;
        head.prev->next = temp;
        head.prev = temp;

        curr = curr->next;
    }
}


template <typename T>
CDLLD<T> CDLLD<T>::operator = (const CDLLD& list){

    if(&list != this){
        
        DNode<T>* curr = head.next;
        while(curr != &head){
            curr = curr->next;
            delete curr->prev;
        }
        head.next = &head;
        head.prev = &head;


        curr = list.head.next;
        while(curr != &list.head){
            DNode<T>* temp = new DNode<T>();
            temp->data = curr->data;
            temp->prev = head.prev;
            temp->next = &head;
            head.prev->next = temp;
            head.prev = temp;
            curr = curr->next;
        }
        
    }
    

    return *this;
}


template <typename T>
void CDLLD<T>::display() const {
    DNode<T>* curr = head.next;
    while(curr != &head){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}


template <typename T>
bool CDLLD<T>::insertAtEnd(T val){
    DNode<T>* temp = new DNode<T>();
    temp->data = val;

    temp->prev = head.prev;
    temp->next = &head;
    head.prev->next = temp;
    head.prev = temp;

    return true;
}


template <typename T>
bool CDLLD<T>::insertAtStart(T val){
    DNode<T>* temp = new DNode<T>();
    temp->data = val;

    temp->next = head.next;
    temp->prev = &head;
    head.next = temp;
    temp->next->prev = temp;

    return true;
}


template <typename T>
bool CDLLD<T>::sortedInsert(T val){

    DNode<T>* temp = new DNode<T>();
    temp->data = val;

    DNode<T>* curr = head.next;

    while(curr != &head && curr->data < val){
        curr = curr->next;
    }

    temp->next = curr;
    temp->prev = curr->prev;

    temp->prev->next = temp;
    curr->prev = temp;

    return true;
}


template <typename T>
bool CDLLD<T>::sortedRemove(T val){

    DNode<T>* curr = head.next;

    while(curr != &head && curr->data < val){
        curr = curr->next;
    }

    if(curr == &head){
        return false;
    }

    if(curr->data == val){
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        return true;
    }

    return false;
}


template <typename T>
bool CDLLD<T>::unsortedRemove(T val){

    DNode<T>* curr = head.next;

    while(curr != &head && curr->data != val){
        curr = curr->next;
    }

    if(curr == &head){
        return false;
    }

    if(curr->data == val){
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        return true;
    }

    return false;
}


template <typename T>
CDLLD<T>::~CDLLD(){
    DNode<T>* curr = head.next;
    while(curr != &head){
        curr = curr->next;
        cout<<"*** "<<curr->prev->data<<"\t";
        delete curr->prev;
    }
    cout<<endl;
    head.next = &head;
    head.prev = &head;
}


