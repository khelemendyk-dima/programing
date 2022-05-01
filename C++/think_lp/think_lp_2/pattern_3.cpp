// pattern

#include <iostream>
using namespace std;

void firstHalfPattern();
void secondHalfPattern();

int main()
{
	firstHalfPattern();
	secondHalfPattern();
	return 0;
}

void firstHalfPattern()
{
	int temp = 12;
	for (int i = 1; i < 5; i++)
	{
		for (int p = 1; p < i; p++)
		{
			cout << ' ';
		}
		for (int j = 0; j < i; j++)
		{
			cout << '#';
		}
		for (int k = 0; k < temp; k++)
		{
			cout << ' ';
		}
		for (int l = 0; l < i; l++)
		{
			cout << '#';
		}
		temp -= 4;
		cout << '\n';
	}
}
void secondHalfPattern()
{
	int temp = 0;
	for (int i = 1; i < 5; i++)
	{
		for (int k = 1; k < 5 - i; k++)
		{
			cout << ' ';
		}
		for (int l = 0; l < 5 - i; l++)
		{
			cout << '#';
		}
		for (int p = 0; p < temp; p++)
		{
			cout << ' ';
		}
		for (int j = 0; j < 5 - i; j++)
		{
			cout << '#';
		}
		temp += 4;
		cout << '\n';
	}
}