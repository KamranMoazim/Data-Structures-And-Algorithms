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

