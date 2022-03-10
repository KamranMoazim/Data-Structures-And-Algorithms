//MUHAMMAD ALI
//BCSF20M033
#define _CRT_SECURE_NO_WARNINGS
#include"MyString.h"
#include<iostream>
#include<cstring>
using namespace std;

//Function#1

MyString::MyString()
{
	str = nullptr;
	length = 0;
}
//Function 2

MyString::MyString(const char* ptr)
{
	if (ptr != nullptr)
	{
		length = strlen(ptr);
		str = new char[length + 1];
		strcpy(str, ptr);
	}
	else
	{
		str = nullptr;
	}
}
//Function 3

MyString::~MyString()
{
	if (str != nullptr)
	{
		delete[]str;
		str = nullptr;
	}
}
//Function 4

const char* MyString::display()const
{
	return str;
}
//Function 5

const int MyString::getLength()const
{
	return length;
}

//Function 6

MyString::MyString(const MyString& obj)
{
	if (obj.str != nullptr)
	{
		length = obj.length;
		str = new char[length + 1];
		strcpy(str, obj.str);
	}
}
//Function 7

const MyString& MyString::operator =(const MyString& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	else
	{ 
		if (str != nullptr)
		{
			delete[]str;
			str = nullptr;
			length = 0;
		}

		if (rhs.str != nullptr)
		{
			length = rhs.length;
			str = new char[length + 1];
			strcpy(str, rhs.str);
		}
		else
		{
			str = nullptr;
			length = 0;
		}
		return *this;
	}
}

//Function 8


ostream& operator << (ostream& out, const MyString& rhs)
{
	out << rhs.str;
	return out;
}

//Function 9

MyString MyString::operator + (const MyString& rhs)const
{
	MyString temp;
	temp.length = length + rhs.length;
	temp.str = new char[temp.length + 1];
	for (int i = 0; i < length; i++)
	{
		temp.str[i] = str[i];
	}
	for (int i = length, j = 0; i < temp.length; i++, j++)
	{
		temp.str[i] = rhs.str[j];
	}
	temp.str[temp.length] = '\0';

	return temp;
}

//Function 10

bool MyString::operator==(const MyString& rhs)const
{
	bool flag = true;
		if (length == rhs.length)
		{
			for (int i = 0; i < length; i++)
			{
				if (str[i] != rhs.str[i])
				{
					flag = false;
					break;
				}
				else
				{
					flag = true;
				}
			}
		}
		else
		{
			flag=false;
		}

		if (flag == true)
		{
			return true;
		}
		else
		{
			return false;
		}
}

//Function 11

bool MyString::operator< (const MyString& rhs)const
{
	bool flag = true;
	int small = 0;
	if (this == &rhs)
	{
		return false;
	}
	else
	{
		if (length > rhs.length)
		{
			small = rhs.length;
		}
		else
		{
			small = length;
		}
		for (int i = 0; i < small; i++)
		{
			if (str[i] > rhs.str[i])
			{
				flag = false;
				break;
			}
			else
			{
				flag = true;
			}
		}
		if (flag == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
}

//Function 12


bool MyString::operator<= (const MyString& rhs)const
{
	bool flag = true;
	if (this == &rhs)
	{
		return true;
	}
	else
	{
		int small;
		if (length > rhs.length)
		{
			small = rhs.length;
		}
		else
		{
			small = length;
		}

		for (int i = 0; i < small; i++)
		{
			if (str[i] > rhs.str[i])
			{
				flag = false;
				break;
			}
			else
			{
				flag = true;
			}
		}
		if (flag == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

//Function 13
const MyString& MyString::operator+= (const MyString& rhs)
{
	char* temp;
	temp = new char[length + rhs.length + 1];
	int len = length + rhs.length;

	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	for (int i = length, j = 0; i < len; i++, j++)
	{
		temp[i] = rhs.str[j];
	}
	temp[len] = '\0';
	*this = temp;
	delete[]temp;
	return *this;

}
//Function 14

void MyString::setStr(const char* temp)
{
	if (str != nullptr)
	{
		delete[]str;
		length = 0;
	}

	if (temp != nullptr)
	{
		length = strlen(temp);
		str = new char[length + 1];
		strcpy(str, temp);
	}
	else
	{
		str = nullptr;
		length = 0;
	}
}
//Function 15
MyString::operator int()
{
	int conversion = 0;
	int num = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] > 47 && str[i] < 58)
		{
			conversion = conversion * 10;
			num = str[i];
			num = num - 48;
			conversion += num;
		}
		else
		{
			conversion = 0;
			break;
		}
	}
	return conversion;
}

//Function 16

MyString::operator char* ()
{
	char* temp;
	temp = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	temp[length] = '\0';
	return temp;
}
//Function 17

MyString& MyString:: operator ++ ()
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
		}
		else
		{
			str[i] = str[i];
		}
	}

	return *this;
}


//Function 18

istream& operator >> (istream& in, MyString& rhs)
{
	if (rhs.str != nullptr)
	{
		delete[]rhs.str;
		rhs.length = 0;
	}

	rhs.length = 100;
	rhs.str = new char[rhs.length + 1];
	in.getline(rhs.str, rhs.length);
	cout << endl;
	return in;
}