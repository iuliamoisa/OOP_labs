#pragma once

class Student
{
private:
	char name[20];
	float gradeM, gradeE, gradeH, avg;
public:
	void SetName(char* name);
	char* GetName();
	void SetMath(float x);
	float GetMath();
	void SetEng(float x);
	float GetEng();
	void SetHistory(float x);
	float GetHistory();
	float avgGrade();
};

/*

#pragma once
class student
{
private:
	static constexpr int MAXSTUDENTNAME = 50;
	char name[MAXSTUDENTNAME] = {};
	float gradeM = 0.0f, gradeE = 0.0f, gradeH = 0.0f;
public:
	void setName(const char* s);
	inline const char* getName() {
		return name;
	}
	void setGradeM(float x);
	inline float getGradeM() {
		return gradeM;
	}
	void setGradeE(float x);
	inline float getGradeE() {
		return gradeE;
	}
	void setGradeH(float x);
	inline float getGradeH() {
		return gradeH;
	}
	float computeAverage();
}; */