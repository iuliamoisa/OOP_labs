#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <functional> // pt a putea pune functiile ca parametrii

using namespace std;

// 1. functie creata pt a fi stocata ca variabila (vezi 1. in main() ) 
// si pt a fi transmisa altor functii
double MultipBy2(double num) {
	return num * 2;
}


// 2. Functions can receive other functions
// the first double is the return type followed by the data types for the parameter
double DoMath(function<double(double)> func, double num) {
	return func(num);
}


//3. functiile pot fi stocate intr-un vector -> 3. in main()
double MultipBy3(double num) {
	return num * 3;
}

// 4. ----- PROBLEM -----
// 
// Checks for odd using modulus
bool IsItOdd(int num) {
	if (num % 2 == 0)
		return false;
	else return true;
}

// Receives a vector and generates a vector of odd values from it
vector<int>ChangeList(vector<int>list, function<bool(int) > func) {
	vector<int> oddList;
	for (auto i : list) {
		if (func(i))
			oddList.push_back(i);
	}
	return oddList;
}


// ----- --------------5. PROBLEM2 -----------------------

// Generates a random list from the possible values supplied
vector<char> GetHAndTlist(vector<char> possibleValues, int numberValuesToGenerate) {
	srand(time(NULL));
	vector<char> hAndTList;
	for (int x = 0; x < numberValuesToGenerate; x++) {
		int randIndex = rand() % 2; // obtin doar nr modulo 2, adica 0 sau 1;
									//possibleValues[0] = 'H'; [1]='T'
			hAndTList.push_back(possibleValues[randIndex]);
	}
	return hAndTList;
}

// Receives a list and sums the number of matching chars
int GetNumberOfMatches(vector<char> list, char valueToFind) {
	int numOfMatches = 0;
	for (char c : list) {
		if (c == valueToFind)
			numOfMatches++;
	}
	return numOfMatches;
}

int main()
{

	// 1. You can store functions as variables
	auto times2 = MultipBy2; //inregistreaza functia intr-o variabila
	cout << "5 * 2 = " << times2(5) << endl;

	// 2. Pass a function into a function
	cout << " 6 * 2 = " << DoMath(times2, 6) << "\n";
	
	// 3.functions can be stored in a vector
	// Create a vector using the function parameters and then load the functions into the vector
	vector<function<double(double)> >funcs(2); //vector de functii
	funcs[0] = MultipBy2;
	funcs[1] = MultipBy3;
	cout << "2 * 10 = " << funcs[0](10) << endl;
	cout << "3 * 2 = " << funcs[1](2) << endl << "3 * 7 = " << funcs[1](7) << endl;


	// 4. 	---------------- PROBLEM ----------------
   // Create a function that receives a list and a function
   // The function passed will return True or False if a list
   // value is odd.
   // The surrounding function will return a list of odd
   // numbers

	vector<int> listOfNums{ 1,2,3,4,5 }; //lista de integeri
	vector < int> oddList = ChangeList(listOfNums, IsItOdd);
	cout << "List of Odds\n";
	for (auto i : oddList) {
		cout << i << " ";
	}
	cout << endl;


	//			---------- 5. PROBLEM2 ------------
 //Create a function that creates a random list using a limited nr of values (ex. 100)
// Create another function that checks for the nr of matches in a list
// Create a random list of Hs and Ts and then output how many of each were generated
	//H=heads, T=tails
	vector<char> possibleValues{ 'H', 'T' };
	vector<char> hAndTlist = GetHAndTlist(possibleValues, 100);
	cout << "Number of heads: " << GetNumberOfMatches(hAndTlist, 'H') << endl;
	cout << "Number of tails: " << GetNumberOfMatches(hAndTlist, 'T') << endl;

	
	return 0;
}