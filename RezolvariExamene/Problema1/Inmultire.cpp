#include "Inmultire.h"
#include <cstring>

Inmultire::Inmultire() {
    strcpy_s(nume, "Inmultire");
}

int Inmultire::comp(int a, int b) {
    return a * b;
}

char* Inmultire::getName() {
    return nume;
}

