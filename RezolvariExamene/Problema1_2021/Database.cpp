#include "Database.h"
#include "Entry.h"
#include <string>
using namespace std;

Database& Database::operator+=(Entry* a) {
	this->entries.push_back(a);
	return *this;
}
Database& Database::operator-=(string name) {
	for (int it = 0; it < entries.size(); it++) {
		if (this->entries[it]->getName() == name) {
			this->entries.erase(this->entries.begin() + it);
		}
	}
	return *this;
}
vector<Entry*>::iterator Database::begin()
{
	return entries.begin();
}

vector<Entry*>::iterator Database::end()
{
	return entries.end();
}
void Database::Print()
{
	for (auto i = entries.begin(); i != entries.end(); i++)
	{
		(*i)->Print();
	}
	cout << endl;
}