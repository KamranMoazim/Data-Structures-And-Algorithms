#include<iostream>

// #include"Book.h"
#include"any.cpp"

using namespace std;


int main(){

    ////////////////////////////////////////////////////////////////
    // TESTING of SIMPLE BOOK
    Book b1;
    b1.setTitle("C++");
    b1.setAuthor("Robert Lafore");
    b1.show();

    // TESTING of SIMPLE FICTION
    Fiction f1;
    f1.setLevel(1, "C++", "Robert Lafore");
    f1.show();

    // TESTING of SIMPLE NON-FICTION
    // NonFiction nf1;
    // nf1.setPages(438, "C++", "Robert Lafore");
    // nf1.show();

    // ************ TESTING As per describe in LAB pdf ************  
    // string title, author;
    // int level, pages;
    // Fiction arr1[5];
    // NonFiction arr2[5];
    // for(int i=0; i<5; i++){
        
    //     cout<<"Enter Book Title for book "<<i+1<<" : ";
    //     getline(cin, title);
    //     cout<<"Enter Author Name for book "<<i+1<<" : ";
    //     getline(cin, author);
    //     cout<<"Enter Level book "<<i+1<<" : ";
    //     cin>>level;
    //     cin.ignore();
    //     arr1[i].setLevel(level, title, author);
    // }
    // for(int i=0; i<5; i++){
    //     arr1[i].show();
    // }

    // for(int i=0; i<5; i++){
    //     cout<<"Enter Book Title for book "<<i+1<<" : ";
    //     getline(cin, title);
    //     cout<<"Enter Author Name for book "<<i+1<<" : ";
    //     getline(cin, author);
    //     cout<<"Enter Number of Pages in book "<<i+1<<" : ";
    //     cin>>pages;
    //     cin.ignore();
    //     arr2[i].setPages(pages, title, author);
    // }
    // for(int i=0; i<5; i++){
    //     arr2[i].show();
    // }



    return 0;
}
