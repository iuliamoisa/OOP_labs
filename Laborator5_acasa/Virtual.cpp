
#include <iostream>
using namespace std;

class Smartphone{
public:
	virtual void TakeASelfie() = 0; // pure virtual function => abstract class
	//which means: we cannot create instances, but we can create pointers
	//=> orice clasa derivata din clasa Smartphone TREBUIE sa aiba implementata
	//o functie TakeASelfie proprie!!

	virtual void MakeACall() = 0;
};

class Android : public Smartphone{ //implementam toate functiile din clasa Smartphone
public:
	void TakeASelfie() {
		cout << "Android selfie\n";
	}
	void MakeACall() {
		cout << "Android calling!\n";
	}
};

class IPhone : public Smartphone {
	void TakeASelfie() {
		cout << "IPhone selfie\n";
	}
	void MakeACall() {
		cout << "IPhone calling!\n";
	}
};

int main()
{
	Smartphone* s1 = new Android();
	Smartphone* s2 = new IPhone();
	s1->TakeASelfie();
	s2->TakeASelfie(); 
	s1->MakeACall();

	system("pause>0");
}

