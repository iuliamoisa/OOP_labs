#include <iostream>
#include "Number.h"
#include "Printer.h"
#include "Decimal.h"
#include "Hexazecimal.h"
using namespace std;
int main()
{
	Number n1(1), n2(2), n3(10);
	Number n4((int)((((n1 + n2) * n3) / n2) + (n1 - n2)));
	(n4.operator+=(new Hexazecimal())) += (new Decimal());
	n4.Print();
	cout << "Valoarea hexazecimala este: " <<  hex << (int)n4 << endl;
	return 0;
}