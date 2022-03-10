#pragma once

#include "any.h"
#include<iostream>

using namespace std;


bool UnsortedList::isFull(){
    return maxSize == currentSize ? true : false;
}
bool UnsortedList::isEmpty(){
    return currentSize == 0 ? true : false;
}
bool UnsortedList::isValidIndex(int i){
    return currentSize >= i ? true : false;
}

UnsortedList::UnsortedList(int s=10){
    maxSize = s;
    if(maxSize<=0){
        maxSize = 10;
    }
    arr = new int[maxSize];
    currentSize = 0;
}
UnsortedList::UnsortedList(const UnsortedList& comingUnsortedList){
    maxSize = comingUnsortedList.maxSize;
    arr = new int[maxSize];
    currentSize = comingUnsortedList.currentSize;

    for(int i=0; i<currentSize; i++){
        arr[i] = comingUnsortedList.arr[i];
    }
}
UnsortedList UnsortedList::operator = (const UnsortedList& comingUnsortedList){
    if(&comingUnsortedList == this){
        return *this;
    }

    if(arr != NULL){
        delete[] arr;
        arr = NULL;
    }

    maxSize = comingUnsortedList.maxSize;
    arr = new int[maxSize];
    currentSize = comingUnsortedList.currentSize;

    for(int i=0; i<currentSize; i++){
        arr[i] = comingUnsortedList.arr[i];
    }

    return *this;
}
bool UnsortedList::operator == (const UnsortedList& comingUnsortedList){
    if(&comingUnsortedList == this){
        return true;
    }

    if(maxSize == comingUnsortedList.maxSize && currentSize == comingUnsortedList.currentSize){
        
        for(int i=0; i<currentSize; i++){
            if(arr[i] != comingUnsortedList.arr[i]){
                return false;
            }
        }
        return true;

    } else {
        return false;
    }
}
int UnsortedList::operator [] (int index){
    if(isValidIndex(index)){
        return arr[index];
    }
    return -1;
}
const int* UnsortedList::getArr() const {
    return arr;
}
int UnsortedList::getCurrentSize() const {
    return currentSize;
}
bool UnsortedList::getVal(int index, int& val) {
    if(isValidIndex(index)){
        val = arr[index];
        return true;
    }
    return false;
}
bool UnsortedList::searchVal(int val) {
    for(int i=0; i<currentSize; i++){
        if(arr[i] == val){
            return true;
        }
    }
    return false;
}
int UnsortedList::searchValCount(int val) {
    int count=0;
    for(int i=0; i<currentSize; i++){
        if(arr[i] == val){
            count++;
        }
    }
    return count;
}
bool UnsortedList::insertVal(int val){
    if(isFull()){
        cout<<"List is Full!"<<endl;
        return false;
    } else {
        arr[currentSize] = val;
        currentSize++;
        return true;
    }
}
void UnsortedList::display() {
    if(isEmpty()){
        cout<<"List is Empty!"<<endl;
    } else {
        for(int i=0; i<currentSize; i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }
}
bool UnsortedList::removeSingleOccurenceAndShiftLeft(int index){
    if(isValidIndex(index)){
        for(int j=index; j<currentSize; j++){
            arr[j] = arr[j+1];
        }
        currentSize--;
        return true;
    }
    return false;
}
bool UnsortedList::removeSingleOccurenceAndPlaceLastElementOnThisPlaces(int index){
    if(isValidIndex(index)){

        arr[index] = arr[currentSize-1];
        currentSize--;
        return true;
    }

    return false;
}
int UnsortedList::removeAllOccurencesAndShiftLeft(int val){
    int count = 0;
    for(int i=0; i<currentSize; i++){
        if(arr[i] == val){
            count++;
            for(int j=i; j<currentSize; j++){
                arr[j] = arr[j+1];
            }
        }
    }
    currentSize -= count;
    return count;
}
int UnsortedList::removeAllOccurencesAndPlaceLastElementOnThesePlaces(int val){
    int count = 0;
    int i=currentSize-1;
    int replacingVal = 0;

    while(i>=0 && arr[i]==val){
        i--;
    }
    replacingVal = arr[i];

    for(i=0; i<currentSize; i++){
        if(arr[i] == val){
            arr[i] = replacingVal;
            count++;
        }
    }

    currentSize -= count;

    return count;
}
int UnsortedList::removeAllOccurencesWithNewArray(int val){
    int count = 0;
    int* newArr = new int[maxSize];
    int i=0, j=0;

    for(i=0, j=0; i<currentSize; i++){
        if(arr[i] != val){
            newArr[j] = arr[i];
            j++;
        } else {
            count++;
        }
    }

    delete[] arr;
    arr = NULL;

    currentSize = j;
    arr = newArr;

    return count;
}
int UnsortedList::removeAllOccurencesWITHOUTNewArray(int val){
    int count = 0;
    int i=0, j=0;

    for(i=0, j=0; i<currentSize; i++){
        if(arr[i] != val){
            arr[j] = arr[i];
            j++;
        } else {
            count++;
        }
    }

    currentSize = j;

    return count;
}
UnsortedList::~UnsortedList(){
    if(arr != NULL){
        delete[] arr;
        arr = NULL;
    }
}


















bool SortedList::isFull(){
    return maxSize == currentSize ? true : false;
}
bool SortedList::isEmpty(){
    return currentSize == 0 ? true : false;
}
bool SortedList::isValidIndex(int i){
    return currentSize >= i ? true : false;
}
SortedList::SortedList(int s=10){
    maxSize = s;
    if(maxSize<=0){
        maxSize = 10;
    }
    arr = new int[maxSize];
    currentSize = 0;
}
SortedList::SortedList(const SortedList& comingSortedList){
    maxSize = comingSortedList.maxSize;
    arr = new int[maxSize];
    currentSize = comingSortedList.currentSize;

    for(int i=0; i<currentSize; i++){
        arr[i] = comingSortedList.arr[i];
    }
}
SortedList SortedList::operator = (const SortedList& comingSortedList){
    if(&comingSortedList == this){
        return *this;
    }

    if(arr != NULL){
        delete[] arr;
        arr = NULL;
    }

    maxSize = comingSortedList.maxSize;
    arr = new int[maxSize];
    currentSize = comingSortedList.currentSize;

    for(int i=0; i<currentSize; i++){
        arr[i] = comingSortedList.arr[i];
    }

    return *this;
}
bool SortedList::operator == (const SortedList& comingSortedList){
    if(&comingSortedList == this){
        return true;
    }

    if(maxSize == comingSortedList.maxSize && currentSize == comingSortedList.currentSize){
        
        for(int i=0; i<currentSize; i++){
            if(arr[i] != comingSortedList.arr[i]){
                return false;
            }
        }
        return true;

    } else {
        return false;
    }
}
int SortedList::operator [] (int index){
    if(isValidIndex(index)){
        return arr[index];
    }
    return -1;
}
const int* SortedList::getArr() const {
    return arr;
}
int SortedList::getCurrentSize() const {
    return currentSize;
}
bool SortedList::getVal(int index, int& val) {
    if(isValidIndex(index)){
        val = arr[index];
        return true;
    }
    return false;
}
bool SortedList::searchVal(int val) {
    for(int i=0; i<currentSize; i++){
        if(arr[i] == val){
            return true;
        }
    }
    return false;
}
int SortedList::searchValCount(int val) {
    int count=0;
    for(int i=0; i<currentSize; i++){
        if(arr[i] == val){
            count++;
        }
    }
    return count;
}
bool SortedList::insertVal(int val){
    if(isFull()){
        cout<<"List is Full!"<<endl;
        return false;
    } else {

        int i=currentSize-1;
        while(i>=0 && arr[i]>val){
            arr[i+1]=arr[i];
            i--;
        }

        arr[i+1]=val;
        currentSize++;
        
        return true;
    }
}
bool SortedList::uniqueInsertVal(int val){
    if(isFull()){
        cout<<"List is Full!"<<endl;
        return false;
    } else {

        if(searchVal(val)){
            cout<<"Value "<<val<<" already Exists in List!"<<endl;
            return false;
        } else {
            insertVal(val);
            return true;
        }
    }
}
void SortedList::display() {
    if(isEmpty()){
        cout<<"List is Empty!"<<endl;
    } else {
        for(int i=0; i<currentSize; i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }
}
bool SortedList::removeSingleOccurenceAndShiftLeft(int index){
    if(isValidIndex(index)){
        for(int j=index; j<currentSize; j++){
            arr[j] = arr[j+1];
        }
        currentSize--;
        return true;
    }
    return false;
}
int SortedList::removeAllOccurencesAndShiftLeft(int val){
    int count = 0;
    for(int i=0; i<currentSize; i++){
        if(arr[i] == val){
            count++;
            for(int j=i; j<currentSize; j++){
                arr[j] = arr[j+1];
            }
        }
    }
    currentSize -= count;
    return count;
}
int SortedList::removeAllOccurencesWithNewArray(int val){
    int count = 0;
    int* newArr = new int[maxSize];
    int i=0, j=0;

    for(i=0, j=0; i<currentSize; i++){
        if(arr[i] != val){
            newArr[j] = arr[i];
            j++;
        } else {
            count++;
        }
    }

    delete[] arr;
    arr = NULL;

    currentSize = j;
    arr = newArr;

    return count;
}
int SortedList::removeAllOccurencesWITHOUTNewArray(int val){
    int count = 0;
    int i=0, j=0;

    for(i=0, j=0; i<currentSize; i++){
        if(arr[i] != val){
            arr[j] = arr[i];
            j++;
        } else {
            count++;
        }
    }

    currentSize = j;

    return count;
}
SortedList::~SortedList(){
    if(arr != NULL){
        delete[] arr;
        arr = NULL;
    }
}
