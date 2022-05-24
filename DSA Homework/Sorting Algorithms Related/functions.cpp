#pragma once

#include<iostream>

using namespace std;


// OTHER
template<typename T>
void swapper(T& a, T& b){
    T t=a;
    a=b;
    b=t;
}

template<typename T>
void printArray(T arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl;
}


// SORTING ALGOS

// *************** 1
template<typename T>
void selectionSort(T* arr, int size){

    int minValIndex=0;
    for(int i=0; i<size; i++){

        minValIndex = i;

        for(int j=i+1; j<size; j++){

            if(arr[j] < arr[minValIndex]){
                minValIndex = j;
            }

        }

        swapper(arr[i], arr[minValIndex]);
    }
}

// *************** 2
template<typename T>
void insertionSort(T* arr, int size){

    T key;
    for(int i=0; i<size; i++){
        key = arr[i];
        int j = i-1;

        while(j>=0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// *************** 3
template<typename T>
void bubbleSort(T* arr, int size){

    int i=size-1;

    while(i > 0){

        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                swapper(arr[j], arr[j+1]);
            }
        }

        i--;
    }
}

// *************** 4
template<typename T>
void merge(T* arr, int leftStart, int leftEnd, int rightStart, int rightEnd){

    int i=leftStart, j=rightStart, k=0, size=rightEnd-leftStart+1;

    T* temp = new T[size];

    while( i<=leftEnd && j<=rightEnd ){
        if(arr[i] < arr[j]){
            temp[k] = arr[i++];
        } else {
            temp[k] = arr[j++];
        }
        k++;
    }

    while(i<=leftEnd){
        temp[k++] = arr[i++];
    }

    while(j<=rightEnd){
        temp[k++] = arr[j++];
    }

    k=0;
    int l=leftStart;

    for(;k<size; k++){
        arr[l++] = temp[k];
    }

    delete[] temp;
    temp = NULL;

}
template<typename T>
void mergeSort(T* arr, int start, int end){

    if(start<end){
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, mid+1, end);
    }

}


// SEARCHING ALGOS

// *************** 1
template<typename T>
bool binarySearch(const T* arr, int size, int key){
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

// *************** 2
template<typename T>
bool linearSearch(const T* arr, int size, int key){

    for(int i=0; i<size; i++){
        if(arr[i] == key){
            return true;
        }
    }

    return false;
}


// *************** MISCELLENEOUS
template<typename T>
T findKthLargest(const T* arr, int n, int k){

    int i=0, count=0;
    T KthElement;

    for(i=0; i<n; i++){
        
        for(int j=0; j<n; j++){
            if(arr[j] < arr[i]){
                count++;
            }
        }

        if(count == (n-k)){
            KthElement = arr[i];
            break;
        }
        count=0;
    }

    return KthElement;
}


