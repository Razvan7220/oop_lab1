#pragma once
#include<stdio.h>
class Number
{
private:
	char* c;
	unsigned int baza;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number() {
		c = nullptr;
		baza = 0;
	}
	~Number();
//  copy/move constructor:
Number(const Number& d);
Number(const Number&& d);
	
//operatori
friend Number operator +(Number& n1, Number& n2);
friend Number operator -(Number& n1, Number& n2);

char* operator = (Number& n);
char* operator +=(Number& n);
char operator[](int i);
bool operator <(Number& n);
bool operator >(Number& n);
bool operator <=(Number& n);
bool operator >=(Number& n);
bool operator ==(Number& n);

char* operator --(int n);
char* operator --();
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
