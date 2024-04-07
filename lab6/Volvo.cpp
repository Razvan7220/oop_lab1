#include "Volvo.h"
#include"Weather.h"
Volvo::Volvo() {
	capacity = 60;//litri
	this->consum = 10;//litri pe 100km
	this->avg_speed[Weather::Sunny] = 60;
	this->avg_speed[Weather::Rain] = 40;
	this->avg_speed[Weather::Snow] = 30;
	this->name = "Volvo";
}
int Volvo::getRace_time(int lenght, Weather vreme) {
	return lenght / avg_speed[vreme];
}
int Volvo::getDistance() {
    unsigned int Capacity = this->capacity, kmPerLitru, km = 0;
    while (Capacity >= this->consum)
    {
        Capacity -= this->consum;
        km += 100;
    }
    kmPerLitru = 100 / this->consum;
    km += (Capacity * kmPerLitru);

    return km;
}