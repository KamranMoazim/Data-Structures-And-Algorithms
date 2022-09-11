#pragma once

#include <iostream>

using namespace std;



class Student {
private:
    int rollNo;
    string name;
    double cgpa;
public:
    Student(){}
    Student(int r, string n, double c){
        rollNo = r;
        name = n;
        cgpa = c;
    }
    bool operator != (const Student& st){
        return rollNo != st.rollNo;
    }
    bool operator == (const Student& st){
        return rollNo == st.rollNo;
    }
    bool operator > (const Student& st){
        return rollNo > st.rollNo;
    }
    bool operator < (const Student& st){
        return rollNo < st.rollNo;
    }
    bool operator >= (const Student& st){
        return rollNo >= st.rollNo;
    }
    bool operator <= (const Student& st){
        return rollNo <= st.rollNo;
    }
    Student operator = (const Student& st){

        if(this != &st){
            rollNo = st.rollNo;
            name = st.name;
            cgpa = st.cgpa;
        }

        return *this;
    }
    friend ostream & operator << (ostream &out, const Student &st){
        out<<"Roll No : "<<st.rollNo<<" ";
        out<<"---- Name : "<<st.name<<" ";
        out<<"---- CGPA : "<<st.cgpa<<endl;
        return out;
    }
};