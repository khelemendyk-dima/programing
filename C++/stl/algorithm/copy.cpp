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
 * 
 * 		copy, copy_if
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

	vector<Person> result;

	// копирует все элементы одного вектора в другой
	// copy(people.begin(), people.end(), back_inserter(result));

	// копирует элементы одного вектора в другой при выполнении определенного условия
	copy_if(people.begin(), people.end(), back_inserter(result), [](const Person &p)
	{
		return p.Age > 25 && p.Score > 140;
	});
	sort(result.begin(), result.end(), [](const Person &p1, const Person &p2)
	{
		return p1.Name < p2.Name;
	});

	for (auto el : result) {
		cout << "Name:\t" << el.Name << "\tScore\t" << el.Score << "\tAge\t" << el.Age << endl;
	}

	return 0;
}