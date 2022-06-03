#pragma once
#include <iostream>
using namespace std;

class Phrase
{
private:
	char** sentence;
	int wordCount;
	int GetLength(char* word) {
		int j = 0;
		while (word[j] != NULL) {
			j++;
		}
		return j;
	}

public:
	Phrase(const char* s);
	~Phrase();

	int CountLetter(int m, char x);
	int CountLetter(char x);
	int CountVowels();
	char* GetLongestWord();
	char* operator[](int index);
	operator int();

};

