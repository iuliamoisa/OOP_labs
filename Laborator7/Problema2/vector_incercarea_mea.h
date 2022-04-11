#pragma once
#include <iostream>
using namespace std;

template <class V>
//vector blabla(vector a, vector b) {
//	return a + b;
//}

class Vector {
private:
	V a[100];
	int count;
public:
	//constructor pt count
	Vector() {
		this->count = 0;
	}
	void push(V x) {
		a[++count] = x;
	}
	V pop() {
		return a[count];
	}
	void remove(int i) {
		if (i >= 0 && i <= count - 1) {
			for (int j = i; j < count - 1; j++) {
				a[j] = a[j + 1];
			}
		}
	}
	void insert(V x, int i) {
		count++;
		for (int j = count; j >= i + 1; j--) {
			a[j] = a[j - 1];
		}
		a[i] = x;
	}

	int nrOfElements() {
		return count;
	}
	void set(int i, V value) {
		a[i] = value;
	}
	V get(int i) {
		return a[i];
	}


};


