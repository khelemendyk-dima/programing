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
 * 	 сравнить две последовательности
 * 
 *     		equal и mismatch
 * 
*/

class Point
{
	public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int x;
	int y;
};

int main ()
{
	// vector<int> arr = { 11, 3, 4, 5, 7, 10 };
	// vector<int> arr2 = { 11, 3, 4, 5, 7, 10 };

	//сравнивает две коллекции, возвращает бул, сравнивает элементы по индексно
	// bool result = equal(begin(arr), end(arr), begin(arr2), end(arr2));

	//  EQUAL WITH PREDICATE
	vector<Point> arr
	{
		Point(1, 3),
		Point(4, 5),
		Point(5, 7),
	};
	vector<Point> arr2
	{
		Point(1, 3),
		Point(4, 5),
		Point(5, 7),
	};
	bool result = equal(begin(arr), end(arr), begin(arr2), end(arr2), [](const Point &p1, const Point &p2)
	{
		return (p1.x == p2.x) && (p1.y == p2.y);
	});

	cout << result << endl;

	// mismatch возвращает пару итераторов, которые указывают какие элементы не равны
	// result.first будет указывать на элемент первого вектора, а second - второго
	// auto result = mismatch(begin(arr), end(arr), begin(arr2));
	// if (result.first == end(arr) && result.second == end(arr2)) {
	// 	cout << '+' << endl;
	// } else {
	// 	cout << '-' << endl;
	// }
	// cout << *result.first << endl; 
	// cout << *result.second << endl; 

	return 0;
}