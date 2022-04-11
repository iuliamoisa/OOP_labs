#pragma once
#include "Operatie.h"
class Inmultire: public Operatie
{
public:
	Inmultire();
	int comp(int a, int b);
	char* getName();
};

