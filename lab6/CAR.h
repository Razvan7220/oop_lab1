#pragma once
#include"Weather.h"
class CAR
{
public:
    float capacity, consum;
   unsigned int  avg_speed[3];
   const char* name;
   virtual int getRace_time(int lenght,Weather vreme) = 0;
   virtual int getDistance() = 0;
};