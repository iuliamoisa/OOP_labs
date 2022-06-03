#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Masina.h"
using namespace std;

class Parcare
{
	vector<Masina*> m;
	int maxCapacity;
public:
	void Create(int maxCapacity);
	bool Add(Masina*);
	void RemoveByName(string name);
	int GetCount();
	bool IsFull();
	void ShowAll();
	void ShowByColor(string color);
};

