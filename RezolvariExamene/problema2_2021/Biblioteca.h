#pragma once
#include "Carte.h"
#include <iostream>
#include <vector>
#include <array>
class Biblioteca
{
private:
	array<Carte*, 100> carti;
	int count;
public:
	Biblioteca();
	~Biblioteca();
	Biblioteca& operator += (Carte* c);
	array<Carte*, 100>::iterator begin();
	array<Carte*, 100>::iterator end();
	operator int();
	void PrintFilter(bool (*fn)(Carte* c));
};

