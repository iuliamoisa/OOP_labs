#pragma once
#include <vector>
#include <array>
#include <string>
#include "Entry.h"
using namespace std;

class Database
{
private:
	vector<Entry*> entries;
public:
	Database& operator+=(Entry* a);
	Database& operator-=(string name);
	vector<Entry*>::iterator begin();
	vector<Entry*>::iterator end();
	void Print();
};

