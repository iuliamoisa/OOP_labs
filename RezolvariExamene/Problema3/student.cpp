#include "student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student(const char* x) {
    strcpy(nume, x);
    n = 0;
}

char* Student::GetName() {
    return nume;
}

void Student::PrintNote() {
    for(int i = 0; i < n; i++)
        cout << "    " << mat[i] << ' ' << note[i] << '\n';
}

int& Student::operator[](const char* x) {
    for(int i = 0; i < n; i++)
        if(strcmp(mat[i], x) == 0)
            return note[i];
    mat[n] = new char[strlen(x)+1];
    strcpy(mat[n], x);
    n++;
    return note[n-1];
}

Student::operator float() {
    float x = 0;
    for(int i = 0; i < n; i++) {
        x += note[i];
    }
    return x/n;
}
