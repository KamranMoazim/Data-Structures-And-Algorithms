// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon



#pragma once

#include "class.h"
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


// ********************************** TASKs 1.1

bool LinkedList::insert(int val){
    // here we are inserting value at the start of LIST
    Node* temp = new Node;
    temp->data = val;
    temp->next = head;
    head = temp;
    return true;
} 

void LinkedList::display(){

    // we are counting number of nodes becuase we need to tell how many nodes are threr before showing content of LIST
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
            cout<<curr->data<<" ";
            curr = curr->next;    
        }
        cout<<endl;
    }

}

bool LinkedList::remove(int val){

    Node* curr = head;
    Node* prev = NULL;

    // looping till we found the value OR reached end;
    while(curr != NULL && curr->data != val){
        prev = curr;
        curr = curr->next;
    }

    // whether there is no node or we have reached end
    if(curr == NULL){
        return false;
    }

    // first node contain that particular value which we were looking for
    if(prev == NULL && curr->data == val){
        head = curr->next;
    }

    // value was found somewhere in the middle of LIST
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
            // as soon as we found that value, we will return
            return true;
        }
        curr = curr->next;
    }

    return false;
}


// ********************************** TASKs 1.2
void LinkedList::sort(){

    if(!head || !head->next) return;    

    Node* outerCurr = head;
    Node* innerCurr = NULL;
    Node* tempHead = NULL;
    Node* startOfMins = NULL;
    Node* prevNode = NULL;

    Node* beforeMinNode = NULL;
    Node* minNode = NULL;
    Node* afterMinNode = NULL;
    int min=0;


    while(outerCurr != NULL){

        prevNode = NULL;

        beforeMinNode = NULL;
        minNode = outerCurr;
        innerCurr = outerCurr;
        min = minNode->data;
        afterMinNode = minNode->next;


        while(innerCurr != NULL){

            if(innerCurr->data < min){
                beforeMinNode = prevNode;
                min = innerCurr->data;
                minNode = innerCurr;
                afterMinNode = innerCurr->next;
            }

            prevNode = innerCurr;
            innerCurr = innerCurr->next;
        }

        if(beforeMinNode == NULL){  // min node is found at start

            outerCurr = outerCurr->next;

        } else if(beforeMinNode != NULL){  // min node is found in middle or at end

            beforeMinNode->next = afterMinNode;

        }

        if(startOfMins == NULL){
            startOfMins = minNode;
            tempHead = startOfMins;
        } else {
            startOfMins->next = minNode;
            startOfMins = startOfMins->next;
        }
    }
    
    head = tempHead;
    cout<<"The list has been sorted!"<<endl;
}


void LinkedList::reverse(){

    if(!head || !head->next){
        cout<<"The list has been reversed!"<<endl;
        return;
    }

    Node* curr = NULL;
    Node* curr2 = NULL;
    Node* curr3 = NULL;
    Node* temp = NULL;

    // catching first node
    temp = head;
    curr = head->next;
    head->next = NULL;
    curr3 = temp;

    // reversing remaining nodes
    while(curr != NULL){
        curr2 = curr->next;
        curr->next = curr3;
        curr3 = curr;
        curr = curr2;
    }

    head = curr3;
    cout<<"The list has been reversed!"<<endl;
}



void LinkedList::emptyList(){
    Node* curr;
    while(head != NULL){
        curr = head->next;
        delete head;
        head = curr;
    }
}