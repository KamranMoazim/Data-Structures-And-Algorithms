#include<iostream>
#include<cmath>
#include <typeinfo>

#include"functions.cpp"

using namespace std;


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

void mergeSortTest(){

    int* arr = new int[5];
    int j;

    for(int i=0; i<5; i++){
        cout<<"Num "<<i+1<<" : ";
        cin>>j;
        arr[i]=j;
    }

    printArray(arr, 5);

    mergeSort(arr, 0, 4);

    printArray(arr, 5);
}


void quickSortTest(){

    int* arr = new int[5];
    int j;

    for(int i=0; i<5; i++){
        cout<<"Num "<<i+1<<" : ";
        cin>>j;
        arr[i]=j;
    }

    printArray(arr, 5);

    quickSort(arr, 0, 4);

    printArray(arr, 5);
}


int main(){

    // selectionSortTest();  
    // insertionSortTest();
    // bubbleSortTest();  
    // mergeSortTest();
    quickSortTest();

    return 0;
}
