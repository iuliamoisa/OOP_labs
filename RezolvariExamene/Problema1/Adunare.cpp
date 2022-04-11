#include "Adunare.h"
#include <cstring>

Adunare::Adunare() {
    strcpy_s(nume, "Adunare");
}

int Adunare::comp(int a, int b) {
    return a + b;
}

char* Adunare::getName() {
    return nume;
}
