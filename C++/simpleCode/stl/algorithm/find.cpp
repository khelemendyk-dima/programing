#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Библиотека стандартных шаблонов (STL)
 * 
 * 			Алгоритмы
 * 
 *     		  Поиск
 * find, find_if, find_if_not
*/

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
	vector<int> v = { 4, 4, 94, 6, 4, 2, 6 };

	// проверяет присутствует ли какой-то элемент в коллекции
	// auto it = find(v.begin(), v.end(), 0);

	// проверяет если есть какой-то элемент исходя из предиката
	// auto result = find_if(v.begin(), v.end(), [](int a)
	// {
	// 	return a > 0;
	// });

	// инвертирует ответ find_if (из тру в фолс и наоборот)
	// auto result = find_if_not(v.begin(), v.end(), [](int a)
	// {
	// 	return a > 0;
	// });

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
	auto result = find_if(people.begin(), people.end(), [](const Person &p)
	{
		return p.Name == "Petr" || p.Score == 51;
	});

	if (result != people.end()) {
		cout << "+" << endl;
	} else {
		cout << "-" << endl;
	}

	return 0;
}