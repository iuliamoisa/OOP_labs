#include "Math.h"
#include <stdlib.h> // pt malloc
#include <stdarg.h> // pt va_start
#include <string.h>
#include <stdio.h> // pt printf


int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return (int)a + b;
}

int Math::Add(double a, double b, double c)
{
	return (int)(a + b + c);
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return (int)(a * b);
}

int Math::Mul(double a, double b, double c)
{
	return (int)(a * b * c);
}

int Math::Add(int count, ...) // sums up a list of integers
{
	int val = 0;

//initializez va_list si astfel pot recupera parametrii nespecificati
	va_list vl; 

//va_start(variabila de tip va_list, parametrul specificat)
	va_start(vl, count); // nr variadic de parametri

//va_arg = variabila + tip element
	//	 = preia parametrii de dupa cel specificat
	for (int i = 0; i < count; i++)
		val += va_arg(vl, int);
	va_end(vl);
	return val;
}

char* Math::Add(const char* s1, const char* s2)
{
//aloca memorie ca sa putem aduna 2 stringuri => malloc
//daca un string e null=> null ptr
//dupa malloc, memoria nu e initializata, deci tre sa dam valori
	char* s3 = nullptr;
	if (s1 == nullptr or s2 == nullptr)
		return nullptr;
	int sizeAlloc;
	sizeAlloc = strlen(s1) + strlen(s2) + 1; 
	if (s3 == nullptr) //nu avem alocat deci trb sa alocam
	{
		s3 = (char*)malloc(sizeAlloc);

		memset(s3, 0, sizeAlloc); //initial setez toate elementele din memorie cu 0
		//ca sa nu mai trb sa pun \0 la final
		if (s3 != nullptr) // am reusit sa alocam deci putem lipi s1 + s2
		{
	//memcpy(destinatie,sursa,n)
			//copiaza primele n valori din sursa in destinatie 
			memcpy(s3, s1, strlen(s1));
			memcpy(s3 + strlen(s1), s2, strlen(s2));
		}

	}
	else {//este deja alocata memorie deci trebuie realoc

		s3 = (char*)realloc(s3, sizeAlloc);

		memset(s3, 0, sizeAlloc);
		if (s3 != nullptr) { // am reusit realocarea

			memcpy(s3, s1, strlen(s1));
			memcpy(s3 + strlen(s1), s2, strlen(s2));
		}
	}
	return s3;
}
