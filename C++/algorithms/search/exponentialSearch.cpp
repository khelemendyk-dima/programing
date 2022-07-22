#include <iostream>
using namespace std;

const int N = 10;

int exponentialSearch(int arr[], int key)
{
	int i = 1;
	while (i < N && arr[i] < key)
		i *= 2;

	int m = 0;
	int b = i / 2;
	int e = (i + 1 < N) ? i + 1 : N;
	while (b <= e) {
		m = (b + e) / 2;
		if (arr[m] >= key)
			e = m - 1;
		else
			b = m + 1;
	}
	if (arr[b] == key) 
		return b;
	else
		return -1;
}

int main()
{
	int myarr[N] = { 1, 7, 9, 25, 30, 33, 41, 53, 60, 66 };
	int num = 33;
	int output = 0;


	output = exponentialSearch(myarr, num);

	if (output == -1) {
		cout << "No Match Found" << endl;
	} else {
		cout << "Match found at position: " << output << endl;
	}

	return 0;
}