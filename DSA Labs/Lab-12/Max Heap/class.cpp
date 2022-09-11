#pragma once

#include "class.h"
#include<iostream>

using namespace std;

template <typename T>
void swap(T& a, T& b){
    // cout<<"swapping "<<a<<" with "<<b<<endl;
    T t = a;
    a = b;
    b = t;
}







template <typename T>
MaxHeap<T>::MaxHeap(int n){
    maxSize = n;
    arr = new T[maxSize+1];
    currentSize = 0;
}

template <typename T>
MaxHeap<T>::MaxHeap(const MaxHeap<T>& comingHeap){
    arr = new T [comingHeap.maxSize];
    maxSize = comingHeap.maxSize;
    currentSize = comingHeap.currentSize;
    for(int i=1; i<currentSize; i++){
        arr[i] = comingHeap.arr[i];
    }
}


template <typename T>
MaxHeap<T>::~MaxHeap(){
    delete[] arr;
    arr = NULL;
}

template <typename T>
bool MaxHeap<T>::isFull(){
    return maxSize == currentSize ? true : false;
}

template <typename T>
bool MaxHeap<T>::isEmpty(){
    return currentSize == 0 ? true : false;
}


template <typename T>
bool MaxHeap<T>::insert(T val){
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


template <typename T>
bool MaxHeap<T>::removeMax(T& val){

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
                // swap(arr[i], arr[largest]);
                T t = arr[i];
                arr[i] = arr[largest];
                arr[largest] = t;
                i = largest;
            }

        }

        return true;
    }
}



template <typename T>
void MaxHeap<T>::heapify(int i){

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
            // swap(arr[i], arr[largest]);
            T t = arr[i];
            arr[i] = arr[largest];
            arr[largest] = t;
            i = largest;
        }

    }

}


template <typename T>
void MaxHeap<T>::buildHeap(T* a, int n){

    if(arr != NULL){
        delete[] arr;
        arr = NULL;
    }

    arr = new T[n+1];
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