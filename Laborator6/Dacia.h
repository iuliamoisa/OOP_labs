#pragma once
#include "Car.h"
class Dacia : public Car
{
public:
	Dacia();
	float Racing(bool&, int, int) override;
	char* getName() override;
};

