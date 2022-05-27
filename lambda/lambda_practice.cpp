// LAMBDA EXPRESSIONSSSSSSSS
/*
allow us to write inline anonymous functions 
	= a function with very small definition
	= these functions don't need to be name because they
	don't need to be reused; they are very simple and therefore, anonymous

lambda = very simple function that we are not going to
reuse like a normal functions; used for short small snippets of code
	= keep the code clean & are fast to execute

*/
#include <iostream>
#include <vector>
#include <algorithm> // functions: for_each
using namespace std;

int main()
{
	/*
	-------------- OVERKILL - TOO MUCH CODE -----------
	struct {
		void operator() (int x) {
			cout << x << "\n";
		}
	}something;

	//[cc](param){funct_def}; //lambda expression

	vector<int> v{ 2,3,7,14,23 };
	for_each(v.begin(), v.end(), something);

	-------------------------------------------------
	*/


	// [](int x){ cout << x << "\n"; } =  lambda funct
	/*
	vector<int> v{ 2,3,7,14,23 };
	for_each(v.begin(), v.end(), [](int x) { cout << x << "\n"; });
	*/
	// cele 2 linii de mai sus fac fix acelasi lucru ca toata partea de mai sus


	/*
	[](int x) {
		if (x % 2 == ) {
			cout << x << " is even number \n";
		}
		else cout << x << " is odd number \n";
	}// lambda function
	
	*/
	/*
	* --------------un exemplu mai complex
	vector<int> v{ 2,3,7,14,23 };
	for_each(v.begin(), v.end(), [](int x) {
		if (x % 2 == 0) {
			cout << x << " is even number \n";
		}
		else cout << x << " is odd number \n";
		});
	
	------------------------------
	*/ 

	int d = 3;
	vector<int> v{ 2,3,7,14,23 };
	for_each(v.begin(), v.end(), [d](int x) {
		if (x % d == 0) {
			cout << x << " is divisible by number "<< d << endl;
		}
		else cout << x << " is not divisible by number " << d << endl;
		});

	/*
	SAUUU daca vreau sa schimb valoarea lui d in interiorul functiei 
	lambda, trebe sa ii dau referinta

	vector<int> v{ 2,3,7,14,23 };
	for_each(v.begin(), v.end(), [&d](int x) {
		if (x % d == 0) {
			cout << x << " is divisible by number "<< d << endl;
		}
		else cout << x << " is not divisible by number " << d << endl;
		d = 10;
		});
	*/

	return 0;
}



