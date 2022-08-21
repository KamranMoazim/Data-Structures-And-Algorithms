#pragma once

#include<iostream>

using namespace std;

class CDLLD;

class DNode {
private:
    int data;
    DNode* next;
    DNode* prev;
public:
    friend CDLLD;
};


class CDLLD {
private:
    DNode head;
public:

    CDLLD();

    CDLLD(const CDLLD& list);

    CDLLD operator = (const CDLLD& list);

    void display() const ;

    bool insertAtEnd(int val);

    bool insertAtStart(int val);

    bool sortedInsert(int val);

    bool sortedRemove(int val);

    bool unsortedRemove(int val);

    ~CDLLD();

    int countNodes() const ;

    void combine(CDLLD& , CDLLD& );

    void shuffleMerge(CDLLD& , CDLLD& );

    void splitList(CDLLD& , CDLLD& );

    bool isSorted () const;

    bool removeLastNode (int& );

    bool removeSecondLastNode (int& );

    bool removeKthNode (int , int& );

};

