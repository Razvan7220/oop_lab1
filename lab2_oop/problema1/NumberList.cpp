#include "NumberList.h"
#include<iostream>
using namespace std;
void NumberList :: Init(){
	this->count = 0;
}
bool NumberList:: Add(int x) {
	if (this->count >= 10)
		return false;
	else
		this->numbers[this->count++] = x;
	return true;
}
void NumberList::Sort(){
	
	for (int i = 0; i < this->count - 1; i++)
	{
		int mini = this->numbers[i];
		for (int j = i + 1; j < this->count; j++)
		{
			if (mini > this->numbers[j])
			{
				mini = this->numbers[j];
				swap(this->numbers[i], this->numbers[j]);
			}
		}
	}
}
void NumberList::Print() {
	for (int i = 0; i < this->count; i++)
		cout << this->numbers[i]<<" ";
	cout << '\n';
}