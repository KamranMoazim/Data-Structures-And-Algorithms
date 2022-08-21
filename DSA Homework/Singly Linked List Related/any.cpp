#pragma once

#include "any.h"
#include<iostream>

using namespace std;









// !!!
// ???
// ***
//TODO 

template <typename T>
void SinglyLinkedList<T>::unionLists(SinglyLinkedList<T>& list1, SinglyLinkedList<T>& list2){

    Node<T>* temp;
    Node<T>* tempForNewNode;

    Node<T>* curr;
    while(head != NULL){
        curr = head->next;
        delete head;
        head = curr;
    }

    if(list1.head==NULL && list2.head==NULL){

        head = NULL;

    } else if(list1.head!=NULL && list2.head==NULL){

        curr = list1.head;
        head = new Node<T>;
        head->data = curr->data;
        head->next = NULL;
        curr = curr->next;
        temp = head;

        while(curr != NULL){
            tempForNewNode = new Node<T>;
            tempForNewNode->data = curr->data;
            tempForNewNode->next = NULL;
            temp->next = tempForNewNode;
            temp = temp->next;
            curr = curr->next;
        }
        temp->next = NULL;

    } else if(list1.head==NULL && list2.head!=NULL){

        curr = list2.head;
        head = new Node<T>;
        head->data = curr->data;
        head->next = NULL;
        curr = curr->next;
        temp = head;

        while(curr != NULL){
            tempForNewNode = new Node<T>;
            tempForNewNode->data = curr->data;
            tempForNewNode->next = NULL;
            temp->next = tempForNewNode;
            temp = temp->next;
            curr = curr->next;
        }
        temp->next = NULL;

    } else {

        curr = list1.head;
        head = new Node<T>;
        head->data = curr->data;
        head->next = NULL;
        curr = curr->next;
        temp = head;

        while(curr != NULL){
            tempForNewNode = new Node<T>;
            tempForNewNode->data = curr->data;
            tempForNewNode->next = NULL;
            temp->next = tempForNewNode;
            temp = temp->next;
            curr = curr->next;
        }
        temp->next = NULL;

        curr = head;
        Node<T>* curr2 = list2.head;
        bool found = false;

        while(curr2 != NULL){

            while(curr != NULL){

                if(curr->data == curr2->data){
                    found = true;
                    break;
                }

                curr = curr->next;
            }

            if(!found){
                tempForNewNode = new Node<T>;
                tempForNewNode->data = curr2->data;
                tempForNewNode->next = NULL;
                temp->next = tempForNewNode;
                temp = temp->next;
            }

            curr2 = curr2->next;
            curr = head;
            found = false;
        }

    }
}

template <typename T>
void SinglyLinkedList<T>::deleteAlternateNodes(){
    if(head==NULL || head->next==NULL){
        return;
    } else {
        Node<T>* curr = head;
        Node<T>* deletableNode = NULL;
        Node<T>* prevNode = NULL;

        while(curr != NULL && curr->next != NULL){
            prevNode = curr;
            deletableNode = curr->next;
            curr = curr->next->next;
            delete deletableNode;
            prevNode->next = curr;
        }

    }
}

template <typename T>
void SinglyLinkedList<T>::splitLists(SinglyLinkedList<T>& list1, SinglyLinkedList<T>& list2){

    int nodes = countNodes();

    if(nodes == 0){
        list1.head = NULL;
        list2.head = NULL;
        return;
    }
    // 1 2 3 4 5 6

    int count = 1;
    list1.head = head;

    Node<T>* curr = head;;
    while(count <= nodes/2){
        curr = curr->next;
        count++;
    }

    list2.head = curr->next;
    curr->next = NULL;

    head = NULL;

}


template <typename T>
void SinglyLinkedList<T>::removeDuplicateNodes(){

    if(!head || !head->next) return;

    Node<T>* lookingFor = head;
    Node<T>* prevOfIterator = head;
    Node<T>* iterator = head->next;

    while(lookingFor != NULL){

        while(iterator != NULL){
            if(iterator!=NULL && lookingFor->data == iterator->data){
                prevOfIterator->next = iterator->next;
                delete iterator;
                iterator = prevOfIterator->next;
                continue;
            }

            if(iterator != NULL){
                prevOfIterator = iterator;
                iterator = iterator->next;
            }
        }

        lookingFor = lookingFor->next;
        prevOfIterator = lookingFor;
        if(lookingFor != NULL){
            iterator = lookingFor->next;
        }

    }
}

template <typename T>
void SinglyLinkedList<T>::removeAllOccurences(T val){
    Node<T>* temp = head;

    while(temp != NULL){

        if(temp->data == val){
            Node<T>* temp2 = temp->next;
            unsortedRemove(val);
            temp = temp2;
            continue;
        }

        temp = temp->next;
    }
}


template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(){
    head = NULL;
}


template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& comingList){

    if(comingList.head == NULL){
        head = NULL;
    } else {
        head = new Node<T>;
        head->data = comingList.head->data;
        head->next = NULL;
    
        Node<T>* p1 = comingList.head->next;
        Node<T>* p2 = head;

        while(p1 != NULL){
            Node<T>* temp = new Node<T>;
            temp->data = p1->data;
            temp->next = NULL;
            p2->next = temp;
            p2 = p2->next;
            p1 = p1->next;
        }

    }
}


template <typename T>
SinglyLinkedList<T> SinglyLinkedList<T>::operator = (const SinglyLinkedList<T>& comingList){

    if(this == &comingList){
        return *this;
    }

    if(head != NULL){
        Node<T>* curr;
        while(head != NULL){
            curr = head->next;
            delete head;
            head = curr;
        }
    }

    if(comingList.head == NULL){
        head = NULL;
    } else {
        head = new Node<T>;
        head->data = comingList.head->data;
        head->next = NULL;
    
        Node<T>* p1 = comingList.head->next;
        Node<T>* p2 = head;

        while(p1 != NULL){
            Node<T>* temp = new Node<T>;
            temp->data = p1->data;
            temp->next = NULL;
            p2->next = temp;
            p2 = p2->next;
            p1 = p1->next;
        }
    }

    return *this;
}



template <typename T>
void SinglyLinkedList<T>::displayList(){

    Node<T>* curr = head;

    while(curr != NULL){
        cout<<curr->data<<"\t";
        curr = curr->next;    
    }
    cout<<endl;
}




template <typename T>
int SinglyLinkedList<T>::countNodes(){
    Node<T>* curr = head;
    int count = 0;

    while(curr != NULL){
        count++;
        curr = curr->next;    
    }

    return count;
}



template <typename T>
bool SinglyLinkedList<T>::removeKthNode(int k, T& val){
    
    if(k <= countNodes()){

        Node<T>* curr = head;
        Node<T>* prev = NULL;

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



template <typename T>
void SinglyLinkedList<T>::combine(SinglyLinkedList& list1, SinglyLinkedList& list2){

    if (list1.head == NULL && list2.head == NULL){

        head = NULL;

    } else if (list1.head == NULL && list2.head != NULL){

        head = list1.head;

    } else if (list1.head != NULL && list2.head == NULL){

        head = list2.head;

    } else {

        head = list1.head;
        Node<T>* curr = head;

        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = list2.head;
    }

}



template <typename T>
void SinglyLinkedList<T>::shuffleMerge(SinglyLinkedList& list1, SinglyLinkedList& list2){

    if (list1.head == NULL && list2.head == NULL){

        head = NULL;

    } else {

        Node<T>* curr1 = list1.head;
        Node<T>* curr2 = list2.head;
        Node<T>* curr3 = NULL;

        head = curr1;
        curr1 = curr1->next;

        head->next = curr2;
        curr2 = curr2->next;

        curr3 = head->next;

        while(curr1 == NULL && curr2 == NULL){

            curr3->next = curr1;
            curr1 = curr1->next;
            curr3 = curr3->next;

            curr3->next = curr2;
            curr2 = curr2->next;
            curr3 = curr3->next;

        }
    }
}




template <typename T>
bool SinglyLinkedList<T>::insertAtStart(T val){
    Node<T>* temp = new Node<T>;
    temp->data = val;
    temp->next = head;
    head = temp;
    return true;
}




template <typename T>
bool SinglyLinkedList<T>::insertAtEnd(T val){

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



template <typename T>
bool SinglyLinkedList<T>::insertBefore(T valToBeFound, T valueToBeInserted){

    if(head == NULL){
        cout<<"Value Inserting at start because List is empty"<<endl;
        insertAtStart(valueToBeInserted);
        return true;
    }

    Node<T>* curr = head;
    Node<T>* beforeNode = NULL;

    while((curr->next != NULL) && (curr->data != valToBeFound)){
        beforeNode = curr;
        curr = curr->next;
    }


    if(curr->data == valToBeFound){

        if(beforeNode == NULL){  // means there is only one node 
            insertAtStart(valueToBeInserted);
        } else {
            Node<T>* temp = new Node<T>;
            temp->data = valueToBeInserted;
            temp->next = curr;

            beforeNode->next = temp;
        }
        
    } else {
        insertAtStart(valueToBeInserted);
        cout<<"Value Inserting at start because your data could not be found in List!"<<endl;
    }

    
    return true;
}



template <typename T>
bool SinglyLinkedList<T>::insertAfter(T valToBeFound, T valueToBeInserted){

    if(head == NULL){
        cout<<"Value Inserting at start because List is empty"<<endl;
        insertAtStart(valueToBeInserted);
        return true;
    }

    Node<T>* curr = head;

    while((curr->next != NULL) && (curr->data != valToBeFound)){
        curr = curr->next;
    }


    if(curr->data == valToBeFound){

        Node<T>* temp = new Node<T>;
        temp->data = valueToBeInserted;
        temp->next = curr->next;
        curr->next = temp;
        
    } else {
        insertAtStart(valueToBeInserted);
        cout<<"Value Inserting at start because your data could not be found in List!"<<endl;
    }

    
    return true;
}


template <typename T>
bool SinglyLinkedList<T>::sortedInsert(T val){

    Node<T>* prev = NULL;
    Node<T>* curr = head;

    Node<T>* temp = new Node<T>;
    temp->data = val;

    while(curr != NULL && curr->data < val){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        if(prev != NULL){ // ! means curr has reached the end
            // * do nothing, we are doing this at end 
        } else { // ! means list is empty
            head = temp;
            head->next = NULL;
            return true;
        }
    }

    if(prev == NULL){ // ! means new node is going to be inserted at start
        temp->next = head;
        head = temp;
        return true;
    }

    // ! means new node is going to be inserted at end as well as in middle
    prev->next = temp;
    temp->next = curr;

    return true;
}


template <typename T>
bool SinglyLinkedList<T>::uniqueSortedInsert(T val){
    
    Node<T>* prev = NULL;
    Node<T>* curr = head;

    while(curr != NULL && curr->data <= val){
        prev = curr;
        curr = curr->next;
    }

    Node<T>* temp = new Node<T>;
    temp->data = val;

    if(prev != NULL){
        if(prev->data == val){
            return false;
        } else {
            prev->next = temp;
            temp->next = curr;
        }
    } else {
        temp->next = head;
        head = temp;
    }

    return true;
}



template <typename T>
bool SinglyLinkedList<T>::unsortedRemove(T val){

    Node<T>* curr = head;
    Node<T>* prev = NULL;

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

template <typename T>
bool SinglyLinkedList<T>::sortedRemove(T val){

    if(head == NULL){ // ! means there is no NODE
        return false;
    }


    Node<T>* curr = head;
    Node<T>* prev = NULL;
    Node<T>* beforePrev = NULL;

    while(curr != NULL && curr->data <= val){
        beforePrev = prev;
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){ // ! means we have reached the last node and all values are smaller
        return false;
    }

    if(beforePrev == NULL && prev == NULL){  // ! means first node has value greater than given value
        return false;
    }

    if(beforePrev == NULL && prev != NULL){ // ! means there were only two nodes
        if(prev->data == val){
            head = prev->next;
            delete prev;
            return true;
        }
        return false;
    }

    if(prev->data == val){  // ! means node was found at middle somewhere
        beforePrev->next = curr;
        delete prev;
        return true;
    }

    return false;
}


template <typename T>
bool SinglyLinkedList<T>::removeFromStart(T& val){

    if(head == NULL)
        return false;

    Node<T>* curr = head;
    head = head->next;
    val = curr->data;
    delete curr;

    return true;
}


template <typename T>
bool SinglyLinkedList<T>::removeFromEnd(T& val){

    if(head == NULL){
        return false;
    }

    if(head->next == NULL){
        removeFromStart(val);
        return true;
    }

    Node<T>* curr = head;
    Node<T>* secondLastNode;

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



template <typename T>
void SinglyLinkedList<T>::displayReverseListUsingLoop(){

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



template <typename T>
bool SinglyLinkedList<T>::search(T key){

    Node<T>* curr = head;

    while(curr != NULL){
        if(curr->data == key){
            return true;
        }
        curr = curr->next;
    }

    return false;
}



template <typename T>
T SinglyLinkedList<T>::findMax(){

    // * make sure if there is no node?????  for homework
    // ! make sure if there is no node?????
    // ? make sure if there is no node?????

    T max = head->data;

    Node<T>* curr = head;

    while(curr != NULL){
        if(curr->data > max){
            max = curr->data;
        }
        curr = curr->next;    
    }

    return max;
}



template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList(){
    Node<T>* curr;
    while(head != NULL){
        curr = head->next;
        delete head;
        head = curr;
    }
}
