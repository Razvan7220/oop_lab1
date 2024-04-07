#include "RangeRover.h"
#include"Weather.h"
RangeRover:: RangeRover() {
    capacity = 150;//litri
    this->consum = 20;//litri pe 100km
    this->avg_speed[Weather::Sunny] = 80;
    this->avg_speed[Weather::Rain] = 60;
    this->avg_speed[Weather::Snow] = 50;
    this->name = "Audi";
}
int RangeRover::getRace_time(int lenght, Weather vreme) {
    return lenght / avg_speed[vreme];
}
int RangeRover::getDistance() {
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