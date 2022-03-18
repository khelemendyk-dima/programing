#include <iostream>
#include <ctime>
using namespace std;

int askNumber(string query);
int akkermanR(int n, int m);
int akkermanI(int n, int m);

int main()
{
	int n = askNumber("Input n: ");
	int m = askNumber("Input m: ");
	clock_t start1 = clock();
	int resultR = akkermanR(n, m);
	clock_t end1 = clock();
	double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	cout << "Result of recursion: " << resultR << endl;
	cout << "Recursion function execution time: " << seconds1 << endl;
	clock_t start2 = clock();
	int resultI = akkermanI(m, n);
	clock_t end2 = clock();
	double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
	cout << "Result of iteration: " << resultI << endl;
	cout << "Iteration function execution time: " << seconds2 << endl;
	return 0;
}

int askNumber(string query)
{
	int number;
	cout << query;
	cin >> number;
	return number;
}
int akkermanR(int n, int m)
{
	if (n == 0)
		return m + 1;
	else
	{
		if ( (n != 0) && (m == 0) )
			return akkermanR(n - 1, 1);
		else
			return akkermanR(n - 1, akkermanR(n, m - 1));
	}
}
int akkermanI(int n, int m) {
	int value[n];
	int size = 0;

	for (;;)
	{
		if (m == 0)
		{
			n++;
			if (size-- == 0)
			{
				break;
			}
			m = value[size];
			continue;
		}
		if (n == 0)
		{
			m--;
			n = 1;
			continue;
		}
		int index = size++;
		value[index] = m - 1;
		n--;
	}
	return n;
}
