#pragma once

#include<iostream>

using namespace std;



int value(string name){
    int temp = 0;
    for (int i=0; i < name.length(); i++)
    {
        temp = temp + name[i];
    }
    return temp;
}


class HashTable
{
private:
    string *table; // Dynamic array of strings to hold names
    int size; // Total number of slots in the table
    int curSize; // Current number of elements present in the table
public:
    HashTable (int size){
        table = new string[size];
        this->size = size;
        curSize = 0;
        for(int i=0; i<size; i++){
            table[i] = "NO"; // NO stands for Not-Occupied
        }
    }
    ~HashTable (){
        delete[] table;
        table = NULL;
    }
    bool isEmpty (){
        return curSize == 0 ? true : false;
    }
    bool isFull (){
        return curSize == size-1 ? true : false;
    }
    double loadFactor (){
        // Calculates & returns the load factor of the hash table (curSize/size)
        return (curSize/size*1.0);
    }
    bool insert (string name){
        if(!isFull()){
            int index = value(name) % size;
            if(table[index] == "NO" || table[index] == "RO"){
                table[index] = name;
                curSize++;
                return true;
            } else {
                int tempIndex = (index + 1) % size;
                bool locationFoundForInsertion = false;
                while((tempIndex != index && locationFoundForInsertion != true)){
                    if(table[tempIndex] == "NO" || table[tempIndex] == "RO"){
                        curSize++;
                        table[tempIndex] = name;
                        locationFoundForInsertion = true;
                    }
                    tempIndex = (tempIndex + 1) % size;
                }

                return locationFoundForInsertion;
            }
        } else {
            return false;
        }
    }

    bool search (string name){
        if(isEmpty()){
            return false;
        } else {
            int index = value(name) % size;
            if(table[index] == name){
                return true;
            } else {
                bool locationFound = false;
                int tempIndex = (index + 1) % size;
                while((tempIndex != index && locationFound != true)){
                    if(table[tempIndex] == name){
                        locationFound = true;
                    } else if(table[tempIndex] == "NO"){
                        tempIndex = index; // means not found
                    }
                    tempIndex = (tempIndex + 1) % size;
                }

                return locationFound;
            }
        }
    }

    bool remove(string name){
        if(isEmpty()){
            return false;
        } else {
            int index = value(name) % size;
            if(table[index] == name){
                table[index] = "RO";  // RO stands for Removed
                curSize--;
                return true;
            } else {
                bool locationFound = false;
                int tempIndex = (index + 1) % size;
                while((tempIndex != index && locationFound != true)){
                    if(table[tempIndex] == name){
                        curSize--;
                        table[tempIndex] = "RO";
                        locationFound = true;
                    } else if(table[tempIndex] == "NO"){
                        tempIndex = index; // means not found
                    }
                    tempIndex = (tempIndex + 1) % size;
                }

                return locationFound;
            }
        }
    }
    void display (){
        for(int i=0; i<size; i++){
            if(table[i] == "NO" || table[i] == "RO"){
                cout<<"\t"<<"EMPTY"<<endl;
            } else {
                cout<<"\t"<<table[i]<<endl;
            }
        }
    }
};