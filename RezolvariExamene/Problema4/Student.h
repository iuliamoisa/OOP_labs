#pragma once
class Student
{
private:
	static const int MAX_SUBJECTS = 20;
	const char* subjects[MAX_SUBJECTS]{};
	int grades[MAX_SUBJECTS]{};
	int subjectIndex = 0;
	const char* m_name;
public:
	Student();
	Student(const char* name);

	const char* GetName();
	int& operator[](const char* subject);
	operator float ();
	void PrintNote();
};