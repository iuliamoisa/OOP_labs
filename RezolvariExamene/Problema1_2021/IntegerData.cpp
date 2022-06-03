#include "IntegerData.h"


IntegerData::IntegerData(string name, string value) : Entry(name) {
	this->name = name;
	//int nr;
	//for (int i = 0; i < value.size(); i++)
	//{
	//	nr = nr * 10 + value[i] - '0';
	//}
	//this->value = nr;
	this->value = stoi(value);
}

void IntegerData::Add(string toAdd)
{
	//int nr = 0;
	//for (int i = 0; i < toAdd.size(); i++)
	//{
	//	nr = nr * 10 + toAdd[i] - '0';
	//}
	//this->value += nr;
	this->value += stoi(toAdd);
}


bool IntegerData::Substract(int toSubstract)
{
	if (toSubstract > this->value)
		return 0;
	else
	{
		this->value -= toSubstract;
		return 1;
	}
}

void IntegerData::Print()
{
	cout << name << " = " << this->value << ';';
}
