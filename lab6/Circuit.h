#pragma once
#include"Weather.h"
#include"CAR.h"
class Circuit
{
private:
	int length;
	Weather vreme;
	CAR** cars;
	int nr_masini;
public:
	//Circuit(int participanti);
	void AddCar(CAR* masina);
	void ShowFinalRanks();
	void SetWeather(Weather vreme);
	void SetLength(int dist);
	void Race();
	void ShowWhoDidNotFinish();
};


