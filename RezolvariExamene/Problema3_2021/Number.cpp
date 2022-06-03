#include "Number.h"

Number::Number(int value) {
	this->count = 0;
	this->number = value;
}
Number:: operator int()
{
	return this->number;
}

Number Number::operator+(Number& n)
{
	return this->number + n.number;
}

Number Number::operator-(Number& n)
{
	return this->number - n.number;
}

Number Number::operator*(Number& n)
{
	return this->number * n.number;
}

Number Number::operator/(Number& n)
{
	return this->number / n.number;
}

Number& Number::operator += (Printer* prnt)
{
	this->printers[count] = prnt;
	this->count++;
	return *this;
}

void Number::Print() {
	for (int i = 0; i < count; i++) {
		cout << printers[i]->GetFormatName() << printers[i]->FormatNumber(this->number) << endl;
	}
	
}