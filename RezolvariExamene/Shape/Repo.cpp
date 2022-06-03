#include "Repo.h"

Shape* Repo::GetShape(string shapeType, string color) {
	if (shapeType == "Circle")
		return new Circle(color);
	if (shapeType == "Rectangle")
		return new Rectangle(color);
	if (shapeType == "Square")
		return new Square(color);
}
void Repo::Add(Shape* a) {
		fig.push_back(a);
}

void Repo::Remove(string info) {

	//for (auto i = fig.begin(); i < fig.end(); i++) {
		/*if (fig.at(i).shapeType == info || fig.at(i).color == info) {
			fig.erase(fig.begin() + i);
		}*/
	
	for (auto i = fig.begin(); i != fig.end(); i++) 
		if ((*i)->GetName() == info) {
			//fig.erase(fig.begin() + j);
			//fig.erase(fig.begin() + j, fig.begin() + j + 1);
			//cout << "----" << endl;
			fig.erase(i);
		
		}
			
}
void Repo::PrintAll() {
	for (auto i = fig.begin(); i != fig.end(); i++) {
		(*i)->Print();
	}
}