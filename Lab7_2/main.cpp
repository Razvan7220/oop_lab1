#include<iostream>
using namespace std;
float operator"" _Fahrenheit(long double a) {
	float  c = 0;
	c = (a - 32) / 2.8;
	return (float)c;
}
float  operator"" _Kelvin( long double a) {
	float  c=0;
	c = a - 273.15;
	return c;
}
int main() {
	float a = 300.0_Kelvin;
	float b = 120.0_Fahrenheit;
	cout << "sunt " << a<< " grade Celsius in Iasi si "<<b<<" grade Celsius in Bucuresti";
	return 0;
}