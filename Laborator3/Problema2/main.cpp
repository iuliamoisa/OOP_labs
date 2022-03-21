#include <iostream>
#include "Canvas.h"
using namespace std;
/*
use a matrix of type char for the canvas. A pixel is a cell in the matrix.
A pixel is considered empty if it contains the space (value 32) character.
---------------------- ALOCARE MATRICE
char** matrix = (char**)(malloc(nr_of_lines * sizeof(char*)))
for (int i = 0; i < nr_of_lines; i++) matrix[i] = (char*)(malloc(nr_of_columns * sizeof(char)))
	cand se acceseaza : m[i][j] = ...
*/


int main()
{
	Canvas c(50, 50);
    c.DrawCircle(40, 40, 10, '*');
   

    c.FillCircle(20, 20, 5, '*');
    c.DrawRect(13, 13, 17, 17, '3');
    c.FillRect(7, 7, 9, 9, '4');
    c.SetPoint(28, 29, '5');
    c.DrawLine(1, 9, 9, 1, '-');
    c.Print();
    c.Clear();
    c.Print();
    
	return 0;
}

