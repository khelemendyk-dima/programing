#include <iostream>
using namespace std;

// for each loop
// range-based loops

int main()
{
	int arr[] = { 1, 4, 33, 32, 564 };

	// for(auto el : arr) {
	// 	cout << el << endl;
	// }
	// for(auto &el : arr) {
	// 	el = -1;
	// 	cout << el << endl;
	// }
	for (const auto &el : arr) {
		cout << el << endl;
	}
	return 0;
}