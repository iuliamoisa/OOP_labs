#pragma once
#include "Operatie.h"
class Impartire: public Operatie
{
public:
	Impartire();
	int comp(int a, int b);
	char* getName();
};

