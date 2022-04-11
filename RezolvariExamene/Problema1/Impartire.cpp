#include "Impartire.h"
#include <cstring>

Impartire::Impartire() {
    strcpy_s(nume, "Impartire");
}

int Impartire::comp(int a, int b) {
    return a / b;
}

char* Impartire::getName() {
    return nume;
}