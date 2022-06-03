#pragma once
#include <string>
#include <iostream>
using namespace std;

class Entry
{
protected:
	string name;
public:
	Entry();
	Entry(string name);
	string getName();
	virtual void Add(string toAdd) = 0;
	virtual bool Substract(int toSubstract) = 0;
	virtual void Print() = 0;
};

