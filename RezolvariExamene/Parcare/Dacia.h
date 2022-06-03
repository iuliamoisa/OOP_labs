#pragma once
#include "Masina.h"

class Dacia : public Masina
{
private:
	string color;
public:
	Dacia(string);
	string GetColor();
	string GetName();
};

