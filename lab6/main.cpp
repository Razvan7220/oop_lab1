#include"CAR.h"
#include"Volvo.h"
#include"Circuit.h"
#include"Weather.h"
#include"Audi.h"
#include"RAngeRover.h"
#include<iostream>
using namespace std;
int main()
{
	Circuit Monaco;
	Monaco.AddCar(new Volvo());
	Monaco.AddCar(new Audi());
	Monaco.AddCar(new RangeRover());
	Monaco.SetLength(1000);
	Monaco.SetWeather(Sunny);
	Monaco.Race();
	Monaco.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	Monaco.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}