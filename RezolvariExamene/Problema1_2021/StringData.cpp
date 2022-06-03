#include "StringData.h"
#include "Entry.h"
#include <iostream>
using namespace std;

StringData::StringData(string name, string value) : Entry(name) {
	this->name = name;
	this->value = value;
}
void StringData::Add(string toAdd) {
	this->value += toAdd;
}
bool StringData::Substract(int toSubstract) {

	if (value.size() <= toSubstract) {
		string s = "StringData: len(";
		s += value;
		s += ") < ";
		s += to_string(toSubstract);
		cout << s << endl;
		return 0;
	}
	else {
		
		//value = value.substr(0, value.size() - toSubstract);
		value.resize(value.size() - toSubstract);
		return 1;
	}
}

void StringData::Print() {
	cout << "Name: " << name<< " = " << this->value << ';';
}
