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
    ~UnsortedList();
    // TASK 2
    bool removeMax (int& maxVal);
    void reverse ();
    void combineList (const UnsortedList& list2);
    // TASK 4
    int replaceVal (int oldVal, int newVal);
    bool removeMin (int& minVal);
    bool removeLastOccurrence (int val);
};









class SortedList {
    int* arr;
    int maxSize;
    int currentSize;
    bool isFull();
    bool isEmpty();
    bool isValidIndex(int i);
    void reSort();
public:
    SortedList(int s);
    SortedList(const SortedList& comingSortedList);
    SortedList operator = (const SortedList& comingSortedList);
    bool operator == (const SortedList& comingSortedList);
    int operator [] (int index);
    const int* getArr() const;
    int getCurrentSize() const;
    bool getVal(int index, int& val);
    bool searchVal(int val);
    int searchValCount(int val);
    bool insertVal(int val);
    bool uniqueInsertVal(int val);
    void display();
    bool removeSingleOccurenceAndShiftLeft(int index);
    int removeAllOccurencesAndShiftLeft(int val);
    int removeAllOccurencesWithNewArray(int val);
    int removeAllOccurencesWITHOUTNewArray(int val);
    ~SortedList();
    // TASK 1
    bool replace (int index, int newVal);
    bool binarySearch (int val);
};