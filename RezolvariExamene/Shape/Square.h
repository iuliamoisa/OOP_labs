#pragma once
#include "Shape.h"
#include <iostream>
using namespace std;
class Square : public Shape
{
private:
	string color;
public:
	Square(string color);
	string GetName();
	void Print() {
		cout << "Shape: square" << endl << "Color: " << color << endl;
	}
};


