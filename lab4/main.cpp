#include<iostream>
#include"Sort.h"
using namespace std;
int main()
{
	char c[] = "12,21,32,121,9,0";
	Sort list1(10,-9,50);
int vec[] = { 2,3,2,-1,6,8,910,-23,30};
	Sort list2(vec, 9);
	Sort variadic_list(7, 3, 2, 1, 2, 0, 90, -19);
	//Sort char_list(c);
	//char_list.Print();
	Sort list3();
	//list3.Print();
	list1.InsertSort(false);
	//list1.Print();
	//list1.QuickSort(false);
	list1.Print();
	variadic_list.BubbleSort(false);
	variadic_list.Print();
	std::cout << list2.GetElementFromIndex(list2.GetElementsCount()-1);
}