#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>

#include <set>
#include <map>
#include <stack>
#include <queue>

#include <iterator>
using namespace std;

// ----- ASSOCIATIVE CONTAINERS -----
//store sorted data => insertion slower, but searching faster

int main() {

	set<int>set1{ 5,4,3,2,1,1 };
	cout << "Size of set1: " << set1.size() << endl; //afis 5, desi 5 4 3 2 1 1 = 6 elem
			//ptc 1=1 deci il ia o sg data in considerare!

	set1.insert(0);
	//cout << set1[0]; //NU MERGE sa accesez elem cu index
	set<int>::iterator it = set1.begin();
	it++;
	cout << "2nd value in set1: " << *it << endl;
	set1.erase(5);

	//deletes the last 2 elements
	it = set1.end();
	advance(it, -2);
	set1.erase(it, set1.end()); 

	int arr[] = { 6,7,8,9 };
	set1.insert(arr, arr + 4);
	auto val = set1.find(6);
	cout << "Found: " << *val << "\n";

	//returns the iterator to the specified value(ex.8)
	//=  Get iterator to value
	auto eight = set1.lower_bound(8); 
	cout << "8: " << *eight << endl;


	// Get iterator to value after
	auto nine = set1.upper_bound(8);
	cout << "9: " << *nine << endl;

	// Swap values in sets
	set<int> set2{ 10,11 };
	set1.swap(set2);


	cout << endl << "Set1: " << endl;
	if (!set1.empty()) {
		for (int i : set1) {
			cout << i << endl;
		}
	}
	cout << endl;

	// ----- MULTISET -----
 // Stores duplicate values in sorted order
  //= SET CARE PERMITE VALORI REPETATE

	std::multiset<int> mset1{ 1,1,2,3,4 };

	// Insert value
	mset1.insert(4);
	mset1.insert(0);

	cout << endl << "Multiset: " << endl;
	if (!mset1.empty()) {
		for (int i : mset1)
			std::cout << i << "\n";
	}

	// ----- MAP -----
  // Stores using key value pairs 
// NO DUPLICATE KEYS

	std::map<int, std::string> map1;
	//pair<key, value>
	map1.insert(pair<int, string>(1, "Bart"));
	map1.insert(pair<int, string>(2, "Lisa"));
	map1.insert(pair<int, string>(3, "Marge"));
	map1.insert(pair<int, string>(4, "Homer"));

	cout << endl << "Map1 :" << endl;

	// Find element by key
	auto match = map1.find(1);
	cout <<"Key 1 has value: " << match->second << endl;

	// Get iterator to value
	auto bart = map1.lower_bound(1);
	cout << "Lower bound of key 1 has value: " << bart->second << endl;

	// Get next iterator
	auto lisa = map1.upper_bound(1);
	cout << "Upper bound of key 1 has value: " << lisa->second << endl;

	// Print elements with an iterator
	map<int, string>::iterator it2;
	for (it2 = map1.begin(); it2 != map1.end(); it2++) {
		cout << "Key: " << it2->first << endl;
		cout << "Value: " << it2->second << endl;
	}

	// ----- MULTIMAP -----
// mapa in care pot avea key dubplicate, atata timp cat
	//valorile sunt diferite
	multimap<int, string> mmap1;
	mmap1.insert(std::pair <int, std::string>(1, "Bart"));
	mmap1.insert(std::pair <int, std::string>(1, "Lisa"));
	mmap1.insert(std::pair <int, std::string>(3, "Marge"));
	
	cout << endl << "Multimap1 :" << endl;

	map<int, string>::iterator it3;
	for (it3 = mmap1.begin(); it3 != mmap1.end(); ++it3) {
		cout << "Key : " << it3->first << "\n";
		cout << "Value : " << it3->second << "\n";
	}



	//------------------------------------

	// -----*********** CONTAINER ADAPTERS*********** -----
	// Adapt containers to provide a defined interface

				// ----- STACK ----- stiva
	// creeaza interfata astfel incat sa poata stoca elemente
	//in format last in first out


	stack<string> custs; //custs = customers
	custs.push("George");
	custs.push("Louise");
	custs.push("Florence");

	// Get number of elements
	int size = custs.size();
	cout << endl << "Stack1 :" << endl;
	// Check if empty
	if (!custs.empty()) {
		for (int i = 0; i < size; i++) {

			// Get value with top
			cout << custs.top() << "\n";

			// Delete last value entered
			custs.pop();
		}
	}

	// ----- QUEUE -----
//storing elements in a FIFO format
	queue<string> cast;
	cast.push("Zoidberg");
	cast.push("Bender");
	cast.push("Leela");
	int size2 = cast.size();

	cout << endl << "Queue :" << endl;
	if (!cast.empty()) {
		for (int i = 0; i < size2; i++) {

			// Get value with top
			cout << cast.front() << "\n";

			// Delete last value entered
			cast.pop();
		}
	}

	// ----- PRIORITY QUEUE -----
 // Elements are organized with the largest first
	priority_queue<int> nums;
	nums.push(4);
	nums.push(8);
	nums.push(5);

	int size3 = nums.size();

	cout << endl << "Priority Queue :" << endl;
	if (!nums.empty()) {
		for (int i = 0; i < size3; i++) {

			// Get value with top
			cout << nums.top() << "\n";

			// Delete last value entered
			nums.pop();
		}
	}

	// ----- ENUMS -----
 // Custom data type that assigns names to constant integers
 // =>  program easier to read

   // You can define the starting index, or any others
	enum day { Mon = 1, Tues, Wed, Thur, Fri = 5 };

	enum day tuesday = Tues;

	cout << endl << "using enumsssss: " << endl;
	cout << "Tuesday is the " << tuesday <<
		"nd day of the week\n";

	// Cycle through days
	for (int i = Mon; i <= Fri; i++)
		cout << i << "\n";



	return 0;
}
