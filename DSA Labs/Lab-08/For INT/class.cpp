#pragma once

#include "class.h"
#include<iostream>

using namespace std;


// **************************** TASK 0


SinglyLinkedList::SinglyLinkedList(){
    head = NULL;
}


SinglyLinkedList::~SinglyLinkedList(){
    Node* curr;
    while(head != NULL){
        curr = head->next;
        delete head;
        head = curr;
    }
}


bool SinglyLinkedList::insertAtStart(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->next = head;
    head = temp;
    return true;
}


void SinglyLinkedList::displayList(){

    Node* curr = head;

    while(curr != NULL){
        cout<<curr->data<<"\t";
        curr = curr->next;
    }
    cout<<endl;
}


int SinglyLinkedList::countNodes(){
    Node* curr = head;
    int count = 0;

    while(curr != NULL){
        count++;
        curr = curr->next;    
    }

    return count;
}



// **************************** TASK 1

bool SinglyLinkedList::removeKthNode(int k, int& val){
    
    if(k <= countNodes()){

        Node* curr = head;
        Node* prev = NULL;

        if(k==1){
            val = curr->data;
            head = curr->next;
            delete curr;
            curr = NULL;
            return true;
        }

        int count = 1;
        

        while(count < k){
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        val = curr->data;
        delete curr;
        curr = NULL;

        return true;

    } else {
        return false;
    }

}




// **************************** TASK 2

void SinglyLinkedList::combine(SinglyLinkedList& list1, SinglyLinkedList& list2){

    if (list1.head == NULL && list2.head == NULL){

        head = NULL;

    } else if (list1.head != NULL && list2.head == NULL){

        head = list1.head;
        list1.head = NULL;

    } else if (list1.head == NULL && list2.head != NULL){

        head = list2.head;
        list2.head = NULL;

    } else {

        head = list1.head;
        Node* curr = head;

        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = list2.head;
        list1.head = NULL;
        list2.head = NULL;
    }

}





// **************************** TASK 3

void SinglyLinkedList::shuffleMerge(SinglyLinkedList& list1, SinglyLinkedList& list2){

    if (list1.head == NULL && list2.head == NULL){

        head = NULL;

    } else {

        Node* curr1 = list1.head;
        Node* curr2 = list2.head;
        Node* curr3 = NULL;

        head = curr1;
        curr1 = curr1->next;

        head->next = curr2;
        curr2 = curr2->next;

        curr3 = head->next;

        while(curr1 != NULL && curr2 != NULL){

            curr3->next = curr1;
            curr1 = curr1->next;
            curr3 = curr3->next;

            curr3->next = curr2;
            curr2 = curr2->next;
            curr3 = curr3->next;

        }

        list1.head = NULL;
        list2.head = NULL;
    }
}





// **************************** TASK 4

bool SinglyLinkedList::removeLastNode(int& val){

    if(head == NULL){
        return false;
    }

    if(head->next == NULL){

        Node* curr = head;
        head = head->next;
        val = curr->data;
        delete curr;
        curr = NULL;

        return true;
    }

    Node* curr = head;
    Node* secondLastNode;

    while(curr->next->next != NULL){
        curr = curr->next;
    }
    secondLastNode = curr;
    curr = curr->next;

    val = curr->data;
    delete curr;
    secondLastNode->next = NULL;
    
    return true;
}



bool SinglyLinkedList::removeSecondLastNode(int& val){

    if(head == NULL || head->next == NULL){
        return false;
    }

    if(head->next->next == NULL){

        Node* curr = head;
        head = head->next;
        val = curr->data;
        delete curr;
        curr = NULL;

        return true;
    }

    Node* curr = head;
    Node* beforeSecondLastNode;
    Node* temp;

    while(curr->next->next->next != NULL){
        curr = curr->next;
    }
    beforeSecondLastNode = curr;
    curr = curr->next;
    temp = curr->next;

    val = curr->data;
    delete curr;
    curr = NULL;

    beforeSecondLastNode->next = temp;
    
    return true;

}






// **************************** TASK 5

int SinglyLinkedList::findMin(){

    if(head == NULL){
        return -999;
    }

    int min = head->data;

    Node* curr = head;

    while(curr != NULL){
        if(curr->data < min){
            min = curr->data;
        }
        curr = curr->next;    
    }

    return min;

}


int SinglyLinkedList::findMax(){

    if(head == NULL){
        return 999;
    }

    int max = head->data;

    Node* curr = head;

    while(curr != NULL){
        if(curr->data > max){
            max = curr->data;
        }
        curr = curr->next;    
    }

    return max;
}






// **************************** TASK 6

int SinglyLinkedList::findMinPrivate(Node* curr, int minVal){

    if(curr == NULL){
        return minVal;
    } else {
        if (curr->data < minVal) {
            return findMinPrivate(curr->next, curr->data);
        } else {
            return findMinPrivate(curr->next, minVal);
        }
    }

}


int SinglyLinkedList::findMinRecursively(){

    if(head == NULL){
        return -999;
    }

    return findMinPrivate(head->next, head->data);
}








// **************************** TASK 7

int SinglyLinkedList::countEvensPrivate(Node* curr, int count){

    if(curr == NULL){
        return count;
    } else {
        count = curr->data%2 == 0 ? count+1 : count;
        return countEvensPrivate(curr->next, count);
    }

}



int SinglyLinkedList::countEvens(){
    
    if(head == NULL){
        return 0;
    }

    return countEvensPrivate(head, 0);
}
