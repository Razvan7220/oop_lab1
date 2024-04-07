#pragma once
#include "CAR.h"
class RangeRover :
    public CAR
{
public:
	int getRace_time(int lenght, Weather speed);
	int getDistance();
	RangeRover();
};

