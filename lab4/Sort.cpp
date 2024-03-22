#include "Sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdarg.h>
Sort::Sort(int nr, int minx, int maxx)
{
	this->size = nr;
	this->v = new int[nr];
	srand((unsigned)time(nullptr));
	for (int i = 0; i < nr; i++)
		v[i] = minx + rand() % (maxx - minx + 1);
 }
Sort::Sort(int* vec, int n)
{
	this->size = n;
	this->v = new int[n];
	for (int i = 0; i < n; i++)
		v[i] = vec[i];

}
Sort::Sort(int n, ...) {
	this->size = n;
	this->v = new int[n];
	va_list el;
	va_start(el, n);
	for (int i = 0; i < n; i++)
		v[i] = va_arg(el, int);
	va_end(el);
}
Sort::Sort(const char* c)
{
	v = new int[100];
	v = {};
	c = new char[100];
	int i = 0;
	int k=0,p=1;
	while (c[i] != '/0')
	{
		while((const char)c[i]!=',')
		{
			v[k] = v[k] * p + (c[i] - '0');
			p *= 10;
			i++;
		}
		p = 1;
		k++;
		i++;
	}
	this->size = k-1;
}
Sort::Sort() : v(new int[5]{1,2,3,5,4}) {
	
		//v={1,2,3,5,4}
	this->size = 5;
}

void Sort::BubbleSort(bool ascendent)
{
	int n = this->size;
	int ok = 0;
	while(ok != 1)
	{
		ok = 1;
		for(int i=0;i<n-1;i++)
			if (!ascendent)
			{
				if (v[i] > v[i + 1])
				{
					ok = 0;
					std::swap(v[i], v[i + 1]);
				}
			}
			else
				if (v[i] < v[i + 1])
				{
					ok = 0;
					std::swap(v[i], v[i + 1]);
				}
	}

}
void Sort::InsertSort(bool ascendent )
{
	if (!ascendent)
	{
		int mini;
		for (int i = 0; i < this->size-1; i++)
		{
			mini = v[i];
			for (int j = i + 1; j < this->size ; j++)
			{
				if (v[j] < mini)
				{
					mini = v[j];
					std::swap(v[i], v[j]);
				}
			}
		}
	}
	else
	{
		int mini;
		for (int i = 0; i < this->size-1; i++)
		{
			mini = v[i];
			for (int j = i + 1; j < this->size ; j++)
			{
				if (v[j] > mini)
				{
					mini = v[j];
					std::swap(v[i], v[j]);
				}
			}
		}
	}
}
void Sort::QuickSort(bool ascendent) {
	
	int* coada1,* coada2;
	coada1 = new int[50];
	coada2 = new int[40];
	int k = 0;
		int st=0, dr=this->size-1;
		while (st < dr)
		{
			//pivotul este inițial v[st]
			int m = (st + dr) / 2;
			int aux = v[st];
			v[st] = v[m];
			v[m] = aux;
			int i = st, j = dr, d = 0;
			while (i < j)
			{
				if (v[i] > v[j])
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
					d = 1 - d;
				}
				i += d;
				j -= 1 - d;
			}
			dr = i - 1;

			//coada1[k++] = i - 1;
			//coada2[k++] = i + 1;
		}
			//QuickSort(v, st, i - 1);
			//QuickSort(v, i + 1, dr);

	
}
int Sort::GetElementsCount() {
	return this->size;
}
int Sort::GetElementFromIndex(int i) {
	return this->v[i];
}
void Sort::Print()
{
	for (int i = 0; i < this->size; i++)
		std::cout << this->v[i] << " ";
	std::cout << '\n';
}
Sort::~Sort()
{
	delete[] v;
}