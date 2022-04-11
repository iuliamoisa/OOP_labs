#include <iostream>
#include "vector.h"
using namespace std;

///// int operator""_Kelvin(int)
//float operator""_Kelvin(unsigned long long x) {
//    float x1;
//    x1 = (float)x;
//    x1 = x - 273.15;
//    return x1;
//}
//float operator""_Fahrenheit(unsigned long long x) {
//    float x1;
//    x1 = (float)x;
//    x1 = x - 32;
//    x1 = x1 / 1.8;
//    return x1;
//}
//int main() {
//
//    float a = 300_Kelvin;
//
//    float b = 120_Fahrenheit;
//
//    cout << a << endl << b;
//    return 0;
//
//}

int main() {
	Vector<int> v;
	v.push(1);
	v.push(3);
	cout << v.pop() << endl;
	v.set(0, 7);
	cout << v.get(0);
	return 0;
}
