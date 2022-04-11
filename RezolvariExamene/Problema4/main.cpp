#include <iostream>
#include "Catalog.h"
#include "Student.h"
using namespace std;

int main() {
	Catalog c;

	c += { "Marcel" };
	c += { "Maria" };

	c["Marcel"]["matematica"] = 5;
	c["Marcel"]["engleza"] = 10;
	c["Marcel"]["info"] = 7;

	c["Maria"]["matematica"] = 10;

	for (int i = 0; i < c.GetCount(); ++i) {
		cout << c[i].GetName() << ": \n";
		c[i].PrintNote();
		cout << "Media: " << (float)c[i] << "\n\n";
	}


	return 0;
}