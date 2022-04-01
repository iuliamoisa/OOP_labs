#pragma once
#include "Car.h"
class Mazda : public Car
{
public:
	Mazda();
	float Racing(bool& b, int, int) override;
	char* getName() override;

};

