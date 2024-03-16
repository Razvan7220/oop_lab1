#include<iostream>
#include "Math.h"

using namespace std;

int main()
{
	Math O;
	cout << O.Add(2, 3) << '\n';
	cout << O.Add(3.10, 3.00) << '\n';
	cout << O.Add(3.7, 3.7,-2.1) << '\n';
	cout << O.Add(2, 3,12) << '\n';
	cout << O.Mul(122, -1) << '\n';
	cout << O.Mul(3.2, 0.5) << '\n';
	cout << O.Mul(1,2,3) << '\n';
	cout << O.Mul(124.00, 0.25) << '\n';
	cout << O.Add(10, 1, 1, 1, 2, 2, 3, -2, 2, -4, -3) << '\n' << '\n';

	const char *s1 = "12",* s2 = "998";
	cout << O.Add(s1, s2);
}