#pragma once

#include "any.h"
#include<iostream>

using namespace std;









// !!!
// ???
// ***
//TODO 




bool CDLLD::removeKthNode(int k, int& val) {


    if(k <= countNodes()){

        DNode* curr = head.next;
        int count = 0;
        
        while(count < k){
            curr = curr->next;
            count++;
        }

        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;


        delete curr;

        return true;

    } else {
        return false;
    }

}






bool CDLLD::removeSecondLastNode(int& val){

    if(head.next != &head && head.next->next != &head){

        val = head.prev->prev->data;

        DNode* secondLastNode = head.prev->prev;

        // cout<<"head.prev->prev->prev : "<<head.prev->prev->prev->data<<endl;
        // cout<<"head.prev->prev->prev->next : "<<head.prev->prev->next->data<<endl;

        head.prev->prev = head.prev->prev->prev;
        head.prev->prev->next = head.prev;


        delete secondLastNode;

        return true;
    }

    return false;

}






bool CDLLD::removeLastNode(int& val){


    if(head.next != &head){

        val = head.prev->data;

        DNode* lastNode = head.prev;

        // cout<<"head.prev->prev : "<<head.prev->prev->data<<endl;
        // cout<<"head.prev->prev->next : "<<head.prev->prev->data<<endl;

        head.prev = head.prev->prev;
        head.prev->next = &head;

        // cout<<val<<endl;

        delete lastNode;

        return true;
    }

    return false;

} 





bool CDLLD::isSorted() const {

    DNode * curr = head.next;
    while(curr != &head){

        if(curr->next != &head && curr->next->data < curr->data){
            return false;
        }

        curr = curr->next;
    }

    return true;
}






void CDLLD::splitList(CDLLD& leftHalf, CDLLD& rightHalf){


    int nodes = countNodes();
    int count = 0;


    DNode* curr1 = head.next;
    DNode* curr2 = NULL;

    


    while(count < (nodes/2.0 - 1)){
        curr1 = curr1->next;
        count++;
    }
    
    curr2 = curr1->next;


    leftHalf.head.next = head.next;
    leftHalf.head.prev = curr1;
    curr1->next = &leftHalf.head;
    head.next->prev = &leftHalf.head;


    rightHalf.head.next = curr2;
    rightHalf.head.prev = head.prev;
    head.prev->next = &rightHalf.head;
    curr2->prev = &rightHalf.head;



    head.next = &head;
    head.prev = &head;

}





void CDLLD::shuffleMerge(CDLLD& list1, CDLLD& list2){



    DNode * curr1 = list1.head.next;
    DNode * curr2 = list2.head.next;


    while(curr1 != &list1.head && curr2 != &list2.head ){

        DNode* curr3 = curr1->next;
        DNode* curr4 = curr2->next;
        
        
        curr1->next = curr2;
        curr2->prev = curr1;

        curr2->next = curr3;
        curr3->prev = curr2;

        // cout<<curr1->data<<endl;
        // cout<<curr2->data<<endl;

        curr1 = curr3;
        curr2 = curr4;

    }

    head.next = list1.head.next;
    list1.head.next->prev = &head;
    head.prev = list2.head.prev;
    list2.head.prev->next = &head;



    list1.head.next = &list1.head;
    list1.head.prev = &list1.head;

    list2.head.next = &list2.head;
    list2.head.prev = &list2.head;
    
}






void CDLLD::combine(CDLLD& list1, CDLLD& list2){



    if( list1.head.next == &list1.head && list2.head.next == &list2.head ){

        head.next = &head;
        head.prev = &head;

    } else if( list1.head.next != &list1.head && list2.head.next == &list2.head ){

        head.next = list1.head.next;
        list1.head.next->prev = &head;
        head.prev = list1.head.prev;
        list1.head.prev->next = &head;

    } else if( list1.head.next == &list1.head && list2.head.next != &list2.head ){

        head.next = list2.head.next;
        list2.head.next->prev = &head;
        head.prev = list2.head.prev;
        list2.head.prev->next = &head;

    } else {

        list1.head.prev->next = list2.head.next;
        list2.head.next->prev = list1.head.prev;

        head.next = list1.head.next;
        head.prev = list2.head.prev;

        list1.head.next->prev = &head;
        list2.head.prev->next = &head;

    }








    list1.head.next = &list1.head;
    list1.head.prev = &list1.head;

    list2.head.next = &list2.head;
    list2.head.prev = &list2.head;
}
















int CDLLD::countNodes() const {
    DNode * curr = head.next;
    int count = 0;
    while(curr != &head){
        count++;
        curr = curr->next;
    }
    return count;
}






CDLLD::CDLLD(){
    head.next = &head;
    head.prev = &head;
}


CDLLD::CDLLD(const CDLLD& list){

    head.next = &head;
    head.prev = &head;

    DNode* curr = list.head.next;

    while(curr != &list.head){

        DNode* temp = new DNode();
        temp->data = curr->data;

        temp->prev = head.prev;
        temp->next = &head;
        head.prev->next = temp;
        head.prev = temp;

        curr = curr->next;
    }
}


CDLLD CDLLD::operator = (const CDLLD& list){

    if(&list != this){
        
        DNode * curr = head.next;
        while(curr != &head){
            curr = curr->next;
            delete curr->prev;
        }
        head.next = &head;
        head.prev = &head;


        curr = list.head.next;
        while(curr != &list.head){
            DNode * temp = new DNode ();
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


 
void CDLLD::display() const {
    DNode * curr = head.next;
    while(curr != &head){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}


 
bool CDLLD::insertAtEnd(int val){
    DNode * temp = new DNode ();
    temp->data = val;

    temp->prev = head.prev;
    temp->next = &head;
    head.prev->next = temp;
    head.prev = temp;

    return true;
}


 
bool CDLLD::insertAtStart(int val){
    DNode * temp = new DNode ();
    temp->data = val;

    temp->next = head.next;
    temp->prev = &head;
    head.next = temp;
    temp->next->prev = temp;

    return true;
}


 
bool CDLLD::sortedInsert(int val){

    DNode * temp = new DNode ();
    temp->data = val;

    DNode * curr = head.next;

    while(curr != &head && curr->data < val){
        curr = curr->next;
    }

    temp->next = curr;
    temp->prev = curr->prev;

    temp->prev->next = temp;
    curr->prev = temp;

    return true;
}


 
bool CDLLD::sortedRemove(int val){

    DNode * curr = head.next;

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


 
bool CDLLD::unsortedRemove(int val){

    DNode * curr = head.next;

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


 
CDLLD::~CDLLD(){
    DNode * curr = head.next;
    while(curr != &head){
        curr = curr->next;
        // cout<<"*** "<<curr->prev->data<<"\t";
        delete curr->prev;
    }
    cout<<endl;
    head.next = &head;
    head.prev = &head;
}


