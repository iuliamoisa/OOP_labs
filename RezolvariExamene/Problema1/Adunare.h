#pragma once
#include "Operatie.h"
class Adunare: public Operatie
{
public:
	Adunare();
	int comp(int a, int b);
	char* getName();
};

