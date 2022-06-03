#pragma once
#include "Printer.h"
#include <string>
using namespace std;

class Hexazecimal : public Printer
{
	string GetFormatName();
	string FormatNumber(int number);
};

