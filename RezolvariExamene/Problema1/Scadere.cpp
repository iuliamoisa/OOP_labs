#include "Scadere.h"
#include <cstring>

Scadere::Scadere() {
    strcpy_s(nume, "Scadere");
}

int Scadere::comp(int a, int b) {
    return a - b;
}

char* Scadere::getName() {
    return nume;
}