#include "Circuit.h"
#include "Car.h"
#include "Weather.h"
#include <iostream>
#include <string.h>
using namespace std;

Circuit::Circuit() {
	this->nrOfCars = 0;
}

void Circuit::SetLength(int val) {
	this->length = val;
}

void Circuit::SetWeather(int type) {
	this->weather = type;
}

void Circuit::AddCar(Car* c) {
	car[nrOfCars++] = c;
}

void Circuit::Race() {
	bool ok;
	for (int i = 0; i < nrOfCars; i++) {
		timeToFinish[i] = car[i]->Racing(ok, weather, length);
		finished[i] = ok;
	}
}

void Circuit::ShowFinalRanks() {
	// it will print the time each car needed to finish the circuit
					   //sorted from the fastest car to the  slowest.
	cout << "----The time each car needed to finish the circuit: \n";
	//float v[10];
	//int k = 0;
	//for (int i = 0; i < nrOfCars; i++) {
	//	if (finished[i]) {
	//		v[k++] = timeToFinish[i]; 
	//	}
	//}
	//
	//for (int i = 0; i < k-1; i++) {
	//	for (int j = i + 1; j < k; j++) {
	//		if (v[i] < v[j]) {
	//			float aux = v[i];
	//			v[i] = v[j];
	//			v[j] = aux;
	//		} // in v: timpul de finish al masinilor in ord descrescatoare (0...k)
	//	}
	//}
	for (int i = 0; i < nrOfCars - 1; i++) {//parcurg timpii ; i=0 -> v[i]=timpul cel mai mare
		for (int j = i + 1; j < nrOfCars; j++) { //parcurg masinile
			if (timeToFinish[i] < timeToFinish[j]) {
				float aux1 = timeToFinish[i];
				timeToFinish[i] = timeToFinish[j];
				timeToFinish[j] = aux1;
				Car* aux2 = car[i];
				car[i] = car[j];
				car[j] = aux2;
			}
		}
	}
	for (int i = 0; i < nrOfCars; i++) {
		if (finished[i]) {
			cout << car[i]->getName() << " needed " << timeToFinish[i] << " to finish. \n";
		}
	}
	cout << "\n\n";
}

void Circuit::ShowWhoDidNotFinish() {
	cout << "----Cars who did not finish the race: \n";
	for (int i = 0; i < nrOfCars; i++) {
		if (!finished[i]) {
			cout << car[i]->getName() << " didn't finish. (Time: " << timeToFinish[i] << ") \n ";
		}
	}
	cout << "\n";
}
