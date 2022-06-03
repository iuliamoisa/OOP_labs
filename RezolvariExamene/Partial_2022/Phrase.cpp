#include "Phrase.h"

Phrase::Phrase(const char* word) {
	sentence = new char* [20];
	int i, j;
	for (i = 0; i < 20; i++) {
		sentence[i] = new char[15];
	}
	i = 0;
	j = 0;
	wordCount = 0;
	while (word[i] != NULL) {
		if (word[i] != ' ') {
			sentence[wordCount][j] = word[i];
			j++;
		}
		else if (j != 0) {
			sentence[wordCount][j] = NULL;
			j = 0;
			wordCount++;
		}
		i++;
	}
	if (j != 0)
		sentence[wordCount][j] = NULL;
	else wordCount--;

}
Phrase::~Phrase() {
	for (int i = 0; i < 20; i++) {
		delete[]sentence[i];
	}
	delete[] sentence;
}


int Phrase::CountLetter(int index, char c) {
	int number = 0;
	int j = 0;
	while (sentence[index][j] != NULL) {
		if (sentence[index][j] == c)
			number++;
		j++;
	}
	return number;
}

int Phrase::CountLetter(char c) {
	int i, j, number = 0;
	for (i = 0; i <= wordCount; i++) {
		j = 0;
		while (sentence[i][j] != NULL) {
			if (sentence[i][j] == c)
				number++;
			j++;
		}
	}
	return number;
}


int Phrase::CountVowels() {
	int i, j, number = 0;
	for (i = 0; i <= wordCount; i++) {
		j = 0;
		while (sentence[i][j] != NULL) {
			if (sentence[i][j] == 'a' || sentence[i][j] == 'e' || sentence[i][j] == 'i' || sentence[i][j] == 'o' || sentence[i][j] == 'u' || sentence[i][j] == 'A' || sentence[i][j] == 'E' || sentence[i][j] == 'I' || sentence[i][j] == 'O' || sentence[i][j] == 'U')
				number++;
			j++;
		}
	}
	return number;
}

char* Phrase::GetLongestWord() {
	int maxi = 0;
	int nr;
	for (int i = 0; i <= wordCount; i++) {
		nr = GetLength(sentence[i]);
		if (nr > maxi)
			maxi = nr;
	}
	for (int i = 0; i <= wordCount; i++) {
		nr = GetLength(sentence[i]);
		if (nr == maxi)
			return sentence[i];
	}

}


char* Phrase::operator[](int index) {
	return sentence[index];
}
Phrase::operator int() {
	return wordCount + 1;
}
