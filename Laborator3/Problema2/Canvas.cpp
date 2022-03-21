#include "Canvas.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
//CTRL F5
Canvas::Canvas()
{
	this->mat = nullptr;
	this->width = 0;
	this->height = 0;
}
Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->mat = (char**)(malloc(width * sizeof(char*)));
	for (int i = 0; i < width; i++)
		this->mat[i] = (char*)(malloc(height * sizeof(char)));

}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++) {
			int d = (i - x) * (i - x) + (j - y) * (j - y);
			int k = ray * ray;
			int k1 = (ray - 1) * (ray - 1);
			int k2 = (ray - 1) * (ray + 1);
			if (d <= k2 && d >= k1)
				this->mat[i][j] = ch;
			else
				this->mat[i][j] = ' ';
		}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
				this->mat[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++)
			if ((i == top && j >= left && j <= right) || (i == bottom && j >= left && j <= right) || (j == left && i >= top && i <= bottom) || (j == right && i >= top && i <= bottom))
				this->mat[i][j] = ch;
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++)
			if (i >= left && i <= right && j >= top && j <= bottom)
				this->mat[i][j] = ch;

}
void Canvas::SetPoint(int x, int y, char ch)
{
	this->mat[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int D = 2 * dy - dx;
	int y = y1;

	for (int i = x1; i < x2; i++)
	{
		this->mat[y][i] = ch;
		if (D > 0)
		{
			y = y + 1;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}
void Canvas::Print()// shows what was printed
{
	if (this->mat != nullptr)
	{
		for (int i = 0; i < this->width; i++)
		{
			for (int j = 0; j < this->height; j++)
				printf("%c ", this->mat[i][j]);
			printf("\n");
		}
	}
	else
		printf("Matricea este nullptr\n");
}
void Canvas::Clear()
{
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++)
			this->mat[i][j] = ' ';
}