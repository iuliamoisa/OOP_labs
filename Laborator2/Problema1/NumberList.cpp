#include "NumberList.h"
#include <iostream>

void NumberList::Init() {
	this->count = 0;
}
bool NumberList::Add(int x)
{
    if (this->count >= 10)
        return false;
    this->numbers[this->count++] = x;
    return true;
}

void NumberList::Sort()
{
    for (int i = 1; i < this->count; i++)
    {
        int j = i;
        while (j >= 1 && this->numbers[j] < this->numbers[j - 1])
        {
            int aux = this->numbers[j - 1];
            this->numbers[j - 1] = this->numbers[j];
            this->numbers[j] = aux;
            j--;
        }
    }
}

void NumberList::Print()
{
    for (int i = 0; i < this->count; i++)
        std::cout << this->numbers[i] << ' ';
    std::cout << '\n';
}