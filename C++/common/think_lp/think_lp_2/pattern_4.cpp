// romb

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
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            cout << ' ';
        }
        cout << '#';
        for (int p = 0; p < i * 2; p++)
        {
            cout << '*';
        }
        cout << '#';
        cout << '\n';
    }
}
void secondHalfPattern()
{
	int temp = 8;
	for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        cout << '#';
        for (int p = 0; p < temp; p++)
        {
            cout << '*';
        }
        cout << '#';
		temp -= 2;
        cout << '\n';
    }
}