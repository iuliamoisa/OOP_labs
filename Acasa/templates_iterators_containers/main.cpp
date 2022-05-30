#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>

#include <deque>
#include <list>
#include <forward_list>

#include <iterator>

#include "Animal.h"

#define PI 3.14159 //macro constant which replaces PI with the value
				//in the code before execution
#define AREA_CIRCLE(radius) (PI * (std::pow(radius, 2)))
using namespace std;


// ----- TEMPLATE FUNCTIONS -----

// We use templates to create functions or classes
// that can work with many types
// Templates differ from function overloading in that
// instead of having a function that does similar
// things with different objects a template does the
// same thing with different objects

// This says this is a function template that generates
// functions that except 1 parameter
template<typename T>
void Times2(T val) {
	cout << val << " * 2 = " << val * 2 << endl;
}

// Receive multiple parameters and return a value
template <typename T>
T Add(T val, T val2) {
	return val + val2;
}

// Work with chars and strings
template <typename T>
T Max(T val, T val2) {
	return (val < val2) ? val2 : val;
}

// ----- TEMPLATE CLASSES -----

// Template classes are classes that can work with 
// different data types

// You can define that you may receive parameters
// with different types, but they don't have to
// be different

template<typename T, typename U>
class Person {
public:
	T height;
	U weight;
	static int numOfPeople; //!!!!!trb initializat
	Person(T h, U w) {
		height = h;
		weight = w;
		numOfPeople++;
	}
	void GetData() {
		cout << "Height: " << height <<
			" and weight: " << weight << endl;
	}
};

// You have to initialize static class members
template<typename T, typename U> int Person<T, U>::numOfPeople; //asa trb facut pt toate variabilele statice!!!


//------------------------------------
	// ----- CONTAINERS -----

bool isEven(const int& val) {
	return (val % 2) == 0;
}

int main()
{
	Animal spot = Animal();
	spot.name = "Spot";
	cout << "The Animal is named " << spot.name << endl;

	std::cout << "Circle Area : " <<
		AREA_CIRCLE(5) << "\n";

	Times2(5);
	Times2(5.3);
	cout << "5 + 4 = " << Add(5, 4) << "\n";
	cout << "5.5 + 4.6 = " << Add(5.5, 4.6) << "\n";
	cout << "Max 4 or 8 = " << Max(4, 8) << endl;
	cout << "Max A or B = " << Max('A', 'B') << endl;
	cout << "Max Dog or Cat = " << Max("Dog", "Cat") << endl;
	
	cout << endl;
	//------------------------------------
	// ----- TEMPLATE CLASSES -----

	// When creating the object you must define the 
	// data types used
	Person<double, int>mikeTyson(5.83, 216);
	mikeTyson.GetData();
	cout << "Number of people: " << mikeTyson.numOfPeople << endl;
	
	cout << endl;
	//------------------------------------

	//iterator = used to point at container memory location!
	vector<int> nums2 = { 1,2,3,4,5 };
	//iterator as the same type as the container im working with(above)
	vector<int>::iterator itr;
	for (itr = nums2.begin(); itr < nums2.end(); itr++) {
		cout << *itr << "\n"; //prints the value
	}

	vector<int>::iterator itr2 = nums2.begin();
	advance(itr2, 2); //jumps 2 places
	cout << *itr2 << "\n";

	auto itr3 = next(itr2, 1); 
	cout << *itr3 << "\n";

	auto itr4 = prev(itr2, 1); //previous
	cout << *itr4 << "\n";

	vector<int> nums3 = { 1,4,5,6 };
	vector<int> nums4 = { 2,3 };
	auto itr5 = nums3.begin();
	advance(itr5, 1);
	copy(nums4.begin(), nums4.end(), inserter(nums3, itr5));
	for (int& i : nums3)
		cout << i << endl;

	//------------------------------------
	// ------------------ CONTAINERS------------ -----
	cout << endl << endl;

	// ----------1. DEQUES ----------

	// A deque (Deck) is a dynamic array like vectors
	// except it also allows for insertion or deletion
	// from the front
	deque<int> deq1;
	deq1.push_back(5);
	deq1.push_front(1);
	deq1.assign({ 11,12 }); //overwrites
	deq1.push_back(7);
	deq1.push_front(8);
	cout << "Size of deq1 : " << deq1.size() << endl;
	cout << "deq1[0]= " << deq1[0] << endl;
	cout << "deq1[1]= " << deq1.at(1) << endl;
	deque<int>::iterator it = deq1.begin() + 1;
	deq1.insert(it, 3);

	int tempArr[5] = { 6,7,8,9,10 };
	deq1.insert(deq1.end(), tempArr, tempArr + 5); //adauga la final 5 elemente din tempArr
	//deq1.erase(deq1.end());//sterge elem de pe ultima pozitie
	deq1.erase(deq1.begin(), deq1.begin() + 2); //sterge primele 2 elemente
	deq1.pop_front();
	deq1.pop_back();

	cout << endl << "deq1: " << endl;
	for (int i : deq1)
		cout << i << endl;

	deque<int>deq2(2, 50); //de 2 ori 50
	deq1.swap(deq2); // Swap values in deques
	//deq1.clear(); // Delete all values

	cout << endl << "deq2: " << endl;
	for (int i : deq2)
		cout << i << endl;

	// ----------2. Lists ----------
	 // Lists are the most efficient at inserting,
	// moving and extracting elements, but lack
	// direct access to elements
	cout << endl;
	int arr[5] = { 1,2,3,4,5 };
	list<int> list1;
	list1.insert(list1.begin(), arr, arr + 5);
	//list1.assgin({ 10,20,30 }); //overwrites
	list1.push_back(5);
	list1.push_front(1);
	
	//cout << list1[0] << endl; nu pot accesa un elem la un anumit index din lista
	list<int>::iterator it2 = list1.begin();
	advance(it2, 1);

	it2 = list1.begin();
	list1.insert(it2, 8);
	//list1.erase(list1.begin());

	//it2 = list1.begin();
	//list<int>::iterator it3 = list1.begin();
	//advance(it3, 2);
	//list1.erase(it2, it3); //deletes elements [begin,begin+2]

	int arr2[6] = { 10,9,8,7,6,6 };
	list<int>list2;
	list2.insert(list2.begin(), arr2, arr2 + 6);
	list2.sort();
	//list2.reverse();
	list2.unique();
	list2.remove(6); //removes the value of 6, not the 6th pos
	list2.remove_if(isEven);
	

	cout << endl << "list 1: " << endl;
	for (int i : list1)
		cout << i << endl;
	cout << "Size of list1: " << list1.size() << endl;
	cout << "2nd index of the list1: " << *it2 << endl;
	cout << endl;

	cout << endl << "list 2: " << endl;
	for (int i : list2)
		cout << i << endl;
	cout << "Size of list2: " << list2.size() << endl;
	
	// ---------- FORWARD_LIST ----------
 //like a list, but each item only has a link to the next item
//(and not to the item that proceeds it)=cannot move back, only forward

   //the QUICKEST of the sequence containers

	forward_list<int>fl1;
	fl1.assign({ 1,2,3,4 });
	fl1.push_front(0); //cant push_back!!
	fl1.pop_front(); //cant pop_back!!!
	cout << "Front: " << fl1.front() << endl;
	forward_list<int>::iterator it4 = fl1.begin();

	it4 = fl1.insert_after(it4, 5);
	//it4 = fl1.erase_after(fl1.begin());

	fl1.emplace_front(6); //places a value on the first pos
	fl1.remove(4); //removes all 4's
	fl1.remove_if(isEven);

	forward_list<int>fl2;
	fl2.assign({ 9,8,7,6,6 });
	fl2.unique();
	fl2.sort(); //pot si reverse()
	//fl1.merge(fl2); //transform listele din 2 in 1
	//fl2.clear();

	cout << endl << "forward list no.1 : " << endl;
	for (int i : fl1)
		cout << i << endl;
	cout << "Front: " << fl1.front() << endl;

	cout << endl << "forward list no.2 : " << endl;
	for (int i : fl2)
		cout << i << endl;
	
	return 0;
}