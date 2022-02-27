#include <iostream>
//de la petru
//un program citeste mai multe nr dintr-un fisier in.txt si afiseaza suma lor pe ecran
int main()
{
	FILE* f = nullptr;
	fopen_s(&f, "in.txt", "r");
	char buffer[1024];
	int sizeB = fread(buffer, 1, 1024, f);
	fclose(f);
	int number = 0;
	int sum = 0;
	bool negative = false; // in caz ca am valori negative
	for (int i = 0; i < sizeB; ++i)
	{
		if (buffer[i] >= '0' && buffer[i] <= '9') // valoarea e cifra
		{
			number = number * 10 + buffer[i] - '0'; // in number formez nr
		}
		else if (buffer[i] == '-' && number == 0) //number==0 sunt la inceput, nu am pus nimic in number
		{
			negative = true;
		}
		else {
			sum += negative ? -number : number; //daca negative=true, adunam -number, altfel adun number
			negative = false;
			number = 0;
		}
	}
	sum += number;
	printf("%d ", sum);
	/*
	for (int i = 0; i < 10; ++i);
	*/
	return 0;
}