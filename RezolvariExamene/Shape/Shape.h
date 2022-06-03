#pragma once
#include <string>
using namespace std;
class Shape {
private: 
	string shapeType;
	string color;
public:
	virtual string GetName() = 0;
	virtual void Print() = 0;
};
