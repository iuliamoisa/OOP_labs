#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"

using namespace std;
class Repo
{
private:
	vector<Shape*> fig;
	
public:
	Shape* GetShape(string shapeType, string color);
	void Add(Shape*);
	void Remove(string info);
	void PrintAll();
};

