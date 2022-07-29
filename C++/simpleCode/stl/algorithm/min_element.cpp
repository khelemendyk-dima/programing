#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

/**
 * Библиотека стандартных шаблонов (STL)
 * 
 * 			  Алгоритмы
 * 
 * 		поиск наименьшего элемента
 * 
*/

int main ()
{
	// vector
	vector<int> v = { 10, 1, -55, 11, 13, 58 };
	auto resultV = min_element(v.begin(), v.end());
	cout << *resultV << endl;

	// list
	list<int> lst = { 4, 7, 77, -3, 44, 74 };
	auto resultL = min_element(lst.begin(), lst.end());
	cout << *resultL << endl;

	// array
	const int SIZE = 6;
	int arr[SIZE] = { 10, 1, -111, 11, 13, 60 };
	auto result = min_element(arr, arr + SIZE);
	cout << *result << endl;

	// minmax_element
	auto results = minmax_element(lst.begin(), lst.end());
	cout << *results.first << '\t' << *results.second << endl;

	return 0;
}