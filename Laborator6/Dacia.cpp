#include "Dacia.h"
#include "Car.h"
#include "Weather.h"
#include <string.h>
using namespace std;

Dacia::Dacia() {
	fuelCapacity = 50;
	fuelConsumption = 30;
	averageSpeed[Rain] = 40;
	averageSpeed[Sunny] = 60;
	averageSpeed[Snow] = 20;
	name = (char*)"Dacia";
}

char* Dacia::getName() {
	return name;
}


float Dacia::Racing(bool& ok, int weather, int length) {
	int speed = averageSpeed[weather]; // speed: 60
	float cap = fuelCapacity / fuelConsumption; // cap:  5/3
	float distance = cap * speed; // 1,6 * 60 => distance: 96

	if (distance >= length) {
		ok = true; // a terminat
	}
	else {
		ok = false;
	}
	return (cap * length / distance); 
}