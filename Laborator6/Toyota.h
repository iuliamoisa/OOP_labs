#pragma once
#include "Car.h"

class Toyota : public Car
{
public:
	Toyota();
	char* getName() override;
	float Racing(bool& , int, int) override;
};

