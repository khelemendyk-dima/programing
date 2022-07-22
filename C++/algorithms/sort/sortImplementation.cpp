#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v = { 54, 44, 43, 40, 33, 25, 2 };
	sort(v.begin(), v.end());
	for(auto el : v) {
		cout << el << ' ';
	}
	return 0;
}