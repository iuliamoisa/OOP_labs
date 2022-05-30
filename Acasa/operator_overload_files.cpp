

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>

// iostream allows use to read from the standard 
// input (keyboard) and write to the standard output
// (console)
// fstream is needed for working with files
#include <fstream>

// ---------- OPERATOR OVERLOADING ----------
// 
// Needed for ostringstream
#include <sstream>
using namespace std;
// Create a custom Box class with overloaded operators
class Box {
public:
	double length, width, breadth;
	
	string boxString;// holds a string representation of a box
	Box() {
		length = 1, width = 1, breadth = 0;
	}
	Box(double l, double w, double b) {
		length = l, width = w, breadth = b;
	}

	// define customer operators <=> define functions
	// 
	// This is a unary operator because it operates on 1 object
	// Other Unary Operators : --, *(pointer dereference),
	// -> (Member Selection), !, & (Address of), +, -
	Box& operator ++ () {
		//declarat ca o functie
		length++;
		width++;
		breadth++;
		return *this; //returns the new box
	}

	// Creates a C string representation which is a
   // pointer to an array that is null terminated
	operator const char* () {
		// Creates a stream that can be loaded with 
	   // characters that can then be accessed as
	   // a string object
		ostringstream boxStream;
		boxStream << "Box: " <<
			length << ", " <<
			width << ", " <<
			breadth;
		boxString = boxStream.str(); //c representation of boxStream
		return boxString.c_str(); //returns the pointer to the string array
	}

	// Binary operators operate on 2 objects
	// +, -, *, /, %, ==, !=, >, <, >=, <=, &&, ||, 
	// !, =, +=, -=, *=, /=, ^, [], &, |

	Box operator + (const Box& box2) {
		Box boxSum;
		boxSum.length = length + box2.length;
		boxSum.width = width + box2.width;
		boxSum.breadth = breadth + box2.breadth;
		return boxSum;
	}

	double operator [](int x) {
		// Access items using a subscript operator
		if (x == 0)
			return length;
		else if (x == 1)
			return width;
		else if (x == 2)
			return breadth;
		else return 0;
	}

	bool operator == (const Box& box2) {
		// Check for box equality
		return ((length == box2.length) &&
			(width == box2.width) &&
			(breadth == box2.breadth));
	}


	bool operator < (const Box& box2) {
		double thisSize = length + width + breadth; //size of current box
		double box2Size = box2.length + box2.width + box2.breadth;
		if (thisSize < box2Size)
			return true;
		else
			return false;
	}

	bool operator > (const Box& box2) {
		double thisSize = length + width + breadth; //size of current box
		double box2Size = box2.length + box2.width + box2.breadth;
		if (thisSize > box2Size)
			return true;
		else
			return false;
	}

	void operator = (const Box& boxToCopy) {
		// Overload the assignment operator
		length = boxToCopy.length;
		width = boxToCopy.width;
		breadth = boxToCopy.breadth;
	}
};

// ---------- FILE I/O & PROBLEM ----------
//prototipul pt problemA
vector<string> StringToVector(string, char separator);

int main()
{

	// ---------- OPERATOR OVERLOADING ----------
	Box box(10, 10, 10);
	++box;  // Will increment all values in the box by 1
	cout << box << "\n";

	Box box2(5, 5, 5);
	cout << "Box1 + Box2 = " << box + box2 << endl; //add boxes

	//access data with subscript operator
	cout << "Box Length: " << box[0] << ", " << box[1] << endl;


	cout << boolalpha; // ca sa apara true/false in loc de 1/0
	cout << "Are boxes equal: " << (box == box2) << endl;

	cout << "Is box < box2? " << (box < box2) << endl;

	cout << "Is box > box2? " << (box > box2) << endl;

	box = box2;
	cout << box << endl;

	//-----------------------------------------------------------
	
	// ---------- FILE I/O & PROBLEM ----------

	ofstream writeToFile;
	ifstream readFromFile;
	string textToWrite = "";
	string textFromFile = "";

	// We open the file by providing a name and then either
   // ios::app : Append to the end of the file
   // ios::trunc : If the exists delete content
   // ios::in : Open file for reading
   // ios::out : Open file for writing
   // ios::ate : Open writing and move to the end of the file

	writeToFile.open("test.txt", ios_base::out |
		ios_base::trunc);
	if (writeToFile.is_open()) {

		// You can write with the stream insertion operator
		writeToFile << "Beggining of file \n";

		// You can write data in a string
		cout << "Enter data to write: ";
		getline(cin, textToWrite);
		writeToFile << textToWrite;

		writeToFile.close();
	}

	readFromFile.open("test.txt", ios_base::in); //open for reading
	if (readFromFile.is_open()) { 
		//read text from file while it's not empty
		while (readFromFile.good()) {
			getline(readFromFile, textFromFile);
			cout << textFromFile << endl;

			// ----- PROBLEM -----
	// After each line print both the number of 
	// words in each line and the average word length

			vector<string> vect = StringToVector(textFromFile, ' ');
			int wordsInLine = vect.size();
			cout << "Number of words in Line: " << wordsInLine << endl;

			int charCount = 0;
			for (auto word : vect) {
				for (auto letter : word) {
					charCount++;
				}
			}
			int avgNumOfChars = charCount / wordsInLine;
			cout << "Average word length: " << avgNumOfChars << endl;

		}
		readFromFile.close();
	}
	return 0;
}

// ----- PROBLEM FUNCTION -----

vector<string> StringToVector(string theString,
	char separator) {

	// Create a vector
	vector<string> vecsWords;

	// A stringstream object receives strings separated
	// by a space and then spits them out 1 by 1
	stringstream ss(theString);

	// Will temporarily hold each word in the string
	string sIndivStr;

	// While there are more words to extract keep executing
	// 
	// getline takes strings from a stream of words stored
	// in the stream and each time it finds a blank space
	// it stores the word proceeding the space in sIndivStr
	while (getline(ss, sIndivStr, separator)) {

		// Put the string into a vector
		vecsWords.push_back(sIndivStr);
	}

	return vecsWords; //returns vectors
}