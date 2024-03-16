#include "Math.h"
#include<iostream>
#include<stdarg.h>
#include<string.h>
using namespace std;
int Math :: Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b) {
	return static_cast<int>(a + b);
}
int Math::Add(double a, double b, double c)
{
	return (int)(a + b + c);
}
int Math::Mul(int a, int b) {
	return a * b;
}
int Math::Mul(int a, int b, int c) {
	return a * b* c;
}
int Math::Mul(double a, double b)
{
	return(int) (a * b);
}
int Math::Mul(double a, double b, double c)
{
	return (int)(a * b * c);
}
int Math::Add(int count, ...)
{
	int rez = 0;
	va_list el;
	va_start (el, count);
	for (int i = 1; i <= count; i++)
	{
		rez += va_arg(el, int);
	}
	va_end(el);
	return rez;
}

char* Math::Add(const char * s1, const char* s2)
{
	if (s1 == nullptr || s2 == nullptr)
		return nullptr;
	int l1 = strlen(s1) - 1, l2 = strlen(s2) - 1,c=0,sum=0,k=0;
	char * rez = new char[l1 + l2 + 2];
	while (l1 >= 0 || l2 >= 0 || c != 0)
	{
		sum = c;
		if (l1 >= 0)
			sum = sum + (s1[l1--] - '0');
		if (l2 >= 0)
			sum = sum + (s2[l2--] - '0');

		c = sum / 10;
		rez[k++] ='0'+ sum % 10;

	}
	for (int i = 0; i < strlen(rez) / 2; i++)
		swap(rez[i], rez[strlen(rez) - 1 - i]);
	return  rez;
}