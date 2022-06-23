#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Библиотека стандартных шаблонов (STL)
 * 
 * 			  Алгоритмы
 * 
 *     	  удаление элемента
 * 
 * 		   remove, remove_if
*/

class Person
{
	public:
	Person(string name, double score, int age)
	{
		this->Name = name;
		this->Score = score;
		this->Age = age;
	}
	bool operator()(const Person &p)
	{
		return p.Score > 180;
	}

	string Name;
	double Score;
	int Age;
};
int main ()
{
	vector<int> v = { 4, 4, 94, 6, 4, 2, 6 };

	// remove записывает все подходящие элементы(в данном случае 4) в конец вектора
	// и возвращает итератор, который указывает на последний не исключеный элемент
	// auto result = remove(v.begin(), v.end(), 4);
	// после можно удалить элементы вектор от указанного итератора до конца коллекции
	// v.erase(result, v.end());
	// for (auto el : v) {
	// 	cout << el << endl;
	// }

	vector<Person> people
	{
		Person("Vasya", 181, 17),
		Person("Petr", 30, 22),
		Person("Masha", 179, 19),
		Person("Dasha", 200, 26),
		Person("Katya", 198, 24),
		Person("Andriy", 181, 23),
		Person("Sergiy", 50, 30),
		Person("Ivan", 150, 40),
		Person("Ivan", 199, 53),
	};

	// также можно написать remove сразу в erase
	people.erase(remove_if(people.begin(), people.end(), [](const Person &p)
	{
		return p.Score < 150 || p.Age > 25;
	}), people.end());

	for (auto el : people) {
		cout << "Name:\t" << el.Name << "\tScore\t" << el.Score << "\tAge\t" << el.Age << endl;
	}

	return 0;
}