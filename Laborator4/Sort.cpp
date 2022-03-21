#include "Sort.h"
#include <stdlib.h> //pt malloc
#include <stdarg.h> // pt va_start
#include <string.h>
#include <stdio.h> // pt printf
#include <time.h>
/*
#define _CRT_SECURE_NO_WARNINGS

int partitiona(int arr[], int low, int high)
{

	{
		int pivot = arr[high];
		int i = (low - 1);
		for (int j = low; j <= high - 1; j++)
		{
			if (arr[j] < pivot)S
			{
				++i;
				int aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			}
		}
		int aux = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = aux;
		return (i + 1);
	}
}
int partitiond(int arr[], int low, int high) {

	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] > pivot)
		{
			++i;
			int aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
		}
	}
	int aux = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = aux;
	return (i + 1);
}
void Crescator(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partitiona(arr, low, high);
		Crescator(arr, low, pi - 1);
		Crescator(arr, pi + 1, high);
	}
}
void Descrescator(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partitiond(arr, low, high);
		Descrescator(arr, low, pi - 1);
		Descrescator(arr, pi + 1, high);
	}
}
void Sort::QuickSort(bool ascendent)
{
	if (ascendent == true)
		Crescator(this->v, 0, this->n - 1);
	else
		Descrescator(this->v, 0, this->n - 1);

}
*/


Sort::Sort(int* v, int nr_elements) {//constructor from existing vector
	/*
	~create the list that needs to be sorted from an existing vector (the constructor will have two parameters - 
one being the vector, the other one being the number of elements from the vector)
	*/
	this->nr_elements_v = nr_elements;

	this->v = (int*)malloc(this->nr_elements_v * sizeof(int));
	for (int i = 0; i < nr_elements; i++) {
		this->v[i] = v[i];
	}
	//for (int i = 0; i < nr_elements; i++) {
		//printf("Elementul din vector cu nr %d: %d\n", i, v2[i]);}
}

Sort::Sort(int count, ...) {
//~create the list that needs to be sorted using variadic parameters(use va_args for this)
	va_list vl;
	va_start(vl, count);
	this->nr_elements_v = count;
	this->v = (int*)malloc(count * sizeof(int));
	for (int i = 0; i < count; i++) {
		this->v[i] = va_arg(vl, int);
		//printf("%d", v[i]);
	}
	va_end(vl);
}

Sort::Sort(char* c) { //transf din string in vector
	int number = 0;
	int k = 0;
	this->v = (int*)malloc(100 * sizeof(int)); //ce val sa pun??

	for (int i = 0; i < strlen(c); ++i){
		if (c[i] >= '0' && c[i] <= '9'){ 
			number = number * 10 + c[i] - '0'; 
			}
		else { 
			this->v[k++] = number;
			number = 0;
			}
		}
	//dupa ultimul caracter nu am virgula, deci nu il ia in considerare
	this->v[k++] = number;
	number = 0;
	this->nr_elements_v = k;
	//for (int i = 0; i < k; i++) {
		//printf("Primul nr identificat in sir este %d\n", v4[i]);}
}

/*Sort::Sort() : v(new int[6] {1, 2, 3, 4, 5, 6}) { //lista de initializare
	//~create the list that needs to be sorted from an initialization list
	//nu mai trb alocat vectorul; este deja alocat
	//putem printa/afisa etc... vectorul este gata de sortare
	this->nr_elements_v = 6;
}
*/

void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	if (ascendent == true)
		for (i = 1; i < this->nr_elements_v; i++)
		{
			key = this->v[i];
			j = i - 1;

			while (j >= 0 && this->v[j] > key)
			{
				this->v[j + 1] = this->v[j];
				j = j - 1;
			}
			this->v[j + 1] = key;
		}
	else
		for (i = 1; i < this->nr_elements_v; i++)
		{
			key = this->v[i];
			j = i - 1;
			while (j >= 0 && this->v[j] < key)
			{
				this->v[j + 1] = this->v[j];
				j = j - 1;
			}
			this->v[j + 1] = key;
		}
}

void Sort::BubbleSort(bool ascendent) {
	int i, j;
	bool swapped;
	if (ascendent == true) {
		for (i = 0; i < this->nr_elements_v; i++)
		{
			swapped = false;
			for (j = 0; j < this->nr_elements_v - i - 1; j++)
			{
				if (this->v[j] > this->v[j + 1])
				{
					int aux = this->v[i];
					this->v[i] = this->v[j];
					this->v[j] = aux;
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
	}
	else {
		for (i = 0; i < this->nr_elements_v; i++)
		{
			swapped = false;
			for (j = 0; j < this->nr_elements_v - i - 1; j++)
			{
				if (this->v[j] < this->v[j + 1])
				{
					int aux = this->v[i];
					this->v[i] = this->v[j];
					this->v[j] = aux;
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
	}
	
}

void Sort::Print() {
	//printf("Numar maxim de elemente: %d\n", this->MaxNumberOfElements);
	printf("Nr de elemente: %d\n", nr_elements_v);
	for (int i = 0; i < nr_elements_v; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int  Sort::GetElementsCount() {
	return this->nr_elements_v;
}

int Sort::GetElementFromIndex(int index)
{
	return this->v[index];
}

/*
  void QuickSort(bool ascendent = false){
	
  }
*/