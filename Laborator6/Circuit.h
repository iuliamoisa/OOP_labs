#pragma once
#include "Car.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"
#include <string.h>
using namespace std;

/*

Create a class circuit that will test how different cars behave in a race depending on the length of the circuit
and the race weather condition. The circuit will use polymorphism to simulate the race conditions
(e.g. will have an array of objects of type Car* )

*/

class Circuit
{
private: 
	int length;
	Car* car[5];
	float timeToFinish[5];
	bool finished[5];
	int nrOfCars;
	int weather;

public:

	Circuit();

	void SetLength(int);

	void SetWeather(int);

	void AddCar(Car* c); 	

	void Race();

	void ShowFinalRanks();

	void ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
};

