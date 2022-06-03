#pragma once
#include <iostream>
#include <string>
using namespace std;

class Masina {
public:
	virtual string GetColor() = 0;
	virtual string GetName() = 0;
};
