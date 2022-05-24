#pragma once
#include<iostream>
template <typename T>
class Stack
{
	T* data;
	int capacity;
	int top;
	// void reSize(int newCapacity)
	// {
	// 	Stack<T> temp;
	// 	temp.data = new T[newCapacity];
	// 	temp.top = top;
	// 	int n;
	// 	n= newCapacity > capacity ? capacity : newCapacity;
	// 	for (int i = 0; i < n; i++)
	// 	{
	// 		temp.data[i] = data[i];
	// 	}
	// 	this->~Stack();
	// 	top = temp.top;
	// 	capacity = newCapacity;
	// 	data = temp.data;
	// }
public:
	Stack(int );
	Stack(const Stack<T>& s);
	Stack <T>& operator=(const Stack<T>& s);
	~Stack();
	void push(T s);
	T pop();
	bool isFull()const;
	bool isEmpty()const;
	T stackTop()const;
	int getNumberOfElements()const;
};
