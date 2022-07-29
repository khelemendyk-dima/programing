#include <iostream>
#define PI 3.14
#define tab "\t"
#define begin {
#define end }
#define FOO(x, y) ((x)*(y))
using namespace std;

/**
 * Препроцессор - это программа, которая проводит некоторые манипуляции с кодом 
 * до того как он скомпилируется. Некая предобработка кода. #include является препроцессором.
 * #define
 * макрос функция
 * 
 */


int main ()
{
	cout << PI << endl;
	// компилятор видит эту запись так:
	// cout << 3.14 << endl;

	cout << "text" << tab << "text" << endl;

	for (int i = 0; i < 5; i++)
	begin
		cout << i << endl;
	end
	// macros function
	cout << "MACROS" << endl;	
	cout << FOO(5,6) << endl;




	return 0;
}