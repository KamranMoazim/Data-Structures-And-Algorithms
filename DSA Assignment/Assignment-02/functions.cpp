// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon


#pragma once

#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<iomanip>

using namespace std;


// name length of bowling player
const int NAME_LENGTH = 25;


// struct as defined in the assignment
struct BowlingFigures {
    char name[NAME_LENGTH+1]; // Name of the bowler
    int wickets;              // Wickets taken by the bowler
    int runs;                 // Runs conceded by the bowler
    // to sort descending order on the basis of wickets
    bool operator > (BowlingFigures bf){
        if(wickets > bf.wickets)
            return true;
        return false;
    }
    // to sort ascending order on the basis of runs
    bool operator < (BowlingFigures bf){
        if(runs < bf.runs)
            return true;
        return false;
    }
};


// for the purpose of swapping any type (by reference)
template <typename T>
void swapper(T& a, T& b){
    T t=a;
    a=b;
    b=t;
}


// to convert string number to integer
int charToInt(string num){
    return stoi(num);
}


// SORTING ALGOS
// sortig any type using selection sort like int or ADT(< and > operators must be overloaded)
template <typename T>
void selectionSort(T* arr, int size, bool ascending = true){
    int minValIndex=0;
    for(int i=0; i<size; i++){
        minValIndex = i;
        for(int j=i+1; j<size; j++){
            if(ascending){
                if(arr[j] < arr[minValIndex]){
                    minValIndex = j;
                }
            } else {
                if(arr[j] > arr[minValIndex]){
                    minValIndex = j;
                }
            }
        }
        swapper(arr[i], arr[minValIndex]);
    }
}

// sortig any type using insertion sort like int or ADT(< and > operators must be overloaded)
template <typename T>
void insertionSort(T* arr, int size, bool ascending = true){
    T key;
    for(int i=0; i<size; i++){
        key = arr[i];
        int j = i-1;
        if(ascending){
            while(j>=0 && key < arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
        } else {
            while(j>=0 && key > arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
        }
        arr[j+1] = key;
    }
}


// here using particulary BowlingFigures type because we needed strcmp function for comparison
void bubbleSort(BowlingFigures* arr, int size){
    int i=size-1;
    while(i > 0){
        for(int j=0; j<i; j++){
            if(strcmp(arr[j].name, arr[j+1].name) > 0){
                swapper(arr[j], arr[j+1]);
            }
        }
        i--;
    }
}







// ****************************** MAIN TASKS ******************************




// this function will read player's data from file and return pointer (in case of success) 
BowlingFigures* readFromFile(char* fileName, int& count) {

    ifstream fin;
    string eachLine;
    BowlingFigures* bowlingFigures = NULL;
    count = 0;  // to return total players count of file

    fin.open(fileName, ios::in);

    if(fin.fail()){
        return bowlingFigures;   // retrun NULL if file is not opened
    } else {
        
        getline(fin, eachLine);   // getting first line which contain total count of players and storing it in variable numberOfBowlingFigures
        int numberOfBowlingFigures = charToInt(eachLine.substr(0, eachLine.find(" ")));
        bowlingFigures = new BowlingFigures[numberOfBowlingFigures];  // defining dynamic array of type BowlingFigures


        while(count<numberOfBowlingFigures){

            getline(fin, eachLine);   // this line contain name of player
            for(int i=0; i<eachLine.length(); i++){
                bowlingFigures[count].name[i] = eachLine[i];
            }
            
            getline(fin, eachLine);  // this line contain wickets and score
            bowlingFigures[count].wickets = charToInt(eachLine.substr(0, eachLine.find(" ")));
            bowlingFigures[count].runs = charToInt(eachLine.substr(eachLine.find(" ")));
            
            count++;
        }

        return bowlingFigures;   // retrun pointer of above defined array
    }    
}


// print all players wickets - runs - playerName
void printBowlingFigures(const BowlingFigures* bf, int count) {
    cout<<endl;
    for(int i=0; i<count; i++){
        cout<<setw(22)<<bf[i].wickets<<"-"<<bf[i].runs<<"\t"<<bf[i].name<<endl;
    }
    cout<<endl;
}


// sort using above defined insertionSort template algorithm
void sortBowlingFigures1(BowlingFigures* bf, int count) {

    insertionSort(bf, count, false);
    // here it is sorting in descending order on base of wickets 

    int tempCount = 0, startOfArray=0;


    for(int i=0; i<count; i++){

        // here we are counting how many players have same number of wickets, 
        // so we may later sort them on the basis of runs
        startOfArray = i; // this is the start of that inner array where players have same number of wickets
        while(i<count-1 && bf[i].wickets == bf[i+1].wickets){
            tempCount++;
            i++;
        }
        tempCount++;

        if(tempCount > 1){
            BowlingFigures* temp = &bf[startOfArray]; // getting that inner array which we wants to sort that have same number of wickets
            // here it is sorting in ascending order on base of runs
            insertionSort(temp, tempCount); // now sorting that chunk 
        }

        tempCount = 0;
    }
    
    cout<<endl;
}


// sort using above defined selectionSort template algorithm
void sortBowlingFigures2(BowlingFigures* bf, int count) {

    selectionSort(bf, count, false);
    // here it is sorting in descending order on base of wickets 


    int tempCount = 0, startOfArray=0;

    for(int i=0; i<count; i++){

        // here we are counting how many players have same number of wickets, 
        // so we may later sort them on the basis of runs
        startOfArray = i;  // this is the start of that inner array where players have same number of wickets
        while(i<count-1 && bf[i].wickets == bf[i+1].wickets){
            tempCount++;
            i++;
        }
        tempCount++;

        if(tempCount > 1){
            BowlingFigures* temp = &bf[startOfArray]; // getting that inner array which we wants to sort that have same number of wickets
            // here it is sorting in ascending order on base of runs
            selectionSort(temp, tempCount); // now sorting that chunk    
        }

        tempCount = 0;
    }
    
    cout<<endl;
}

// sort using above defined bubbleSort algorithm (this is not template as we needed strcmp in bubbleSort)
void sortByName(BowlingFigures * bf, int count) {
    bubbleSort(bf, count);
}


