#pragma once
#include "Weather.h"
// ABSTRACT CLASS => CONTAINS at least one pure virtual method
//Abstract class Car only has virtual methods (it does not need a .cpp file)

//An abstract class Car that reflects some properties on a car
//(fuel capacity, fuel consumption, average speed on different conditions(Rain, Sunny, Snow)
class Car
{
protected:
	int fuelCapacity;
	int fuelConsumption;
	int  averageSpeed[3];
	char* name;
public:
	enum Weather;
	virtual char* getName() = 0;
	virtual float Racing(bool&, int, int) = 0;
};