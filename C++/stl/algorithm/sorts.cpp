#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Библиотека стандартных шаблонов (STL)
 * 
 * 			Алгоритмы
 * 
 *     		  SORT
*/

bool greaterThanZero(int a);
bool lessThanZero(int a);
class Person
{
	public:
	Person(string name, double score)
	{
		this->Name = name;
		this->Score = score;
	}
	bool operator()(const Person &p)
	{
		return p.Score > 180;
	}

	string Name;
	double Score;
};
int main ()
{
	// vector<int> v = { 9, 4, 94, 6, 1, 3, 7 };
	// обычная сортировка
	// sort(v.begin(), v.end());
	// сортировка с помощью анонимного предиката(лямбда-выражения)
	// sort(v.begin(), v.end(), [](int a, int b)
	// {
	// 	return a > b;
	// });

	// сортировка для обычного массива
	// const int SIZE = 7;
	// int arr[SIZE] = { 9, 4, 94, 6, 1, 3, 7 };
	// sort(arr, arr + SIZE);

	vector<Person> people
	{
		Person("Vasya", 181),
		Person("Petr", 30),
		Person("Masha", 179),
		Person("Dasha", 200),
		Person("Katya", 198),
		Person("Andriy", 181),
		Person("Sergiy", 50),
		Person("Ivan", 150),
	};
	sort(people.begin(), people.end(), [](const Person &p1, const Person&p2)
	{
		return p1.Score > p2.Score;
	});
	for (auto el : people) {
		cout << el.Name << "\t";
		cout << el.Score << endl;
	}
	return 0;
}
bool greaterThanZero(int a)
{
	return a > 0;
}
bool lessThanZero(int a)
{
	return a < 0;
}