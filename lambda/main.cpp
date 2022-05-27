#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void MyFunction1(int aa) {
	int a, b, c;
	a = b = c = 10;
	auto f = [=](int x, int y) {return x + y + a + b + c + aa; };
	//se captureaza toate variabilele locale si parametrii din MyFunction
	//daca nu puneam =, nu puteam folosi a,b,c,aa
	printf("%d\n", f(10, 20)); // 1060
	printf("--------------\n");
}

void MyFunction2(int aa) {
	int a, b, c;
	a = b = c = 10;
	auto f = [&](int x, int y) {return x + y + a + b + c + aa; };
	//se captureaza toate variabilele locale si parametrii din MyFunction
	//prin referinta
	printf("%d\n", f(10, 20)); //1060
	a = b = c = 100;
	aa *= 2;
	printf("%d\n", f(10, 20)); // 2330
	printf("--------------\n");
}

void MyFunction3(int aa) {
	int a, b, c;
	a = b = c = 10;
	auto f = [=, &a](int x, int y) {return x + y + a + b + c + aa; };
	// toate variabilele sunt capturate => se creeaza o copie, mai putin a
	// variabila locata a este capturata prin referinta
	printf("%d\n", f(10, 20)); //1060 = 10+20+10+10+10+1000
	a = b = c = 100;
	aa *= 2;
	printf("%d\n", f(10, 20)); // 1150 = 10+20+100+10+10+1000
	printf("--------------\n");
}

void MyFunction_erori(int aa) {
	//functii lambda care nu merg pe exemplele anterioare
	int a, b, c;
	a = b = c = 10;
	auto f = [=, &a](int x, int y) {return x + y + a + b + c + aa; }; //asta e ok; daca nu puneam nu mai rula programu:))

	//auto f = [=, a](int x, int y) {return x + y + a + b + c + aa; }; // nu compileaza mereu
	
	//auto f = [a, a](int x, int y) {return x + y + a + b + c + aa; }; // -> a nu poate fi capturat de doua ori
	
	//auto f = [a, &a](int x, int y) {return x + y + a + b + c + aa; }; // -> a nu poate fi capturat de doua ori

	printf("%d\n", f(10, 20)); 
	a = b = c = 100;
	aa *= 2;
	printf("%d\n", f(10, 20)); 
	printf("--------------\n");
}

//-----------------------------------

int Add(int x, int y) {
	return x + y;
}

void MyFunction4(int aa) {
	int a, b, c;
	a = b = c = 10;
	auto ptr_f = Add;
	auto f = [ptr_f](int x, int y) {return ptr_f(x,y); };
	// se captureaza un poinnter la o functie
	// deci e salvata valoarea la care pointeaza ptr_f
	// mai exact, e salvata valoarea Add = x+y
	printf("%d\n", f(10, 20));  //30
	printf("--------------\n");
}

class MyNumber {
public: 
	int a, b;
	MyNumber(int x, int y): a(x), b(y){ }
	// ClassName (const ClassName &old_obj);  =  COPY CONSTRUCTOR
	MyNumber(const MyNumber& m) { a = m.b; b = m.a; }

};

class Student {
private:
	const char* Name;
	int Grade;
public:
	Student(const char* n, int g) { Name = n; Grade = g; }
	void IncrementGrade() {
	//se captureaza(copiaza) pointerul this 
	//deci pot accesa ceea ce exista in clasa student
		//acum functia lambda devine clasa friend pt clasa Student =>
		// poate accesa campurile private ale clasei mama
		auto la = [this] {this->Grade++; };
		la(); //apelez functia lambda => creste nota cu 1

		//auto la = [=] {this->Grade++; }; 
		//auto la = [&] {Grade++; }; 
			//fac la fel ca functia lambda de mai sus, deoarece 
			//[=], [&] inseamna captarea tuturor variabilelor locale, obiectului this, etc
			// !! nu e necesara folosirea "this->" in functiile lambda
		//auto la = [] {Grade++; }; NU FUNCTIONEAZA ptc nu a fost captat pointerul this
	}	
};

class AltStudent { // pt std::function
private:
	const char* Name2;
	int Grade2;
public:
	AltStudent(const char* n2, int g2) { Name2 = n2; Grade2 = g2; }
	function<void()> GetIncrementFunction() {
		auto la2 = [&]() {Grade2++; };
		function<void()> fnc3 = la2;
		return fnc3;
	}
};
//void Sort(int *number, int count, bool(*Compare)(int n1, int n2)){...}

typedef int (TypeIntegerSum)(int, int); //folosit pt a inlocui un pointer cu o functie

int main() { 

	/*
	exemplu 1
	auto f = [](int x, int y) { return x + y; };
	int x = f(10, 20);
	printf("X = %d", x); //afis 30
	*/


	/* exemplu 2
	int value = 100;
	auto f = [value](int x, int y) { return x + y + value; };
	//[value] -> se face o copie locata a valorii value
	// adica chiar daca modificam valoarea, rezultatul
	//functiei lambda va fi acelasi
	printf("%d \n", f(10,20)); // afis 130
	value = 200;
	printf("%d \n", f(10, 20)); //afis 130
	*/


	/* exemplu 3
	int value = 100;
	auto f = [&value](int x, int y) { return x + y + value; };
	printf("%d \n", f(10, 20)); // afis 130
	value = 200;
	// [&value] -> se modifica valoarea din 100 in 200
	printf("%d \n", f(10, 20)); //afis 230
	*/


	/* exemplu 4
	int value = 100;
	auto f = [&value](int x, int y) -> char { return x + y + value; };
	//am setat tipul expresiei lambda, si anume char
	//daca nu am fi setat, tipul ar fi fost dedus din tipul
	// return al expresiei lambda
	printf("%d \n", f(10, 20)); // afis -126 = reprezentarea char a valorii int 130
	value = 200;
	printf("%d \n", f(10, 20)); //afis -30 = reprezentarea char a lui 230
	*/


	MyFunction1(1000); // returneaza 1060
	MyFunction2(1000); // afis 1060 si apoi 2330
	MyFunction3(1000); // 1060 1150
	MyFunction4(1000); //30


	int a = 10, b = 20;
	auto f1 = [a, b](int x, int y) {return x + y + a + b; };
	//decltype(f1) f2(a,b); //-> nu merge deoarece NU POT initializa astfel o lambda
		//pot folosi decltype pt lambda care NU au capturi!!!!
		//= adica au default cosntructor
	//!! decltype creeaza un obiect de tipul altui obiect!!!
	decltype(f1) f2 = f1;// am copy constructor intre f1 si f2
	printf("%d", f2(1, 2)); // 33
	printf("----------------------\n\n");




	//---------------------------
	
	// !!!!!!!!!!!!!!!!!!! DE INTELES DE AICI IN JOS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	MyNumber m1(2, 3);
	auto g1 = [m1](int x, int y) { return x * m1.a + y * m1.b; };
	//constructorul copy din MyNumber e apelat <=> captez prin copie
	//obiectul actual e creat in interiorul obiectului lambda si
	//are campurile a si b inversate
	printf("%d\n", g1(10, 20)); // 10 * 3 + 20 * 2 = 70
	printf("----------------------\n\n");


	MyNumber m2(2, 3);
	auto g2 = [&m2](int x, int y) { return x * m2.a + y * m2.b; };
	printf("%d\n", g2(10, 20)); // 10 * 2 + 20 * 3 = 80
	//se foloseste referinta, deci doar se capteaza pointerul pt acel obiect=>
		//reuzltatul este diferit 
	printf("----------------------\n\n");



	//---------------------------



	int a1, a2, a3, a4, a5, a6;
	auto h1 = [=](int x, int y) {return x + y + a1 + a3; };
	// daca folosim "="  si/sau   "&" inseamna ca singurele valori folosite 
	// in corpul functiei lambda sunt copiate in clasa lambda
	printf("%d\n", sizeof(h1)); // 8 , ptc copiem numai a1 si a3 
					//adica am creat campuri doar pt a1 si a2 => 2 * 4 =8 
	printf("----------------------\n\n");



	//int a1, a2, a3, a4, a5, a6;
	auto h2 = [=](int x, int y) {return x + y + a1 + a3 + a5; };

	printf("%d\n", sizeof(h2)); // 12 , ptc copiem numai a1 si a3
	printf("----------------------\n\n");



	//---------------------------

	Student s("popescu", 8);
	s.IncrementGrade(); // => nota devine 9

	//---------------------------
	/*
	toate functiile lambda care nu au capturi au o conversie implicita la o functie pointer
	no capture = pointerul this-> nu e necesar pt functia lambda
	*/
	//int a = 100;
	int numbers[] = { 1,4,2,6,1,3 };
	//auto i1 = [](int n1, int n2) {return n1 > n2; }; // -> functioneaza ptc i1 nu are capturi
	//Sort(numbers, sizeof(numbers)/sizeof(int), i1);
	//auto i2 = [b](int n1, int n2) {return n1 > n2; }; // -> nu functioneaza ptc i2 captureaza variabila locala 'a'
	//auto i3 = [=](int n1, int n2) {return n1 > n2; }; // -> functioneaza, ptc desi copiaza toate 
			//variabilele locale & parametrii creand o copie a lor, lambda nu foloseste niciunul dintre ei
			//deci e ca si cum nimic n-a fost capturat
	//auto i4 = [=](int n1, int n2) {return n1 > (n2 + a); }; //-> nu functioneaza ptc lambda foloseste o variabila locala




	//--------------------------- LAMBDA SI STL!!!!!!!!


	// exemplul 1
	vector<int> v1 = { 1,2,3,5,6,7 };
	for_each(v1.begin(), v1.end(), [](int value) {printf("%d ", value); }); // 1 2 3 5 6 7


	printf("\n\n");
	//------------------------exemplul 2--------------------------------
	vector<int> v2 = { 1,2,3,5,6,7 };
	for_each(v2.begin(), v2.end(), [](int& value) {value *= 2; });
	for_each(v2.begin(), v2.end(), [](int value) {printf("%d ", value); }); // 2 4 6 10 12 14

	printf("\n\n");

	//---------------------exemplul 3-------------------------------
	vector<int> v3{ 1,2,3,5,6,7 };
	int odd_numbers = count_if(v3.begin(), v3.end(), [](int value) {return value % 2 == 0; });
	printf("%d\n", odd_numbers); // 2
	v3.erase( remove_if(v3.begin(), v3.end(), [](int value) {return value % 2 == 1; }), v3.end() ); //sterge elementele impare
	
	for_each(v3.begin(), v3.end(), [](int value) {printf("%d ", value); }); // 2 6

	printf("\n\n");
	//---------------------exemplul 4-------------------------------
	function<int(int, int)> fnc1 = [](int a, int b)->int {return a + b; };
	printf("%d\n",fnc1(10,20)); //30
	printf("\n\n");
	//altfel, cu typedef:

	//---------------------exemplul 5-------------------------------
	function<TypeIntegerSum> fnc2 = [](int a, int b)-> int {return a + b; };
	printf("%d\n", fnc2(10, 20)); //30
	printf("\n\n");

	//---------------------exemplul 6-------------------------------
	AltStudent st("stefanescu", 8);
	auto fnc3 = st.GetIncrementFunction();
	fnc3();
	printf("\n\n");

	//-----------------------

	int aaa = 0;
	auto j1 = [&aaa](int x, int y) {aaa = x + y; };
		//captura lui aaa e facuta prin referinta => poate fi modificata
	j1(10, 20);
	printf("aaa = %d\n", aaa); // aaa = 30
	

	//auto j2 = [aaa](int x, int y) {aaa = x + y; }; // -> nu functioneaza deoarece 
			// aaa nu are referinta si nu poate fi modificata intr-o lambda non-mutable
			//deci trebe ca lambda sa fie mutable...

	int bbb = 0;
	auto j2 = [bbb](int x, int y) mutable {bbb = x + y; };
		//nu se modifica valoarea lui bbb ptc n are &
	j2(10, 20);
	printf("bbb = %d\n", bbb); // aaa = 0
	printf("\n\n");


	//--------------------------------------
	int index = 0;
	auto counter = [index]()mutable ->int {return index++; };
	for (int tr = 0; tr < 10; tr++) {
		printf("%d ", counter()); // 0 1 2 3 4 5 6 7 8 9
	}
	printf("\n\n");


	return 0;
}