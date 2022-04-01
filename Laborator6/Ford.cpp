#include "Ford.h"
#include "Car.h"
#include "Ford.h"
#include "Weather.h"
#include <string.h>
using namespace std;

Ford::Ford() {
	fuelCapacity = 60;
	fuelConsumption = 8;
	averageSpeed[Rain] = 50;
	averageSpeed[Sunny] = 75;
	averageSpeed[Snow] = 35;
	name = (char*)"Ford";
}

float Ford::Racing(bool& ok, int weather, int length) {

	int speed = averageSpeed[weather]; // speed = 75
	float cap = fuelCapacity / fuelConsumption; // hours = 60/8 = 7,5
	float distance = cap * speed; // distance = 562,5

	if (distance >= length) {
		ok = true;
	}
	else {
		ok = false;
	}
	
	return (cap * length / distance); // 450/562,5 = 0,8
}

char* Ford::getName() {
	return name;
}