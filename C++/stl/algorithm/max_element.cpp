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
 * 		поиск наибольшего элемента
 * 
*/

int main ()
{
	// vector
	vector<int> v = { 10, 1, -55, 11, 13, 58 };
	auto resultV = max_element(v.begin(), v.end());
	cout << *resultV << endl;

	// list
	list<int> lst = { 4, 7, 77, -3, 44, 74 };
	auto resultL = max_element(lst.begin(), lst.end());
	cout << *resultL << endl;

	// array
	const int SIZE = 6;
	int arr[SIZE] = { 10, 1, -55, 11, 13, 60 };
	auto result = max_element(arr, arr + SIZE);
	cout << *result << endl;

	return 0;
}