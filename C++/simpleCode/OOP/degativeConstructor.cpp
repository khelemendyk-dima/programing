#include <iostream>
using namespace std;

/**
 * Делигирующий конструктор
 */

class Human
{
public:
	string name;
	int age;
	int weight;

	Human(string name)
	{
		this->name = name;
		this->age = 0;
		this->weight = 0;
	}
	Human(string name, int age) : Human(name)
	{
		this->age = age;
	}
	Human(string name, int age, int weight) : Human(name, age)
	{
		this->weight = weight;
	}
};

int main ()
{
	Human h("Ivan", 30, 70);


	return 0;
} 