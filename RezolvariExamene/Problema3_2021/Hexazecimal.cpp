#include "Hexazecimal.h"

string Hexazecimal::GetFormatName() {
	string s = "Format: Hexazecimal ";
	return s;
}

string Hexazecimal::FormatNumber(int numar) {
 
    string a = "Value: 0x0000000";
    string d = "0123456789ABCDEF";
    string res;
    while (numar > 0)
    {
        res = d[numar % 16] + res;
        numar /= 16;
    }
    a += res;
    return a;
}
