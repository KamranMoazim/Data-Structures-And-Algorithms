#pragma once

#include "UnsortedList.h"
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


bool UnsortedList::removeMax (int& maxVal){
    if(isEmpty()){
        return false;
    } else {

        maxVal = arr[0];
        int maxValIndex = 0;

        for(int i=0; i<currentSize; i++){
            if(maxVal < arr[i]){
                maxVal = arr[i];
                maxValIndex = i;
            }
        }

        if(searchValCount(maxVal) > 1){
            // cout<<"run";
            for(int i=0; i<currentSize; i++){
                if(maxVal == arr[i]){
                    maxValIndex = i;
                    break;
                }
            }
        }

        for(int i=maxValIndex; i<currentSize; i++){
            arr[i] = arr[i+1];
        }

        currentSize--;

        return true;
    }
}

void UnsortedList::reverse (){
    if(isEmpty()){
        cout<<"List is Empty!"<<endl;
    } else {
        int temp=0;
        for(int i=0, j=currentSize-1; i<(currentSize/2); i++,j--){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

void UnsortedList::combineList(const UnsortedList& list2){
    if(list2.currentSize + currentSize < maxSize){
        for(int i=0, j=currentSize; i<list2.currentSize; i++, j++){
            cout<<list2.arr[i]<<"\t";
            arr[j] = list2.arr[i];
        }
    } else {
        int tempSize = list2.currentSize + currentSize;
        int* newArr = new int[tempSize];
        for(int i=0; i<currentSize; i++){
            newArr[i] = arr[i];
        }
        for(int i=0, j=currentSize; i<list2.currentSize; i++, j++){
            newArr[j] = list2.arr[i];
        }
        currentSize = tempSize;
        // cout<<currentSize<<endl;
        delete[] arr;
        arr = NULL;
        arr = newArr;
    }
}

int UnsortedList::replaceVal (int oldVal, int newVal){
    int count=0;
    for(int i=0; i<currentSize; i++){
        if(arr[i]==oldVal){
            arr[i]=newVal;
            count++;
        }
    }
    return count;
}

bool UnsortedList::removeMin (int& minVal){
    if(isEmpty()){
        return false;
    } else {

        minVal = arr[0];
        int minValIndex = 0;

        for(int i=0; i<currentSize; i++){
            if(minVal > arr[i]){
                minVal = arr[i];
                minValIndex = i;
            }
        }

        if(searchValCount(minVal) > 1){
            // cout<<"run";
            for(int i=0; i<currentSize; i++){
                if(minVal == arr[i]){
                    minValIndex = i;
                    break;
                }
            }
        }

        for(int i=minValIndex; i<currentSize; i++){
            arr[i] = arr[i+1];
        }

        currentSize--;

        return true;
    }
}

bool UnsortedList::removeLastOccurrence (int val){
    if(isEmpty()){
        return false;
    } else {

        int valIndex = 0;

        for(int i=0; i<currentSize; i++){
            if(arr[i] == val){
                valIndex = i;
            }
        }

        if(valIndex == 0){
            return false;
        }

        val = arr[valIndex];

        if(searchValCount(val) > 1){
            for(int i=currentSize; i>=0; i--){
                if(val == arr[i]){
                    valIndex = i;
                    break;
                }
            }
        }

        for(int i=valIndex; i<currentSize; i++){
            arr[i] = arr[i+1];
        }

        currentSize--;

        return true;
    }
}


// TASK 1.1
UnsortedList UnsortedList::intersection(const UnsortedList& list2) const {

    int thisSize = this->getCurrentSize();
    int list2Size = list2.getCurrentSize();
   
    if(thisSize <= list2Size){

        UnsortedList temp(thisSize);

        for(int i=0; i<thisSize; i++){

            for(int j=0; j<list2Size; j++){
                
                if(this->arr[i]==list2.arr[j]){
                    temp.insertVal(this->arr[i]);
                }

            }
        }

        return temp;

    } else {

        UnsortedList temp(list2Size);

        for(int i=0; i<list2Size; i++){

            for(int j=0; j<thisSize; j++){
            
                if(list2.arr[i]==this->arr[j]){
                    temp.insertVal(list2.arr[i]);
                }

            }
        }

        return temp;
    }
}

// TASK 3.1
bool UnsortedList::isSubset(const UnsortedList& list2) const {

    int thisSize = this->getCurrentSize();
    int list2Size = list2.getCurrentSize();
    int count = 0;

    bool isSubsetTrue = false;
   
    if(thisSize <= list2Size){

        for(int i=0; i<thisSize; i++){

            for(int j=0; j<list2Size; j++){
                
                if(this->arr[i]==list2.arr[j]){
                    count++;
                }

            }
        }

        if(thisSize == count || thisSize == 0){
            isSubsetTrue = true;
        }

        return isSubsetTrue;

    } else {

        return isSubsetTrue;
    }
}


// TASK 4.1
UnsortedList UnsortedList::difference(const UnsortedList& list2) const {

    int thisSize = this->getCurrentSize();
    int list2Size = list2.getCurrentSize();
    bool matched = false;
   
    UnsortedList temp(thisSize);

    for(int i=0; i<thisSize; i++){

        for(int j=0; j<list2Size; j++){
            
            if(this->arr[i]==list2.arr[j]){
                matched = true;
                break;
            }

        }
        if(!matched){
            temp.arr[temp.currentSize++] = this->arr[i];
        }
        matched = false;
    }

    return temp;
}


// TASK 5.1
UnsortedList UnsortedList::unionFunc(const UnsortedList& list2) const {

    int thisSize = this->getCurrentSize();
    int list2Size = list2.getCurrentSize();

    int i=0, j=0;
   
    UnsortedList temp(thisSize+list2Size);

    for(i=0; i<thisSize; i++){
        temp.arr[temp.currentSize++] = this->arr[i];
    }

    for(j=0; i<thisSize+list2Size; j++, i++){
        temp.arr[temp.currentSize++] = list2.arr[j];
    }

    return temp;
}
