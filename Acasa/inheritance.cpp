#include <iostream>
using namespace std;

// base class: common functionalities 
// child class : derived from the base

class Entity {
public:
	float X, Y;

	void Move(float xa, float ya) {
		X += xa;
		Y += ya;
	}
};

class Player : public Entity { // player are tot ce are entity public

public:
	const char* Name;
	
	void PrintName() {
		cout << Name << endl;
	}
};

int main() {
	cout << sizeof(Entity) << endl;
	Player player; 
	player.Move(5, 5);
	player.X = 5;
	//player.PrintName();
}
