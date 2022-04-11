#include "Catalog.h"
#include <cstring>
using namespace std;

Catalog::Catalog() {}

void Catalog::operator+=(Student student) {
	if (studentsIndex >= MAX_STUDENTS) {
		return;
	}

	students[studentsIndex++] = &student;
}

Student& Catalog::operator[](const char* name) {
	for (int i = 0; i < studentsIndex; ++i) {
		if (strcmp(students[i]->GetName(), name) == 0) {
			return *students[i];
		}
	}
}

Student& Catalog::operator[](size_t index) {
	return *students[index];
}

int Catalog::GetCount() {
	return studentsIndex;
}