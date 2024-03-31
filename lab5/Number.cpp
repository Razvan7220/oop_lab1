#include "Number.h"
#include<cstring>
#include<iostream>
using namespace std;
 Number::Number(const char* sir, int base) {
	this->baza = base;
	this->c = new char(strlen(sir) + 1);
	memcpy(c, sir, strlen(sir) + 1);
}
 Number::Number(const Number& d)
 {
	this->baza = d.baza;
	this->c = nullptr;
	this->c = d.c;
 }
 Number::Number(const Number&& d)
 {
	 this->baza = d.baza;
	 this->c = new char(strlen(d.c) + 1);
	 memcpy(this->c, d.c, strlen(d.c) + 1);
 }
 //fuctii ajutatoare:
 int in_baza_10(const char* c, int base)
 {
	 int number = 0, i = strlen(c) - 1, len = i, poww = 1;
	 while (i >= 0)
	 {
		 if (c[i] >= 'A' && c[i] <= 'F')
			 number += (c[i] - '7') * poww;
		 else
			 number += (c[i] - '0') * poww;
		 i--;
		 poww = poww * base;
	 }
	 return number;
 }
 char* din_baza_10(int nr, int base)
 {
	 char* sir;
	 sir = new char(101);
	 if (nr == 0)
	 {
		 sir[0] = '0';
		 sir[1] = '\0';
		 return sir;
	 }
	 int rest, i = 0;
	 while (nr != 0)
	 {
		 rest = nr % base;
		 if (rest < 10)
			 sir[i++] = (char)(rest + '0');
		 else
			 sir[i++] = (char)(rest + '7');
		 nr = nr / base;
	 }
	 sir[i] = '\0';
	 int len = strlen(sir) - 1;
	 for (int j = 0; j <= len / 2; j++)
		 swap(sir[j], sir[len - j]);
	 return sir;
 } 
 Number operator + (Number& n1, Number& n2)
 {
	 Number suma;
	 if (n1.baza > n2.baza)
		 suma.baza = n1.baza;
	 else
		 suma.baza = n2.baza;
	 int n1_aux, n2_aux, suma_aux;
	 n1_aux = in_baza_10(n1.c, n1.baza);
	 n2_aux = in_baza_10(n2.c, n2.baza);
	 suma_aux = n1_aux + n2_aux;
	 suma.c = din_baza_10(suma_aux,suma.baza);
	 return suma;
 }
 Number operator -(Number& n1, Number& n2)
 {
	 Number suma;
	 if (n1.baza > n2.baza)
		 suma.baza = n1.baza;
	 else
		 suma.baza = n2.baza;
	 int n1_aux, n2_aux, suma_aux;
	 n1_aux = in_baza_10(n1.c, n1.baza);
	 n2_aux = in_baza_10(n2.c, n2.baza);
	 suma_aux = n1_aux - n2_aux;
	 suma.c = din_baza_10(suma_aux, suma.baza);
	 return suma;
 }
 char* Number::operator = (Number& n)
 {
	 this->baza = n.baza;
	 this->c = n.c;
	 return c;
 }
 char* Number::operator +=(Number& n)
 {
	 int num1 = in_baza_10(c, baza);
	 int num2 = in_baza_10(n.c, n.baza);
	 num1 += num2;
	 baza = max(baza, n.baza);
	 c = din_baza_10(num1, baza);
	 return c;
 }
 char Number:: operator[](int i)
 {
	 return c[i];
 }
 bool Number :: operator > (Number& n)
 {
	 int num1 = in_baza_10(c, baza);
	 int num2 = in_baza_10(n.c, n.baza);
	 return num1 > num2;
 }
 bool Number :: operator < (Number& n)
 {
	 int num1 = in_baza_10(c, baza);
	 int num2 = in_baza_10(n.c, n.baza);
	 return num1 < num2;
 }
 bool Number :: operator <= (Number& n)
 {
	 int num1 = in_baza_10(c, baza);
	 int num2 = in_baza_10(n.c, n.baza);
	 return num1 <= num2;
 }
 bool Number :: operator >= (Number& n)
 {
	 int num1 = in_baza_10(c, baza);
	 int num2 = in_baza_10(n.c, n.baza);
	 return num1 >= num2;
 }
 bool Number :: operator == (Number& n)
 {
	 int num1 = in_baza_10(c, baza);
	 int num2 = in_baza_10(n.c, n.baza);
	 return num1== num2;
 }
 char* Number:: operator -- (int n)
 {
	 c[strlen(c) - 1]='\0';
	 return c;
 }
 char* Number :: operator --()
 {
	 for (int i = 0; i < strlen(c); i++)
		 c[i] = c[i + 1];
	 return c;
 }
int Number::GetDigitsCount()
{
	int i = 0;
	while (this->c[i] != '\0')
		i++;
	return i - 1;
}
void Number::Print()
{
	cout << c <<'\n';
}
void Number::SwitchBase(int n) {
	this->baza = n;
}
int Number::GetBase() {
	return this->baza;
}
Number::~Number() {
	delete c;
	c = nullptr;
}