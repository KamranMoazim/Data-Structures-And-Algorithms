#pragma once

#include<iostream>

using namespace std;




// *********** 1
void printZigZag(int* arr, int start, int end) {

    if(start < end){
        cout<<arr[start]<<"\t"<<arr[end]<<"\t";
        start++;
        end--;
    } else if(start == end){
        cout<<arr[start]<<"\t";
        start++;
    } else {
        cout<<endl;
        return;
    }

    printZigZag(arr, start, end);    

}


// *********** 2
void printChar(char ch, int n){
    // cout<<ch<<"\t";
    cout<<ch;
    n--;
    if(n <= 0){
        cout<<endl;
        return;
    }
    printChar(ch, n);
}


// *********** 3
void printPattern1(char ch, int n){
    printChar(ch, n);
    n--;
    if(n <= 0){
        cout<<endl;
        return;
    }
    printPattern1(ch, n);
}


// *********** 4
void printPattern2 (char ch, int n){

    if(n <= 0){
        return;
    }
    
    int k=n-1;
    printPattern2(ch, k);
    printChar(ch, n);
}


// *********** 5
void printVertical (int val) {
    int remainder = val % 10;
    if(val == 0){
        return;
    }
    printVertical(val/10);
    cout<<remainder<<endl;
}


// *********** 6
int product(int a, int b){
    if(a == 1){
        return b;
    }
    a--;
    return product(a, b)+b;
}


// *********** 7   {2,4,9,3,5,10};
int findLargestIndex(int* arr, int start, int end) {

    int index=end;

    if(start < end){
        int gettingIndex = findLargestIndex(arr, start+1, end);
        if(arr[start] > arr[gettingIndex]){
            index = start;
        } else {
            index = gettingIndex;
        }
    }
            
    return index;
}
int findSmallestValue(int* arr, int start, int end) {

    int val=arr[end];

    if(start < end){
        int gettingVal = findSmallestValue(arr, start+1, end);
        if(arr[start] < gettingVal){
            val = arr[start];
        } else {
            val = gettingVal;
        }
    }
            
    return val;
}


// *********** 8
int linearSearchUpdated (int* arr, int start, int end, int key) {
    int count = 0;

    if(start > end){
        return 0;
    }

    if(arr[start++] == key){
        count++;
    }

    return count + linearSearchUpdated(arr, start, end, key);
}


// *********** 9
int sumDigits (int num) {

    if(num < 0){
        num = -num;
    }

    int remainder=num%10;;
    num = num/10;

    if(num == 0){
        return remainder;
    }

    return (remainder + sumDigits(num));
}


// *********** 10
void decimalToBinary (int num) {  // 6   3   1

    int remainder=num%2;   //  011
    if(num == 0){
        return;
    }
    decimalToBinary(num/2);
    cout<<remainder;
}

