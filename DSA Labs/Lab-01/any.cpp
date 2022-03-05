#pragma once

#include "any.h"
#include<iostream>

using namespace std;


// //////////////////////// Book ///////////////////////////////////
void Book::show(){
    cout<<"Title of Book is "<<title<<", Author of Book is "<<author<<"."<<endl;
}
void Book::setTitle(string t){
    title = t;
}
void Book::setAuthor(string a){
    author = a;
}


// //////////////////////// Fiction ///////////////////////////////////
void Fiction::setLevel(int i, string t, string a){
    level = i;
    setTitle(t);
    setAuthor(a);
}
void Fiction::show(){
    cout<<"Level of Book is "<<level<<", ";
    Book::show();
}


// //////////////////////// NonFiction ///////////////////////////////////
void NonFiction::setPages(int p, string t, string a){
    pages = p;
    setTitle(t);
    setAuthor(a);
}
void NonFiction::show(){
    cout<<"Book has "<<pages<<" pages, ";
    Book::show();
}
