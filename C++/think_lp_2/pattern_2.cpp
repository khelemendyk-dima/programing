// pattern

#include <iostream>
using namespace std;

int main()
{
	cout << "\n";
	cout << "##\n";
	for (int i = 2; i < 5; i++)
	{
		for (int p = 0; p < 4 - i; p++)
		{
			cout << ' ';
		}
		for (int j = 0; j < i * 2; j++)
		{
			cout << '#';
		}
		cout << '\n';
	}
	// inverse pyramide
	for (int i = 0; i < 4; i++)
	{
		for (int p = 0; p < i; p++)
		{
			cout << ' ';
		}
		for (int j = 0; j < (4 - i) * 2; j++)
		{
			cout << '#';
		}
		cout << '\n';
	}
	cout << '\n';
	return 0;
}

