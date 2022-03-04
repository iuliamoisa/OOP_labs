#include "FirstClass.h"
#include <string.h>
//interpretarea clasei
//in header: definitia claselor

//ca sa implementam o metoda din clasa:
//<tip de return> <nume_clasa>::<nume_metoda> (parametri) '{implementare}
void FirstClass::setNota(int input) {
	//this-> 
	this->nota = input;
}

int FirstClass::getNota() {
	return this->nota;
}
void FirstClass::setNume(char nume[20]) {
	strcpy_s(this->nume, 20, nume);
}
char* FirstClass::getNume() {
	return this->nume;
}