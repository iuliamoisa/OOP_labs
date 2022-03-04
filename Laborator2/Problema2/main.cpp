#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Student.h"
#include "GlobalFunctions.h"
using namespace std;
int main()
{
	Student a;
	Student b;
	a.SetName((char*)"mihai");
	b.SetName((char*)"mihaela");
	a.SetEng(5);
	b.SetEng(9);
	printf("Elevul %s a luat nota %f\n", a.GetName(), a.GetEng());
	/*
	if(CompName(a, b) == -1)
		std::cout << a.GetName() << '\n';
		//cu printf!!!!
	if(CompEng(a, b) == -1)
		std::cout << b.GetName();
		*/
	system("pause");
	return 0;
}


/*
#include <iostream>
#include "GlobalFunctions.h"
using namespace GlobalFunctions;
int main()
{
	student A, B;
	A.setName("Antonio");
	A.setGradeE(5.2);
	B.setName("Ana");
	B.setGradeE(9.9);
	//student::MAXSTUDENTNAME
	std::cout << byName(A, B) << '\n';
	std::cout << byEng(A, B);
	return 0;
}
*/