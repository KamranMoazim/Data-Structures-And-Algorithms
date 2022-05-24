#include<iostream>
#include"Stack.h"
using namespace std;




template<typename T>
Stack<T>::Stack(int s)
{
	// data = nullptr;
	data = new T[s];
	top = 0;
	capacity = s;
}


template<typename T>
Stack<T>::Stack(const Stack<T>& s) :Stack()
{
	if (s.data != nullptr)
	{
		top = s.top;
		capacity = s.capacity;
		data = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			data[i] = s.data[i];
		}
	}
	else
	{
		return;
	}
}
template<typename T>
Stack <T>& Stack<T>:: operator=(const Stack<T>& s)
{
	if (this == &s)
	{
		return *this;
	}
	if (s.data == nullptr)
	{
		data = nullptr;
		capacity = 0;
		top = 0;

		return *this;
	}
	if (s.data != nullptr)
	{
		top = s.top;
		capacity = s.capacity;
		data = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			data[i] = s.data[i];
		}

		return *this;
	}
}
template<typename T>
Stack<T>::~Stack()
{
	delete[] data;
	data = nullptr;
	capacity = 0;
	top = 0;
}
template<typename T>
void Stack<T>:: push(T s)
{
	if (isFull())
	{
		// reSize(capacity == 0 ? 1 : capacity * 2);
		return;
	}
	data[top++] = s;
	// cout<<data[top-1]<<endl;
}
template<typename T>
T Stack<T>::pop()
{
	// if (isEmpty())
	// {
	// 	exit(0);
	// }

	// int n = capacity / 4;
	// if (top <= n)
	// {
	// 	reSize(capacity / 2);
	// }
	if (isEmpty()){
		cout<<"EMpty"<<endl;
	}
	
	// cout<<data[top]<<endl;

	return data[top--];
}
template<typename T>
bool Stack<T>::isFull()const
{
	if (top == capacity)
	{
		return true;
	}
	return false;
}
template<typename T>
bool Stack<T>:: isEmpty()const
{
	if (top == 0)
	{
		return true;
	}
	return false;
}

template<typename T>
T Stack<T>:: stackTop()const
{
	return data[top-1];
}

template<typename T>
int Stack<T>:: getNumberOfElements()const
{
	return top;
}
