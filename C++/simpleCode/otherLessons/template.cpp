#include <iostream>
using namespace std;

// Шаблоны функций

template<typename T1, typename T2> void Sum(T1 a, T2 b)
{
	cout << a << endl;
	cout << b << endl;
}
int main ()
{
	Sum(1, "параметр");
	return 0;
}