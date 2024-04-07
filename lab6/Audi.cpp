#include "Audi.h"
#include"Weather.h"
Audi::Audi() {
    capacity = 100;//litri
    this->consum = 15;//litri pe 100km
    this->avg_speed[Weather::Sunny] = 90;
    this->avg_speed[Weather::Rain] = 70;
    this->avg_speed[Weather::Snow] = 60;
    this->name = "Audi";
}
int Audi::getRace_time(int lenght, Weather vreme) {
    return lenght / avg_speed[vreme];
}
int Audi::getDistance() {
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