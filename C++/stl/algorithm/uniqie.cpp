#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Библиотека стандартных шаблонов (STL)
 * 
 * 			  Алгоритмы
 * 
 *   удалить повторяющиеся элементы
 * 
 * 		unique, unique_copy
 * 
*/
int main ()
{
	vector<int> v = { 1, 2, 2, 2, 5, 4, 4 };
	vector<int> v2;

	// сортирует элементы определенным образом(все дубликаты отправляются в конец коллекции, 
	// в данном примере: 1, 2, 5, 4, 2, 2, 4 и возвращает итератор на элемент со значением 4)
	// auto result = unique(begin(v), end(v));
	// v.erase(result, v.end());

	// копирует уникальные элементы в другую коллекцию
	unique_copy(begin(v), end(v), back_inserter(v2));

	for (auto a : v2) {
		cout << a << endl;
	}


	return 0;
}