// Утраченный клад
// Персонализированная приключенческая игра

#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int GOLD_PIECES = 900;
	int adventurers, killed, survivors;
	string leader;
	cout << "\nWelcome to Lost Fortune" << endl;
	cout << "Please enter the following for your personalized adventure" << endl;
	cout << "Enter a number: ";
	cin >> adventurers;
	cout << "Enter a number, smaller than the first: ";
	cin >> killed;
	cout << "Enter your last name: ";
	cin >> leader;
	survivors = adventurers - killed;
	cout << "\nA brave group of " << adventurers << " set out on a quest ";
	cout << "-- in search of the lost treasure of the Ancient Dwarves. ";
	cout << "The group was led by that legendary rogue, " << leader << "." << endl;
	cout << "\nAlong the way, a band of marauding ogres ambushed the party. ";
	cout << "All fought bravely under the command of " <<  leader << ", and the agres ";
	cout << "were defeated, but at a cost. Of the adventurers, " << killed;
	cout << " were vanquished, leaving just " << survivors << " in the group." << endl;
	cout << "\nThe party was about to give up all hope. But while laying the ";
	cout << "deceased to rest, they stumbled upon the buried fortune. So the adventurers ";
	cout << "split " << GOLD_PIECES << " gold pieces. " << leader << " held on to the ";
	cout << "extra " << GOLD_PIECES % survivors << " pieces to keep things fair of course.";
	return 0;
}