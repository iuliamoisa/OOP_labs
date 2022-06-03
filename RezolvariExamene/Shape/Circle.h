#pragma once
#include "Shape.h"
#include <iostream>
using namespace std;

class Circle : public Shape
{ 
private:
	string color;
public:
	Circle(string color);
	string GetName();
	void Print() {
		cout << "Shape: circle" << endl << "Color: " << color << endl;
	}
};

