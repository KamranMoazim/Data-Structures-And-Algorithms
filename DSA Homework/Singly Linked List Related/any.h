#pragma once

#include<iostream>

using namespace std;

template <typename T>
class SinglyLinkedList;

template <typename T>
class Node {
private:
    T data;
    Node* next;
public:
    friend SinglyLinkedList<T>;
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList<T>& );
    SinglyLinkedList<T> operator = (const SinglyLinkedList<T>& );
    void displayList();
    bool insertAtStart(T );
    bool insertAtEnd(T );
    bool insertBefore(T , T );
    bool insertAfter(T , T );
    // ********
    bool sortedInsert(T );
    bool sortedRemove(T );
    bool unsortedRemove(T );
    // ********
    bool uniqueSortedInsert(T );
    // ********
    bool removeFromStart(T& );
    bool removeFromEnd(T& );
    void displayReverseListUsingLoop();
    bool search(T );
    T findMax();
    ~SinglyLinkedList();
};

