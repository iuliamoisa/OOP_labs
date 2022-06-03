#include <iostream>
#include "Repo.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	Repo* m = new Repo();
	m->Add(m->GetShape("Circle", "red"));
	m->Add(m->GetShape("Square", "yellow"));
	m->Add(m->GetShape("Rectangle", "blue"));
	m->Add(m->GetShape("Rectangle", "red"));
	m->Add(m->GetShape("Circle", "green"));
	m->PrintAll();
	cout << endl << "Incep sa sterg elemente" << endl;
	m->Remove("Circle");
	m->PrintAll();
	//m->Add(new Circle("green"));
	//m->Add(new Rectangle("red"));
	//m->Remove("red");
	//m->PrintAll();
	return 0;
}