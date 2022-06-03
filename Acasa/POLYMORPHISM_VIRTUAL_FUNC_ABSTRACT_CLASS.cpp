#include <iostream>
using namespace std;

/* --------- BEFORE VIRTUAL FUNCTIONS: BAD PROGRAMMING
class Enemy {
protected:
	int attackPower; //every enemy has an attack power
public:
	void setAttackPower(int a) {
		attackPower = a;
	}
};

class Ninja : public Enemy {
	//all ninjas are enemy
public:
	void attack() {
		//specific ONLY TO THE NINJA, even tho ninja is still an enemy
		//so it can still acces protected&public traits of parent class (=enemy)
		cout << "I am a ninja attacker! I will chop you! -" << attackPower << endl;
	}
};

class Monster : public Enemy {
	//all monsters are enemy
public:
	void attack() {
		//specific ONLY TO THE MONSTER
		cout << "I am a monster attacker! I will eat you! -" << attackPower << endl;
	}
};


int main()
{
	//ninja is just a more specific type of enemy
	Ninja n;
	Monster m;

	//anything an enemy can do, a ninja/monster can do too
	//so it's possible to reffer an enemy pointer to a ninja memory space
	Enemy* enemy1 = &n;
	Enemy* enemy2 = &m;
	enemy1->setAttackPower(29);
	enemy2->setAttackPower(90);

	//can't use enemy1 bcs its type is Enemy, not Ninja; and Enemy class doesn't have attack method
	//it would've been easier if the Enemy class would've had the attack method

	n.attack(); //because of polymorphism, it knows that is should display the attack message
				//specific to the ninja enemy
	m.attack();

	return 0;
}
*/

// -----------IMPROVED ------------


class Enemy {
public:
	virtual void attack() {
		//every enemy has the ability to attack
		//ninja attacks differently than a monster does, so this function would be overwritten
		//to avoid this, we can create this function as a VIRTUAL one
		//which means that we're going to use it polymorphically
	} 
};

class Ninja : public Enemy {
public:
	void attack() {
		cout << "Ninja attacks!" << endl;
	}
};

class Monster : public Enemy {
public:
	void attack() {
		cout << "Monster attacks!" << endl;
	}
};
/*
regular virtual functions have the OPTION to be overwritten; it's not a strict requirement
sa zicem ca eu am o clasa parinte cu o functie virtuala (NU pura) attack care contine emsajul
"parintele ataca"; exista 2 copii derivati din aceasta clasa parinte:
copil 1: are functie attack care afis mesajul " copilul 1 ataca"
copil 2: are functie attack care nu afiseaza nimic!

fiind vb de regular virtual functions, copil 1 afis "copilul 1 ataca",
copilul 2, neavand mesaj propriu in functia virtuala, afiseaza mesajul din clasa parinte=>
copil 2: "parintele ataca!"
*/

int main()
{
	Ninja n;
	Monster m;
	Enemy* enemy1 = &n;
	Enemy* enemy2 = &m;
	enemy1->attack(); //now we can use an Enemy type of object to access the attack method
	enemy2->attack();
	return 0;
}

//daca am o functie virtuala pura [virtual void function()=0] intr o clasa parinte
//e obligatoriu ca orice alta clasa copil care contine function sa aiba scris cod in acea functie
//pt a suprascrie function din clasa parinte

//=> PURE VIRTUAL FUNCTIONS NEED TO  BE OVERWRITTEN
//ABSTRACT CLASS =  a class in which there's at least one pure virtual function