#pragma once
#include "Masina.h"

class Toyota : public Masina
{
private: 
	string color;
public:
	Toyota(string);
	string GetColor();
	string GetName();
};

