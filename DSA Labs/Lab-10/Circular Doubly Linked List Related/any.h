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
    void secretMergeSort(CDLLD& );
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

    // **************** TASK 1.3
    bool merge (CDLLD& , CDLLD& );

    // **************** TASK 1.4
    void mergeSort();

    // **************** TASK 1.5
    void reverse ();

    // **************** TASK 1.6
    void insertionSort();
};



// **************** TASK 2
class JosephusList;

class PersonNode {
    friend class JosephusList;
private:
    int id;
    PersonNode* next;
};

class JosephusList {
private:
    PersonNode* first;
public:
    JosephusList(int );
    ~JosephusList ();
    int getWinner (int );
    void display(){
        
        PersonNode* iterator = first->next;
        cout<<first->id;
        while(iterator != first){
            cout<<" "<<iterator->id;
            iterator = iterator->next;
        }
        cout<<endl;
    }
};