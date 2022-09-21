#pragma once

#include<iostream>

using namespace std;



class UnsortedList {
    int* arr;
    int maxSize;
    int currentSize;
    bool isFull();
    bool isEmpty();
    bool isValidIndex(int i);
public:
    UnsortedList(int s);
    UnsortedList(const UnsortedList& comingUnsortedList);
    UnsortedList operator = (const UnsortedList& comingUnsortedList);
    bool operator == (const UnsortedList& comingUnsortedList);
    int operator [] (int index);
    const int* getArr() const ;
    int getCurrentSize() const ;
    bool getVal(int index, int& val);
    bool searchVal(int val);
    int searchValCount(int val);
    bool insertVal(int val);
    void display();
    bool removeSingleOccurenceAndShiftLeft(int index);
    bool removeSingleOccurenceAndPlaceLastElementOnThisPlaces(int index);
    int removeAllOccurencesAndShiftLeft(int val);
    int removeAllOccurencesAndPlaceLastElementOnThesePlaces(int val);
    int removeAllOccurencesWithNewArray(int val);
    int removeAllOccurencesWITHOUTNewArray(int val);
    void combineList(const UnsortedList& list2);
    ~UnsortedList();
    bool removeMax (int& maxVal);
    void reverse ();
    int replaceVal (int oldVal, int newVal);
    bool removeMin (int& minVal);
    bool removeLastOccurrence (int val);
    // TASK 1.1
    UnsortedList intersection(const UnsortedList& list2) const;
    // TASK 3.1
    bool isSubset(const UnsortedList& list2) const;
    // TASK 4.1
    UnsortedList difference(const UnsortedList& list2) const;
    // TASK 5.1
    UnsortedList unionFunc(const UnsortedList& list2) const;
};

