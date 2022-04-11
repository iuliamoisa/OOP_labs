#include "Student.h"
#include <cstring>
#include <iostream>
using namespace std;

Student::Student() : m_name(nullptr) {}

Student::Student(const char* name) : m_name(name) {
}

const char* Student::GetName() {
	return m_name;
}

int& Student::operator[](const char* subject) {
	for (int i = 0; i < subjectIndex; ++i) {
		if (strcmp(subjects[i], subject) == 0) {
			return grades[i];
		}
	}

	subjects[subjectIndex] = subject;
	return grades[subjectIndex++];
}

void Student::PrintNote() {
	for (int i = 0; i < subjectIndex; ++i) {
		cout << subjects[i] << " - " << grades[i] << endl;
	}
}

Student::operator float() {
	float sum = 0;
	for (int i = 0; i < subjectIndex; ++i) {
		sum += grades[i];
	}

	return sum / subjectIndex;
}