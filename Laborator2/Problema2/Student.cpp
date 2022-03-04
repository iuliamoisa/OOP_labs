#include "Student.h"
#include <string.h>

void Student::SetName(char* name)
{
	strcpy_s(this->name, 20, name);
}

char* Student::GetName()
{
	return name;
}

void Student::SetMath(float x)
{
	if (x >= 1 && x <= 10)
		this->gradeM = x;
}

float Student::GetMath()
{
	return gradeM;
}

void Student::SetEng(float x)
{
	if (x >= 1 && x <= 10)
		this->gradeE = x;
}

float Student::GetEng()
{
	return gradeE;
}

void Student::SetHistory(float x)
{
	if (x >= 1 && x <= 10)
		this->gradeH = x;
}

float Student::GetHistory()
{
	return gradeH;
}

float Student::avgGrade()
{
	this->avg = (gradeM + gradeE + gradeH) / 3;
	return avg;
}
//compares two students in terms of name, grades, average
//If two students are equal the return value of such a function
//will be 0. If the first student is bigger than the second one, 
//the return value will be 1, otherwise -1.




/*
#include "student.h"

inline void set_float_value(float value, float& output)
{
	if (value >= 1 && value <= 10)
		output = value;
}

void student::setName(const char* s)
{
	int i = 0;
	while (*(s + i) != '\0' && i < MAXSTUDENTNAME - 1)
	{
		name[i++] = s[i];
	}
	name[i] = '\0';
}


void student::setGradeM(float x)
{
	set_float_value(x, gradeM);
}

void student::setGradeE(float x)
{
	set_float_value(x, gradeE);
}


void student::setGradeH(float x)
{
	set_float_value(x, gradeH);
}


float student::computeAverage()
{
	return ((gradeE + gradeH + gradeM) / 3.0f);
}
*/