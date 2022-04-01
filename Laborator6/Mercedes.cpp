#include "Mercedes.h"
#include "Car.h"
#include "Weather.h"
#include <string>
using namespace std;

Mercedes::Mercedes() {
	fuelCapacity = 100;
	fuelConsumption = 10;
	averageSpeed[Rain] = 100;
	averageSpeed[Sunny] = 150;
	averageSpeed[Snow] = 75;
	name = (char*)"Mercedes";
}

float Mercedes::Racing(bool& ok, int weather, int length) {
	int speed = averageSpeed[weather];

	float cap = fuelCapacity / fuelConsumption;
	float distance = cap * speed;

	if (distance >= length) {
		ok = true;
	}
	else {
		ok = false;
	}
	return (cap * length / distance);
}

char* Mercedes::getName() {
	return name;
}