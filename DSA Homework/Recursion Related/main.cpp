#include<iostream>
#include<cmath>

#include"any.cpp"

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



int main(){

    // ************ 1
    // int arr[] = {3,6,2,1,4};
    // int arr2[] =  {7,1,9,3,5,2};
    // printZigZag(arr, 0, 4);
    // printZigZag(arr2, 0, 5);


    // ************ 2
    // printChar('Z',5);


    // ************ 3
    // printPattern1('*',4);


    // ************ 4
    // printPattern2('#',6);


    // ************ 5
    // printVertical(375);


    // ************ 6
    // cout<<product(3, 4);
    // cout<<product(10, 10);
    // cout<<endl;


    // ************ 7
    // int arr2[] =  {15,2,7,39,1,4};
    // cout<<"Index of Largest index is : "<<findLargestIndex(arr2, 0, 5);
    // cout<<endl;
    // cout<<"Smallest Value is : "<<findSmallestValue(arr2, 0, 5);
    // cout<<endl;


    // ************ 8
    // int arr2[] =  {2,1,0,3,5,8};
    // cout<<linearSearchUpdated(arr2, 0, 5, 7);
    // cout<<endl;


    // ************ 9
    // cout<<sumDigits(357);
    // cout<<sumDigits(0);
    // cout<<sumDigits(-123);
    // cout<<endl;


    // ************ 10
    // decimalToBinary(6);
    // cout<<"\t";
    // decimalToBinary(84);
    // cout<<"\t";
    // decimalToBinary(10);
    // cout<<"\t";
    // decimalToBinary(25);
    // cout<<"\t";
    // cout<<endl;



    return 0;
}
