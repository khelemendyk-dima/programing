#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Библиотека стандартных шаблонов (STL)
 * 
 * 			  Алгоритмы
 * 
 *  		   for_each
 * 
*/
int main ()
{
	int arr[] = { 1, 2, 10, 55 };

	// выполняет функцию для каждого элемента коллекции
	for_each(begin(arr), end(arr), [](int a)
	{
		cout << a << endl;
	});

	// альтернатива for_each
	// for (auto a : arr) {
		// cout << a << endl;
	// }

	return 0;
}