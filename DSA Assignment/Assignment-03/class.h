// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon



#pragma once

#include<iostream>

using namespace std;


class LinkedList;


class Node {
private:
    int data;
    Node* next;
public:
    friend class LinkedList;
};


class LinkedList {
private:
    Node* head;
public:
    LinkedList();
    ~LinkedList();

    // ********************************** TASKs 1.1
    bool insert(int ); 
    // This function will insert a new value (val) into the linked list, and return true.

    void display();
    // This function will display the contents of the linked list on screen. This function will also
    // display the total number of nodes present in the linked list.

    bool remove(int );
    // This function removes the node containing the first occurrence of val from the linked list.
    // This function will return true if such a node is found (and removed) from the linked list,
    // and it will return false otherwise.

    bool search(int );
    // This function searches for val in the linked list. It will return true if val is present in the
    // linked list and it will return false otherwise.

    // ********************************** TASKs 2.1
    void sort();

    void reverse();


    // this function is made as it is required in TASK 1.3 to remove complete List
    void emptyList();
};

