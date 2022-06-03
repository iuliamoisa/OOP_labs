#include "Revista.h"
#include <string.h>

Revista::Revista(string titlu, int nrArticole) {
	this->titlu = titlu;
	this->nrArticole = nrArticole;
}

string Revista::GetInfo() {
	string s = "Revista";
	s += this->titlu;
	s += " cu ";
	s += to_string(this->nrArticole);
	s += " articole";
	return s;
}
