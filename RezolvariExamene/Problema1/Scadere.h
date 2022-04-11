#pragma once
#include "Operatie.h"
class Scadere: public Operatie
{
public:
	Scadere();
	int comp(int a, int b);
	char* getName();
};

