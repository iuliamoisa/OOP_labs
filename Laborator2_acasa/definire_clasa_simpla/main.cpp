#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "FirstClass.h"
using namespace std;
int main()
{
//daca avem *, folosim ->
//daca avem normal, folosim .
	FirstClass f1;
	FirstClass f2;
	FirstClass f3;
	f1.setNota(10);
	f1.setNume((char*)"Iulia");
	f2.setNota(7);
	f2.setNume((char*)"Mihai");
	f3.setNota(4);
	f3.setNume((char*)"Stefania");
	printf("1. Nume: %s | nota = %d\n", f1.getNume(), f1.getNota());
	printf("2. Nume: %s | nota = %d\n", f2.getNume(), f2.getNota());
	printf("3. Nume: %s | nota = %d\n", f3.getNume(), f3.getNota());
	
	system("pause");
	return 0;
}