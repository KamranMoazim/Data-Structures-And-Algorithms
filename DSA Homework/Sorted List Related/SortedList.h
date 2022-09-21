#pragma once

#include<iostream>

using namespace std;



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
    bool replace (int index, int newVal);
    bool binarySearch (int val);
    SortedList intersection(const SortedList& list2) const;
    bool isSubset(const SortedList& list2) const;
    SortedList difference(const SortedList& list2) const;
    SortedList unionFunc(const SortedList& list2) const;
};

