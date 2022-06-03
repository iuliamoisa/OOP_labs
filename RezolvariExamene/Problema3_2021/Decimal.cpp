#include "Decimal.h"

string Decimal::GetFormatName() {
	string s = "Format: Decimal ";
	return s;
}

string Decimal::FormatNumber(int number) {
	string s = "Value: ";
	s += to_string(number);
	return s;
}
