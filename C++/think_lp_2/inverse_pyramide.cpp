// перевернутая пирамида

#include <iostream>
using namespace std;

int main()
{
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