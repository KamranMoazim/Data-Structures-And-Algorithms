#pragma once

#include "class.h"
#include<iostream>

using namespace std;


void swap(int& a, int& b){
    // cout<<"swapping "<<a<<" with "<<b<<endl;
    int t = a;
    a = b;
    b = t;
}








MaxHeap::MaxHeap(int n){
    maxSize = n;
    arr = new int[maxSize+1];
    currentSize = 0;
}


MaxHeap::MaxHeap(const MaxHeap& comingHeap){
    arr = new int [comingHeap.maxSize];
    maxSize = comingHeap.maxSize;
    currentSize = comingHeap.currentSize;
    for(int i=1; i<currentSize; i++){
        arr[i] = comingHeap.arr[i];
    }
}


MaxHeap::~MaxHeap(){
    delete[] arr;
    arr = NULL;
}


bool MaxHeap::isFull(){
    return maxSize == currentSize ? true : false;
}


bool MaxHeap::isEmpty(){
    return currentSize == 0 ? true : false;
}



bool MaxHeap::insert(int val){
    if(isFull()){
        return false;
    } else {

        currentSize = currentSize + 1;
        int i = currentSize;
        while(i>1 && val>arr[i/2]){
            // cout<<" i : "<<i<<" replacing arr[i] : "<<arr[i]<<" with arr[i/2] : "<<arr[i/2]<<" val : "<<val<<endl;
            arr[i] = arr[i/2];
            i = i/2;
        }
        arr[i] = val;

        return true;
    }
}



bool MaxHeap::removeMax(int& val){

    if(isEmpty()){
        return false;
    } else {

        val = arr[1];
        arr[1] = arr[currentSize];
        currentSize = currentSize - 1;

        bool flag = true;
        int i = 1;
        int left;
        int right;
        int largest;

        // cout<<"currentSize : "<<currentSize<<endl;

        while(flag==true && 2*i<=currentSize){

            largest = i;
            left = 2*i;
            right = 2*i + 1;

            // cout<<"largest : "<<largest<<" left : "<<left<<" right : "<<right<<endl;

            if(left <= currentSize && arr[left] > arr[largest]){
                // cout<<"arr[left] : "<<arr[left]<<" arr[largest] : "<<arr[largest]<<endl;
                largest = left;
            }

            if(right <= currentSize && arr[right] > arr[largest]){
                // cout<<"arr[right] : "<<arr[right]<<" arr[largest] : "<<arr[largest]<<endl;
                largest = right;
            }

            if(largest == i){
                flag = false;
            } else {
                swap(arr[i], arr[largest]);
                i = largest;
            }

        }

        return true;
    }
}



void MaxHeap::heapify(int i){

    bool flag = true;
    int left;
    int right;
    int largest;

    while(flag==true && 2*i<=currentSize){

        largest = i;
        left = 2*i;
        right = 2*i + 1;

        // cout<<"largest : "<<largest<<" left : "<<left<<" right : "<<right<<endl;

        if(left <= currentSize && arr[left] > arr[largest]){
            // cout<<"arr[left] : "<<arr[left]<<" arr[largest] : "<<arr[largest]<<endl;
            largest = left;
        }

        if(right <= currentSize && arr[right] > arr[largest]){
            // cout<<"arr[right] : "<<arr[right]<<" arr[largest] : "<<arr[largest]<<endl;
            largest = right;
        }

        if(largest == i){
            flag = false;
        } else {
            swap(arr[i], arr[largest]);
            i = largest;
        }

    }

}



void MaxHeap::buildHeap(int* a, int n){

    if(arr != NULL){
        delete[] arr;
        arr = NULL;
    }

    arr = new int[n+1];
    maxSize = n;
    currentSize = n;

    for(int i=0; i<=n; i++){
        arr[i+1] = a[i];
    }

    for(int i=currentSize/2; i>=1; i--){
        // cout<<"here"<<endl;
        heapify(i);
    }
    
}