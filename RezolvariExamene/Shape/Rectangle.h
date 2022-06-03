#pragma once
#include "Shape.h"
#include <iostream>
using namespace std;

class Rectangle : public Shape
{
private:
	string color;
public:
	Rectangle(string);
	string GetName();
	void Print() {
		cout << "Shape: rectangle" << endl << "Color: " << color << endl;
	}
};

