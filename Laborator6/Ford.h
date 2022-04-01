#pragma once
#include "Car.h"
class Ford : public Car
{
public:
	Ford();
	float Racing(bool& ok, int, int) override;
	char* getName() override;
};

