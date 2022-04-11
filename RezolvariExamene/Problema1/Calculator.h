#pragma once
#include "Scadere.h"
#include "Adunare.h"
#include "Impartire.h"
#include "Inmultire.h"


class Calculator
{
	Operatie* a[10];
	int n;
public: 
	Calculator(); // constructor
	void operator+=(Operatie* x);
	void operator-=(const char* x);
	bool operator[](const char* x);
	void Compute(int a, int b);
	operator int();

};

