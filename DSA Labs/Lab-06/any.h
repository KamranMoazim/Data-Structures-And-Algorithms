#pragma once

#include<iostream>

using namespace std;


class Book {
private:
    string title;
    string author;
public:
    void show();
    void setTitle(string t);
    void setAuthor(string a);
};


class Fiction : public Book {
private:
    int level;
public:
    void setLevel(int i, string t, string a);
    void show();
};


class NonFiction : public Book {
private:
    int pages;
public:
    void setPages(int p, string t, string a);
    void show();
};