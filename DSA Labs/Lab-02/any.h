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
};









class SortedList {
    int* arr;
    int maxSize;
    int currentSize;
    bool isFull();
    bool isEmpty();
    bool isValidIndex(int i);
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
};