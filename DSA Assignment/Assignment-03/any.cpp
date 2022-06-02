#pragma once

#include "any.h"
#include<iostream>

using namespace std;






LinkedList::LinkedList(){
    head = NULL;
}



LinkedList::~LinkedList(){
    Node* curr;
    while(head != NULL){
        curr = head->next;
        delete head;
        head = curr;
    }
}


bool LinkedList::insert(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->next = head;
    head = temp;
    return true;
} 


void LinkedList::display(){

    Node* curr = head;
    int count=0;
    while(curr != NULL){
        count++;
        curr = curr->next;    
    }


    if(count == 0){
        cout<<"Linked list is empty!"<<endl;
    } else {
        cout<<"The list contains following "<<count<<" elements: ";

        curr = head;

        while(curr != NULL){
            cout<<curr->data<<"\t";
            curr = curr->next;    
        }
        cout<<endl;
    }

}



bool LinkedList::remove(int val){

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL && curr->data != val){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        return false;
    }

    if(prev == NULL && curr->data == val){
        head = curr->next;
    }

    if(prev != NULL){
        prev->next = curr->next;
    }

    delete curr;

    return true;
}


bool LinkedList::search(int key){

    Node* curr = head;

    while(curr != NULL){
        if(curr->data == key){
            return true;
        }
        curr = curr->next;
    }

    return false;
}


void LinkedList::sort(){

    if(!head || !head->next) return;

    Node* outerCurr = head;
    Node* innerCurr = head;
    Node* tempHead = NULL;
    Node* anotherTempHead = NULL;
    Node* prevNode = NULL;

    Node* beforeMinNode = NULL;
    Node* minNode = head;
    Node* afterMinNode = NULL;
    int min=0;

    min = innerCurr->data;

    while(innerCurr != NULL){

        if(innerCurr->data < min){
            beforeMinNode = prevNode;
            min = innerCurr->data;
            minNode = innerCurr;
        }

        prevNode = innerCurr;
        innerCurr = innerCurr->next;

    }

    if(beforeMinNode != NULL){
        beforeMinNode->next = minNode->next;
    }

    tempHead = minNode;

    // cout<<"here 1 "<<tempHead->data<<endl;

    if(head==tempHead){
        // cout<<"iamere1"<<endl;
        outerCurr = head->next;
        // cout<<outerCurr->data<<endl;;
    } else {
        // cout<<"iamere2"<<endl;
        outerCurr = head;
    }


    anotherTempHead = tempHead;
    while(outerCurr != NULL){

        min = outerCurr->data;  // 7
        minNode = outerCurr;
        beforeMinNode = NULL;
        prevNode = outerCurr;
        innerCurr = outerCurr->next; // 6

        while(innerCurr != NULL){

            if(innerCurr->data < min){
                beforeMinNode = prevNode;
                min = innerCurr->data;
                minNode = innerCurr;
            }

            prevNode = innerCurr;
            innerCurr = innerCurr->next;
        }

        if(outerCurr->next == NULL){
            minNode = outerCurr;
        }

        if(beforeMinNode != NULL){
            beforeMinNode->next = minNode->next;
        } else {
            outerCurr = outerCurr->next;
        }

        minNode->next = NULL;
        anotherTempHead->next = minNode;
        anotherTempHead = anotherTempHead->next;
        // cout<<"here 2 "<<minNode->data<<endl;
    }

    head = tempHead;
}



void LinkedList::reverse(){

    if(!head || !head->next) return;

    Node* curr = head;
    Node* nextNode = curr->next;
    Node* curr2 = head;
    Node* curr3 = NULL;
    Node* temp = NULL;

    curr = head->next;
    temp = curr;

    head->next = NULL;

    while(curr != NULL){
        curr2 = curr->next;
        curr->next = curr3;
        curr3 = curr;
        curr = curr2;
    }

    temp->next = head;

    head = curr3;
}



void LinkedList::emptyList(){
    Node* curr;
    while(head != NULL){
        curr = head->next;
        delete head;
        head = curr;
    }
}