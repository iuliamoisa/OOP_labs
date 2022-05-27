#include <iostream>
#include <string>
#include <list>
using namespace std;

struct YoutubeChannel {
	//members are public by default
	string Name;
	int SubscribersCount;

	YoutubeChannel(string name, int subscribersCount) {
		// constructor
		Name = name;
		SubscribersCount = subscribersCount;
	} 
	bool operator==(const YoutubeChannel& channel) const{
		return this->Name == channel.Name;
	}
};

ostream& operator<<(ostream& COUT, YoutubeChannel& ytChannel) {
	//INSERTION OPERATOR
	//prints info about yt channel
	COUT << "Name: " << ytChannel.Name << endl;
	COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;
	return COUT;
}

struct MyCollection {
	list<YoutubeChannel>myChannels;

	void operator+=(YoutubeChannel& channel) {
		this->myChannels.push_back(channel); //it is a member function!
	}

	void operator-=(YoutubeChannel& channel) {
		this->myChannels.remove(channel); //it is a member function!
	}
};
ostream& operator<<(ostream& COUT, MyCollection& myCollection) {
	for (YoutubeChannel ytChannel : myCollection.myChannels) // for each ytChannel inside myCOllection, inside myChannels
		COUT << ytChannel << endl;
	return COUT; // return ptc avem ostream in fata
}

int main()
{
	YoutubeChannel yt1 = YoutubeChannel("CodeFun", 10000);
	YoutubeChannel yt2 = YoutubeChannel("EatHealthy", 12345);
	cout << yt1; // cout = operator 1, yt1 = operator2 -> more common approach
	//operator<<(cout, yt1); -> less common approach

	MyCollection myCollection;
	myCollection += yt1;// add yt channel to myCollection
	myCollection += yt2;
	myCollection -= yt2; //remove element from myCollection; we need to overload the -= operator
	cout << myCollection; //inprinted info ab myCollection

	return 0;

}