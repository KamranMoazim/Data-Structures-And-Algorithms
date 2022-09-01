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
};

