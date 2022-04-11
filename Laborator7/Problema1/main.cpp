#include <iostream>
using namespace std;


float operator""_Kelvin(unsigned long long x) {
    float x1;
    x1 = (float)x;
    x1 = x - 273.15;
    return x1;
}
float operator""_Fahrenheit(unsigned long long x) {
    float x1;
    x1 = (float)x;
    x1 = x - 32;
    x1 = x1 / 1.8;
    return x1;
}
int main() {

    float a = 300_Kelvin;

    float b = 120_Fahrenheit;

    cout << a << endl << b;
    return 0;

}