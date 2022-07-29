#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

/**
 * Библиотека стандартных шаблонов (STL)
 * 
 * 			  Алгоритмы
 * 
 *   сортировка массива в случайном порядке
 * 
 * 		     random_shuffle
 * 
*/

int main ()
{
	srand(time(NULL));

	int arr[] = { 1, 2, 3, 4, 5 };

	random_shuffle(begin(arr), end(arr));

	for (auto a : arr) {
		cout << a << endl;
	}

	return 0;
}