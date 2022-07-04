#include <iostream>
#include <vector>
using namespace std;

// auto

int main()
{
	vector<int> v = { 1, 4, 33, 32, 564 };

	vector<int>::iterator it = v.begin();
	auto it2 = v.begin();

	for (auto el : v) {
		cout << el << endl; 
	}



	return 0;
}