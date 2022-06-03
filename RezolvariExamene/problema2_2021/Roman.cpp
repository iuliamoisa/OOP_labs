#include "Roman.h"

Roman::Roman(string nume, string autor) {
	this->nume = nume;
	this->autor = autor;
}
string Roman::GetInfo() {
	string s = "Roman ";
	s += this->nume;
	s += " de ";
	s += this->autor;
	return s;
}