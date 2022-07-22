#include <iostream>
using namespace std;

const int N = 10;

int interpolSearch(int arr[], int key)
{
	int m = 0;
	int b = 0;
	int e = N - 1;
	while (arr[b] <= key && arr[e] >= key) {
		m = b + ((key - arr[b]) * (e - b)) / (arr[e] - arr[b]);
		if (arr[m] < key) {
			b = m + 1;
		} else if (arr[m] > key) {
			e = m - 1;
		} else {
			return m;
		}
	}
	if (arr[b] == key) {
		return b;
	} else {
		return -1;
	}
}

int main() {
	int myarr[N] = { 1, 7, 9, 25, 30, 33, 41, 53, 60, 66 };
	int num = 33;
	int output = 0;


	output = interpolSearch(myarr, num);

	if (output == -1) {
		cout << "No Match Found" << endl;
	} else {
		cout << "Match found at position: " << output << endl;
	}

	return 0;
}