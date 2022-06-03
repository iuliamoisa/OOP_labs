#include "Biblioteca.h"

Biblioteca::Biblioteca() {
	count = 0;
	for (int i = 0; i < 100; i++)
		carti[i] = nullptr;

}
Biblioteca::~Biblioteca() {
}

Biblioteca& Biblioteca::operator += (Carte* c) {
	if (count + 1 > 100)
		return (*this);

	this->carti[count] = c;
	this->count++;
	return (* this);
}

array<Carte*, 100>::iterator Biblioteca::begin() {
	return carti.begin();
}

array<Carte*, 100>::iterator Biblioteca::end() {
	array<Carte*, 100>::iterator it = carti.begin();
	for (int i = 0; i < count; i++)
		it++;
	return it;

}

Biblioteca::operator int() {
	return this->count;
}

void Biblioteca::PrintFilter(bool(*fn)(Carte* c))
{
	for (int i = 0; i < count; i++)
		if (fn(carti[i]) == true)
			cout << carti[i]->GetInfo() << "\n";
}

