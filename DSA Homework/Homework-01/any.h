#pragma once

#include<iostream>

using namespace std;




bool binarySearch(const int* arr, int size, int key){
    int start=0, end=size-1, middle=0;

    while(start<=end){
        middle = (start+end)/2;
        if(key == arr[middle]){
            return true;
        } else if(key < arr[middle]){
            end = middle-1;
        } else {
            start = middle+1;
        }
    }
    return false;
}






class UnsortedList {
    int* arr;
    int maxSize;
    int currentSize;
    bool isFull(){
        return maxSize == currentSize ? true : false;
    }
    bool isEmpty(){
        return currentSize == 0 ? true : false;
    }
    bool isValidIndex(int i){
        return currentSize >= i ? true : false;
    }
public:
    UnsortedList(int s=10){
        maxSize = s;
        if(maxSize<=0){
            maxSize = 10;
        }
        arr = new int[maxSize];
        currentSize = 0;
    }
    UnsortedList(const UnsortedList& comingUnsortedList){
        maxSize = comingUnsortedList.maxSize;
        arr = new int[maxSize];
        currentSize = comingUnsortedList.currentSize;

        for(int i=0; i<currentSize; i++){
            arr[i] = comingUnsortedList.arr[i];
        }
    }
    UnsortedList operator = (const UnsortedList& comingUnsortedList){
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
    bool operator == (const UnsortedList& comingUnsortedList){
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
    int operator [] (int index){
        if(isValidIndex(index)){
            return arr[index];
        }
        return -1;
    }
    const int* getArr() const {
        return arr;
    }
    int getCurrentSize() const {
        return currentSize;
    }
    bool getVal(int index, int& val) {
        if(isValidIndex(index)){
            val = arr[index];
            return true;
        }
        return false;
    }
    bool searchVal(int val) {
        for(int i=0; i<currentSize; i++){
            if(arr[i] == val){
                return true;
            }
        }
        return false;
    }
    int searchValCount(int val) {
        int count=0;
        for(int i=0; i<currentSize; i++){
            if(arr[i] == val){
                count++;
            }
        }
        return count;
    }
    bool insertVal(int val){
        if(isFull()){
            cout<<"List is Full!"<<endl;
            return false;
        } else {
            arr[currentSize] = val;
            currentSize++;
            return true;
        }
    }
    void display() {
        if(isEmpty()){
            cout<<"List is Empty!"<<endl;
        } else {
            for(int i=0; i<currentSize; i++){
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
    }
    bool removeSingleOccurenceAndShiftLeft(int index){
        if(isValidIndex(index)){
            for(int j=index; j<currentSize; j++){
                arr[j] = arr[j+1];
            }
            currentSize--;
            return true;
        }
        return false;
    }
    bool removeSingleOccurenceAndPlaceLastElementOnThisPlaces(int index){
        if(isValidIndex(index)){

            arr[index] = arr[currentSize-1];
            currentSize--;
            return true;
        }

        return false;
    }
    int removeAllOccurencesAndShiftLeft(int val){
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
    int removeAllOccurencesAndPlaceLastElementOnThesePlaces(int val){
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
    int removeAllOccurencesWithNewArray(int val){
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
    int removeAllOccurencesWITHOUTNewArray(int val){
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
    ~UnsortedList(){
        if(arr != NULL){
            delete[] arr;
            arr = NULL;
        }
    }
};

















class SortedList {
    int* arr;
    int maxSize;
    int currentSize;
    bool isFull(){
        return maxSize == currentSize ? true : false;
    }
    bool isEmpty(){
        return currentSize == 0 ? true : false;
    }
    bool isValidIndex(int i){
        return currentSize >= i ? true : false;
    }
public:
    SortedList(int s=10){
        maxSize = s;
        if(maxSize<=0){
            maxSize = 10;
        }
        arr = new int[maxSize];
        currentSize = 0;
    }
    SortedList(const SortedList& comingSortedList){
        maxSize = comingSortedList.maxSize;
        arr = new int[maxSize];
        currentSize = comingSortedList.currentSize;

        for(int i=0; i<currentSize; i++){
            arr[i] = comingSortedList.arr[i];
        }
    }
    SortedList operator = (const SortedList& comingSortedList){
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
    bool operator == (const SortedList& comingSortedList){
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
    int operator [] (int index){
        if(isValidIndex(index)){
            return arr[index];
        }
        return -1;
    }
    const int* getArr() const {
        return arr;
    }
    int getCurrentSize() const {
        return currentSize;
    }
    bool getVal(int index, int& val) {
        if(isValidIndex(index)){
            val = arr[index];
            return true;
        }
        return false;
    }
    bool searchVal(int val) {
        for(int i=0; i<currentSize; i++){
            if(arr[i] == val){
                return true;
            }
        }
        return false;
    }
    int searchValCount(int val) {
        int count=0;
        for(int i=0; i<currentSize; i++){
            if(arr[i] == val){
                count++;
            }
        }
        return count;
    }
    bool insertVal(int val){
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
    bool uniqueInsertVal(int val){
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
    void display() {
        if(isEmpty()){
            cout<<"List is Empty!"<<endl;
        } else {
            for(int i=0; i<currentSize; i++){
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
    }
    bool removeSingleOccurenceAndShiftLeft(int index){
        if(isValidIndex(index)){
            for(int j=index; j<currentSize; j++){
                arr[j] = arr[j+1];
            }
            currentSize--;
            return true;
        }
        return false;
    }
    int removeAllOccurencesAndShiftLeft(int val){
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
    int removeAllOccurencesWithNewArray(int val){
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
    int removeAllOccurencesWITHOUTNewArray(int val){
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
    ~SortedList(){
        if(arr != NULL){
            delete[] arr;
            arr = NULL;
        }
    }
};