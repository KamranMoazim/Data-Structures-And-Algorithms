#pragma once

#include "any.h"
#include<iostream>

using namespace std;









// !!!
// ???
// ***
//TODO 








// **************** TASK 2

JosephusList::JosephusList(int N){
    int num = 1;
    first = new PersonNode();
    first->id = num++;
    first->next = NULL;
    PersonNode* iterator = first;

    while(num <= N){
        PersonNode* createdNode = new PersonNode();
        createdNode->id = num;
        createdNode->next = NULL;

        iterator->next = createdNode;

        iterator = iterator->next;
        num++;
    }
    iterator->next = first;
}


JosephusList::~JosephusList(){

    PersonNode* iterator = first->next;

    while(iterator != first){
        // cout<<" "<<iterator->id;
        PersonNode* temp = iterator->next;
        delete iterator;
        iterator = temp;
    }
    // cout<<" "<<first->id<<endl;
    delete first;

}


int JosephusList::getWinner(int M){

    // display();
    int count;
    PersonNode* iterator = first;
    PersonNode* prev = NULL;

    while(iterator != iterator->next){

        count = 0;
        while(count < M){
            prev = iterator;
            iterator = iterator->next;
            count++;
        }

        if (prev == NULL){

            prev = iterator->next;
            while(prev->next != iterator){
                prev = prev->next;
            }

            prev->next = iterator->next;
            cout<<"deleting "<<iterator->id<<endl;
            delete iterator;
            iterator = prev->next;
            prev = NULL;

        } else {
            
            prev->next = iterator->next;
            cout<<"deleting "<<iterator->id<<endl;
            delete iterator;
            iterator = prev->next;
            prev = NULL;

        }

    }

    first = iterator;

    return first->id;
}















// **************** TASK 1.3
bool CDLLD::merge(CDLLD& list1, CDLLD& list2){

    if(list1.isSorted() && list2.isSorted()){

        DNode * curr1 = list1.head.next;
        DNode * curr2 = list2.head.next;
        DNode * curr3 = NULL;
        DNode * curr4 = NULL;
        


        while( curr1 != &list1.head && curr2 != &list2.head ){

            if(curr1->data <= curr2->data){


                if(curr1->next != &list1.head && curr2->data <= curr1->next->data){

                    curr3 = curr1->next;

                    curr1->next = curr2;
                    curr2->prev = curr1;

                    curr1 = curr3;

                } else {
                    if(curr1->next == &list1.head){
                        curr1->next = curr2;
                        curr2->prev = curr1;
                        break;
                    } else {
                        curr1 = curr1->next;
                    }
                }


            } else {


                if(curr2->next != &list2.head && curr1->data <= curr2->next->data){

                    curr4 = curr2->next;

                    curr2->next = curr1;
                    curr1->prev = curr2;

                    curr2 = curr4;

                } else {
                    if(curr2->next == &list2.head){
                        curr2->next = curr1;
                        curr1->prev = curr2;
                        break;
                    } else {
                        curr2 = curr2->next;
                    }
                }

            }

        }


        if(curr1 == &list1.head){
            curr1 = curr1->prev;
            curr1->next = list2.head.next;
            list2.head.next->prev = curr1;
        }

        
        
        if(curr2 == &list2.head){
            curr2 = curr2->prev;
            curr2->next = list1.head.next;
            list1.head.next->prev = curr2;
        }

        
        if(list1.head.next->data <= list2.head.next->data){
            head.next = list1.head.next;
            list1.head.next->prev = &head;
        } else {
            head.next = list2.head.next;
            list2.head.next->prev = &head;
        }

        if(list1.head.prev->data > list2.head.prev->data){
            head.prev = list1.head.prev;
            list1.head.prev->next = &head;
        } else {
            head.prev = list2.head.prev;
            list2.head.prev->next = &head;
        }


        list1.head.next = &list1.head;
        list1.head.prev = &list1.head;

        list2.head.next = &list2.head;
        list2.head.prev = &list2.head;

        cout<<"merge : ";
        (*this).display();

        return true;

    } else {
        return false;
    }

}




// **************** TASK 1.4
void CDLLD::mergeSort(){
    secretMergeSort(*this);
}
void CDLLD::secretMergeSort(CDLLD& list){


    if(list.head.next->next != &list.head){
        CDLLD l1, l2;
        list.splitList(l1, l2);
        secretMergeSort(l1);
        secretMergeSort(l2);
        merge(l1, l2);
    }

}




// **************** TASK 1.5
void CDLLD::reverse(){

    DNode* curr1 = head.next;
    DNode* curr2 = NULL;

    while(curr1 != &head){
        curr2 = curr1->next;
        curr1->next = curr1->prev;
        curr1->prev = curr2;
        curr1 = curr2;
    }
    curr2 = curr1->next;
    curr1->next = curr1->prev;
    curr1->prev = curr2;

}




// **************** TASK 1.6
void CDLLD::insertionSort(){

    DNode* curr1 = head.next;
    DNode* curr2 = head.next->next;
    DNode* curr3 = NULL;
    DNode* curr4 = NULL;

    while(curr2 != &head){

        curr3 = curr1;

        while( (curr1 != curr2) && curr1->data < curr2->data){
            curr1 = curr1->next;
        }

        if(curr1 == curr3){


            curr3 = curr2->next;
            curr4 = curr1->prev;


            if(curr3 == curr4 || curr3 == curr2){

                curr4 = curr2->prev;

                curr3->next = curr2;
                curr2->prev = curr3;

                curr2->next = curr1;
                curr1->prev = curr2;

                curr4->next = curr3;
                curr3->prev = curr4;
                

            } else if (curr1->next != curr2){

                curr2->prev->next = curr3;
                curr3->prev = curr2->prev;

                curr4->next = curr2;
                curr2->next = curr1;

                curr1->prev = curr2;
                curr2->prev = curr4;

            } else {
                curr4->next = curr2;
                curr2->prev = curr4;

                curr2->next = curr1;
                curr1->prev = curr2;

                curr1->next = curr3;
                curr3->prev = curr1;
            }
            

            curr2 = curr3;

            (*this).display();

        } else if(curr1 == curr2){

            curr2 = curr2->next;
            
            (*this).display();

        } else {


            curr3 = curr1;
            curr1 = curr1->prev;
            curr4 = curr2->next;

            curr1->next = curr2;
            curr2->next = curr3;
            curr3->next = curr4;

            curr4->prev = curr3;
            curr3->prev = curr2;
            curr2->prev = curr1;

            curr2 = curr4;
            (*this).display();

        }

        curr1 = head.next;

    }

}






































bool CDLLD::removeKthNode(int k, int& val) {


    if(k > 0 && k <= countNodes()){

        DNode* curr = head.next;
        int count = 1;
        
        while(count < k){
            curr = curr->next;
            count++;
        }

        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;

        val = curr->data;

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

    cout<<"leftHalf : ";
    leftHalf.display();
    cout<<"rightHalf : ";
    rightHalf.display();


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


