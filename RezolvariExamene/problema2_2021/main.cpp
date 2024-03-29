#include <iostream>
#include "Biblioteca.h"
#include "Revista.h"
#include "Roman.h"
using namespace std;

int main()
{
	Biblioteca b;
	(b += new Roman("DON QUIJOTE", "MIGUEL DE CERVANTES")) += new Revista("Journal of Artificial Intelligence", 100);
	b += new Roman("MACBETH", "WILLIAM SHAKESPEARE");
	for (auto x : b)
	{
		std::cout << x->GetInfo() << std::endl;
	}
	std::cout << "Numar de intrari in biblioteca: " << (int)b << std::endl;
	std::cout << "Lista doar cu romane:" << std::endl;
	b.PrintFilter([](Carte* c)->bool {
		// adaugati codul care determina daca o carte este un Roman
		string info = c->GetInfo();
		string subInfo = info.substr(0, 5);
		if (subInfo == "Roman")
			return true;
		return false;

		});
	return 0;
}