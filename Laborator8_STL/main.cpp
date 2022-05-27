#include <iostream>
#include <string>
#include <fstream>
#include <map> // map
#include <vector>
#include <queue> //priority_queue -> vector e default container
#include <utility> //pair

using namespace std;

string lower(string s)
{
	for (string::iterator it = s.begin(); it < s.end(); it++)
	{
		*it = tolower(*it);
	}
	return s;
}

class Comparare
{
public:
	bool operator()(pair<string, int> a, pair <string, int> b)
	{
		/*if (p1.second < p2.second)
			return true;
		if (p1.second > p2.second)
			return false;
		if (p1.first < p2.first)
			return false;
		return true;*/

		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second < b.second;
	}
};

int main()
{
	string s;
	ifstream fin("file.txt");
	getline(fin,s); // fin>>s
	
	map<string, int> m; // m = de cate ori apare un cuvant 

	int poz_initiala = 0, poz_finala = 0;
	poz_finala = s.find_first_of(" ,?!.");
	while (poz_finala != s.npos)
	{
		if (poz_finala > poz_initiala)
		{
			//cout << lower(s.substr(poz_initiala, poz_finala - poz_initiala)) << " ";
			m[lower(s.substr(poz_initiala, poz_finala - poz_initiala))] += 1;
		}
		poz_initiala = poz_finala + 1;
		poz_finala = s.find_first_of(" ,?!.", poz_initiala);
	}

	cout << endl;
	map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
		cout << it->first << " : " << it->second << endl;

	cout << "\n\n";

	priority_queue<pair<string, int>, vector<pair<string, int>>, Comparare> pq;
	for (auto it = m.begin(); it != m.end(); it++) {
		pq.push(pair<string, int>(it->first, it->second));
	}
	while (pq.empty() == false)
	{
		cout << pq.top().first << " => " << pq.top().second << endl;
		pq.pop();
	}
}
