#pragma once

#include<iostream>

using namespace std;


// OTHER
void swapper(int& a, int& b){
    int t=a;
    a=b;
    b=t;
}
void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl;
}


// SORTING ALGOS

void selectionSort(int* arr, int size){

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

void insertionSort(int* arr, int size){

    int key;
    for(int i=0; i<size; i++){
        key = arr[i];
        int j = i-1;

        while(j>=0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        printArray(arr, size);
    }
}

void bubbleSort(int* arr, int size){

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



// SEARCHING ALGOS
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


bool linearSearch(const int* arr, int size, int key){
    
    bool found = false;

    for(int i=0; i<size; i++){
        if(arr[i] == key){
            found = true;
        }
    }

    return found;
}


int findKthLargest(const int* arr, int n, int k){

    int i=0, count=0;
    int KthElement;

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


void bubbleSortTest(){

    int* arr = new int[5];
    int j;

    for(int i=0; i<5; i++){
        cout<<"Num "<<i+1<<" : ";
        cin>>j;
        arr[i]=j;
    }

    printArray(arr, 5);

    bubbleSort(arr, 5);

    printArray(arr, 5);
}

void insertionSortTest(){

    int* arr = new int[5];
    int j;

    for(int i=0; i<5; i++){
        cout<<"Num "<<i+1<<" : ";
        cin>>j;
        arr[i]=j;
    }

    printArray(arr, 5);

    insertionSort(arr, 5);

    // printArray(arr, 5);
}

void selectionSortTest(){

    int* arr = new int[5];
    int j;

    for(int i=0; i<5; i++){
        cout<<"Num "<<i+1<<" : ";
        cin>>j;
        arr[i]=j;
    }

    printArray(arr, 5);

    selectionSort(arr, 5);

    printArray(arr, 5);
}
