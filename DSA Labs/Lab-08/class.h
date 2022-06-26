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
    T findMinPrivate(Node<T>* , T );
    int countEvensPrivate(Node<T>* , T );
public:
    // TASK 0
    SinglyLinkedList();
    ~SinglyLinkedList();
    bool insertAtStart(T );
    void displayList();
    int countNodes();

    // TASK 1
    bool removeKthNode (T , T& );

    // TASK 2
    void combine(SinglyLinkedList& , SinglyLinkedList& );

    // TASK 3
    void shuffleMerge (LinkedList& , LinkedList& );

    // TASK 4
    bool removeLastNode (T& );
    bool removeSecondLastNode (T& );

    // TASK 5
    T findMin();
    T findMax();

    // TASK 6
    T findMinRecursively();

    // TASK 7
    int countEvens();

    SinglyLinkedList(const SinglyLinkedList<T>& );
    SinglyLinkedList<T> operator = (const SinglyLinkedList<T>& );
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
    // T findMax();
};
