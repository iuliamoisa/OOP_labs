#include <iostream>
#include "Calculator.h"
using namespace std;

int main() {
	Calculator c;
	c += new Adunare();
	c += new Scadere();
	c += new Adunare(); // nu se mai adauga inca o op de adunare
	c += new Inmultire();
	c += new Impartire();

	cout << "Numar operatii suportate: " << (int)c << endl;
	c.Compute(20, 10);
	if (c["Scadere"]) cout << "operatia de scadere este suportata de calculator" << endl;
	c -= "Scadere";
	c -= "Impartire";
	c.Compute(15, 6);
	cout << "Nr operatii suportate: " << (int)c << endl;
}

//operator+= adauga o operatie doar daca nu exista deja in calculator

//OK !!!!! 5 fisiere: main.cpp, calculator.cpp, calculator.h + 4 fisiere .h si .cpp pt cele 4 operatii

//operatorul += din clasa Calculator (adaugarea tre sa fie unica)

//metoda Compute din clasa Calculator (se fol polimorfism)

// operator indexare

//operator conversie la int 

// constructor clasa Calculator

//scriere corecta a claselor Adunare Scadere Inmult si Impart 

//creare clasa abastracta cu functiile virtuale pure necesare din care sunt derrivate clasele de mai sus + = * /

// operator -= din clasa Calculator (elimina un obiect care face op)

