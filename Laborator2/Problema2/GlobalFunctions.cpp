#include "Student.h"
#include "GlobalFunctions.h"
#include <string.h>

int CompName(Student* a, Student* b) {
	if (strcmp(a->GetName(), b->GetName()) == 0)
		return 0;
	else
		if (strcmp(a->GetName(), b->GetName()) > 0)
			return 1;
		else return -1;
}

int CompGradeM(Student* a, Student* b) {
	if (a->GetMath() == b->GetMath())
		return 0;
	else
		if (a->GetMath() > b->GetMath())
		return 1;
		else return -1;
}

int CompGradeE(Student* a, Student* b) {
	if (a->GetEng() == b->GetEng())
		return 0;
	else
		if (a->GetEng() > b->GetEng())
			return 1;
		else return -1;
}

int CompGradeH(Student* a, Student* b) 
{
	if (a->GetHistory() == b->GetHistory())
		return 0;
	else
		if (a->GetHistory() > b->GetHistory())
			return 1;
		else return -1;
}
int CompAvgGrade(Student* a, Student* b) {
	float gr1, gr2;
	gr1 = a->avgGrade();
	gr2 = b->avgGrade();
	if (gr1 == gr2)
		return 0;
	else
		if (gr1 > gr2)
			return 1;
		else return -1;
}

/*
#include "GlobalFunctions.h"
int GlobalFunctions::byName(student a, student b)
{
	int i = 0, j = 0;
	char* numeA = a.getName();
	char* numeB = b.getName();
	while (*(numeA + i) != '\0' && *(numeB + i) != '\0')
	{
		if (*(numeA + i) != *(numeB + i))
		{
			if (*(numeA + i) < *(numeB + i))
				return -1;
			return 1;
		}
		i++;
	}
	if (*(numeA + i) == '\0' && *(numeB + i) == '\0')
		return 0;
	if (*(numeA + i) == '\0')
		return -1;
	return 1;
}
inline int compare_float_values(float v1, float v2)
{
	if (v1 > v2) return 1;
	if (v1 < v2) return -1;
	return 0;
}
int GlobalFunctions::byAverage(student a, student b)
{
	return compare_float_values(a.computeAverage(), b.computeAverage());
}

int GlobalFunctions::byEng(student a, student b)
{
	return compare_float_values(a.getGradeE(), b.getGradeE());
}

int GlobalFunctions::byMath(student a, student b)
{
	return compare_float_values(a.getGradeM(), b.getGradeM());
}

int GlobalFunctions::byHist(student a, student b)
{
	return compare_float_values(a.getGradeH(), b.getGradeH());
}
*/