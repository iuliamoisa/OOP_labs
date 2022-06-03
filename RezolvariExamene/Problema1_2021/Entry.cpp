#include "Entry.h"
#include <iostream>
using namespace std;

Entry::Entry() {

}
Entry::Entry(string name) {
	this->name = name;
}
string Entry::getName() {
	return this->name;
}
