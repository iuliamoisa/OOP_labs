#pragma once
#include "Car.h"
class Mercedes : public Car
{
public:
	Mercedes();
	float Racing(bool& , int, int) override;
	char* getName() override;

};

