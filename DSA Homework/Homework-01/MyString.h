//MUHAMMAD ALI
//BCSF20M033

#pragma once
#include<iostream>
using namespace std;
class MyString
{
private:
	char* str;
	int length;
public:
	MyString();
	
	MyString(const char* ptr);

	~MyString();

	const char* display()const;

	const int getLength()const;

	MyString(const MyString& obj);

	const MyString& operator = (const MyString& rhs);

	friend ostream& operator << (ostream& out, const MyString& rhs);
	

	MyString operator + (const MyString& rhs)const;

	bool operator == (const MyString& rhs)const;

	bool operator < (const MyString& rhs)const;

	bool operator <= (const MyString& rhs)const;

	const MyString& operator +=(const MyString& rhs);

	void setStr(const char* ptr);

	operator char* ();

	operator int();

	MyString& operator ++();

	friend istream& operator >> (istream& out, MyString& rhs);
};