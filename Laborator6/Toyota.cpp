#include "Toyota.h"
#include "Car.h"
#include "Toyota.h"
#include "Weather.h"
#include <string.H>
using namespace std;

Toyota::Toyota() {
	fuelCapacity = 55;
	fuelConsumption = 10;
	averageSpeed[Rain] = 50;
	averageSpeed[Sunny] = 80;
	averageSpeed[Snow] = 45;
	name = (char*)"Toyota";
}

float Toyota::Racing(bool& ok, int weather, int length) {
	int speed = averageSpeed[weather];

	float cap = (float)(fuelCapacity / fuelConsumption);
	float distance = cap * speed;

	if (distance >= length) {
		ok = true;
	}
	else {
		ok = false;
	}

	return (cap * length / distance);
}

char* Toyota::getName() {
	return this->name;
}
