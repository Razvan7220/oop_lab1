#include<iostream>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList a;
	a.Init();
	a.Add(12);
	a.Add(9);
	a.Add(89);
	a.Add(0);
	a.Add(-21);
	a.Sort();
	a.Print();

	system("pause");
	return 0;

}