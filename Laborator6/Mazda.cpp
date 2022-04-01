#include "Mazda.h"
#include "Car.h"
#include "Weather.h"
#include <string.h>
using namespace std;

Mazda::Mazda() {
	fuelCapacity = 70;
	fuelConsumption = 10;
	averageSpeed[Rain] = 70;
	averageSpeed[Sunny] = 90;
	averageSpeed[Snow] = 45;
	name = (char*)"Mazda";
}

float Mazda::Racing(bool& ok, int weather, int length) {
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

char* Mazda::getName() {
	return name;
}