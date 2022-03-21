#include "Sort.h"
#include <stdlib.h>
#include <stdarg.h> // pt va_start
#include <string.h>
#include <stdio.h> // pt printf
#include <time.h>
int main()
{
	
	
	int v[5] = { 1, 2, 3, 4, 5 };
	Sort c2(v, 5);
	c2.Print();
	Sort c3(6, 1, 2, 3, 4, 5, 6);
	c3.Print();
	char c[] = "12,34,56,78";
	Sort c4(c);
	c4.Print();

	bool ascendent = false;
	c4.InsertSort();
	c4.Print();
	printf("%d\n", c4.GetElementFromIndex(2));
	printf("%d\n", c4.GetElementsCount());
	system("pause");
	return 0;
}

