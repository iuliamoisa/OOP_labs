#pragma once
#include "Student.h"
class Catalog
{
private:
	static const int MAX_STUDENTS = 100;
	Student* students[MAX_STUDENTS]{};
	int studentsIndex = 0;
public:
	Catalog();
	void operator+=(Student student);
	Student& operator[](const char* name);
	Student& operator[](size_t index);
	int GetCount();
};

