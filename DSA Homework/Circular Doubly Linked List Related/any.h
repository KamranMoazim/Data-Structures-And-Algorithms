#pragma once

#include<iostream>

using namespace std;

template <typename T>
class CDLLD;

template <typename T>
class DNode {
private:
    T data;
    DNode* next;
    DNode* prev;
public:
    friend CDLLD<T>;
};


template <typename T>
class CDLLD {
private:
    DNode<T> head;
public:

    CDLLD();

    CDLLD(const CDLLD& list);

    CDLLD<T> operator = (const CDLLD& list);

    void display() const ;

    bool insertAtEnd(T val);

    bool insertAtStart(T val);

    bool sortedInsert(T val);

    bool sortedRemove(T val);

    bool unsortedRemove(T val);

    ~CDLLD();





    // CDLLD(){
    //     head.next = &head;
    //     head.prev = &head;
    // }

    // CDLLD(const CDLLD& list){

    //     head.next = &head;
    //     head.prev = &head;

    //     DNode<T>* curr = list.head.next;

    //     while(curr != &list.head){

    //         DNode<T>* temp = new DNode<T>();
    //         temp->data = curr->data;

    //         temp->prev = head.prev;
    //         temp->next = &head;
    //         head.prev->next = temp;
    //         head.prev = temp;

    //         curr = curr->next;
    //     }
    // }

    // CDLLD<T> operator = (const CDLLD& list){

    //     if(&list == this){
    //         return *this;
    //     }
        
    //     DNode<T>* curr = head.next;
    //     while(curr != &head){
    //         curr = curr->next;
    //         delete curr->prev;
    //     }
    //     head.next = &head;
    //     head.prev = &head;


    //     curr = list.head.next;
    //     while(curr != &list.head){
    //         DNode<T>* temp = new DNode<T>();
    //         temp->data = curr->data;
    //         temp->prev = head.prev;
    //         temp->next = &head;
    //         head.prev->next = temp;
    //         head.prev = temp;
    //         curr = curr->next;
    //     }

    //     return *this;
    // }

    // void display() const {
    //     DNode<T>* curr = head.next;
    //     while(curr != &head){
    //         cout<<curr->data<<" ";
    //         curr = curr->next;
    //     }
    //     cout<<endl;
    // }

    // bool insertAtEnd(T val){
    //     DNode<T>* temp = new DNode<T>();
    //     temp->data = val;

    //     temp->prev = head.prev;
    //     temp->next = &head;
    //     head.prev->next = temp;
    //     head.prev = temp;

    //     return true;
    // }

    // bool insertAtStart(T val){
    //     DNode<T>* temp = new DNode<T>();
    //     temp->data = val;

    //     temp->next = head.next;
    //     temp->prev = &head;
    //     head.next = temp;
    //     temp->next->prev = temp;

    //     return true;
    // }

    // bool sortedInsert(T val){

    //     DNode<T>* temp = new DNode<T>();
    //     temp->data = val;

    //     DNode<T>* curr = head.next;

    //     while(curr != &head && curr->data < val){
    //         curr = curr->next;
    //     }

    //     temp->next = curr;
    //     temp->prev = curr->prev;

    //     temp->prev->next = temp;
    //     curr->prev = temp;

    //     return true;
    // }

    // bool sortedRemove(T val){

    //     DNode<T>* curr = head.next;

    //     while(curr != &head && curr->data < val){
    //         curr = curr->next;
    //     }

    //     if(curr == &head){
    //         return false;
    //     }

    //     if(curr->data == val){
    //         curr->next->prev = curr->prev;
    //         curr->prev->next = curr->next;
    //         return true;
    //     }

    //     return false;
    // }

    // bool unsortedRemove(T val){

    //     DNode<T>* curr = head.next;

    //     while(curr != &head && curr->data != val){
    //         curr = curr->next;
    //     }

    //     if(curr == &head){
    //         return false;
    //     }

    //     if(curr->data == val){
    //         curr->next->prev = curr->prev;
    //         curr->prev->next = curr->next;
    //         return true;
    //     }

    //     return false;
    // }

    // ~CDLLD(){
    //     DNode<T>* curr = head.next;
    //     while(curr != &head){
    //         curr = curr->next;
    //         // cout<<"*** "<<curr->prev->data<<"\t";
    //         delete curr->prev;
    //     }
    //     // cout<<endl;
    //     head.next = &head;
    //     head.prev = &head;
    // }

};

