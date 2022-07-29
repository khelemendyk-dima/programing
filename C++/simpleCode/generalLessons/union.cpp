#include <iostream>
using namespace std;

// union - хранит все переменные на одном участке памяти. Соответственно, 
// при изменении значения одной переменной - значения других переменных теряются.
// Union использовался в то время, когда у техники было мало памяти.

union MyUnion
{
	short int a;
	int b;
	float c;
};


int main()
{
	MyUnion u;
	u.a = 5;
	u.b = 30000;
	u.c = 32.45;


	return 0;
}