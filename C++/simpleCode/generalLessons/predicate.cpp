#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Предикаты
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


	int result = count_if(people.begin(), people.end(), people.front());
	cout << result << endl;


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
