#include "Math.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
	Math m;
	int a = 3, b = 6, c = 10;
	double x = 19.2, y = 2.3, z = 1.5;

	printf("Suma a 2 nr intregi: %d\n", m.Add(a, b));
	printf("Suma a 3 nr intregi: %d\n", m.Add(a, b, c));
	printf("Suma a 2 nr reale: %d\n", m.Add(x, y));
	printf("Suma a 3 nr reale: %d\n", m.Add(x, y, z));
	printf("Inmultirea a 2 nr intregi: %d\n", m.Mul(a, b));
	printf("Inmultirea a 3 nr intregi: %d\n", m.Mul(a, b, c));
	printf("Inmultirea a 2 nr reale: %d\n", m.Mul(x, y));
	printf("Inmultirea a 3 nr reale: %d\n", m.Mul(x, y, z));
	printf("Suma a n nr intregi: %d\n", m.Add(5, 10, 2, 20, 3, 9));
	printf("Concatenarea a 2 siruri: %s\n", m.Add("nu", "stiu"));
	return 0;
}

