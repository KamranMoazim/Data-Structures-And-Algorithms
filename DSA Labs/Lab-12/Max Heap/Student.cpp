#pragma once

#include <iostream>
#include <cmath>

using namespace std;


class StudentMaxHeap;



class Student {
private:
    int rollNo;
    double cgpa;
public:
    friend class StudentMaxHeap;
    Student(){}
    Student(int r, double c){
        rollNo = r;
        cgpa = c;
    }
    bool operator != (const Student& st){
        return cgpa != st.cgpa;
    }
    bool operator == (const Student& st){
        return cgpa == st.cgpa;
    }
    bool operator > (const Student& st){
        return cgpa > st.cgpa;
    }
    bool operator < (const Student& st){
        return cgpa < st.cgpa;
    }
    bool operator >= (const Student& st){
        return cgpa >= st.cgpa;
    }
    bool operator <= (const Student& st){
        return cgpa <= st.cgpa;
    }
    Student operator = (const Student& st){

        if(this != &st){
            rollNo = st.rollNo;
            cgpa = st.cgpa;
        }

        return *this;
    }
    friend ostream & operator << (ostream &out, const Student &st){
        out<<"---- Roll No : "<<st.rollNo<<" ";
        out<<"---- CGPA : "<<st.cgpa<<endl;
        return out;
    }
};


class StudentMaxHeap {
private:
    Student* st; // Array of students which will be arranged like a Max Heap
    int currSize; // Current number of students present in the heap
    int maxSize; // Maximum number of students that can be stored in the heap
public:
    StudentMaxHeap (int size){ // Constructor
        st = new Student[size+1];
        currSize = 0;
        maxSize = size;
    } 
        
    ~StudentMaxHeap(){ // Destructor
        delete[] st;
        st = NULL;
    }
    bool isEmpty(){ // Checks whether the heap is empty or not
        return currSize == 0 ? true : false;
    }
    bool isFull(){ // Checks whether the heap is full or not
        return maxSize == currSize ? true : false;
    }
    bool insert (int rollNo, double cgpa){
        if(isFull()){
            return false;
        } else {
            
            Student std1(rollNo, cgpa);


            currSize = currSize + 1;
            int i = currSize;
            while(i>1 && std1>st[i/2]){
                st[i] = st[i/2];
                i = i/2;
            }


            st[i] = std1;

            int left = 2*i;
            int right = 2*i + 1;
            int largest = i;

            
            if( st[left].rollNo > st[i].rollNo ){
                largest = left;
            } 
            
            if(st[right].rollNo > st[i].rollNo ) {
                largest = right;
            }

            Student s = st[largest];
            st[largest] = st[i];
            st[i] = s;


            return true;
        }
    }
    bool removeBestStudent (int& rollNo, double& cgpa){

        if(isEmpty()){
            return false;
        } else {

            rollNo = st[1].rollNo;
            cgpa = st[1].cgpa;
            st[1] = st[currSize];
            currSize = currSize - 1;

            bool flag = true;
            int i = 1;
            int left;
            int right;
            int largest;


            while(flag==true && 2*i<=currSize){

                largest = i;
                left = 2*i;
                right = 2*i + 1;


                if(left <= currSize && st[left] > st[largest]){
                    largest = left;
                }

                if(right <= currSize && st[right] > st[largest]){
                    largest = right;
                }

                if(largest == i){
                    flag = false;
                } else {
                    Student t = st[i];
                    st[i] = st[largest];
                    st[largest] = t;
                    i = largest;
                }

            }

            return true;
        }
    }

    void levelOrder(){
        for(int i=1; i<=currSize; i++){
            cout<<st[i]<<endl;
        }
    }
    int height(){
        return log2(currSize)+1;
    }

};



