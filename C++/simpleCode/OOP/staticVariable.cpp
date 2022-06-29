#include <iostream>
using namespace std;

// static. Статические поля класса.
// Статическая переменная хранится в одной области памяти для всех объектов.
// При изменении этой переменной в одном объекте, она изменится и в других объектах
// static часто используется для идентификатора id

class Apple
{
private:
	int weight;
	string color;
	size_t id;
public:
	static int count;

	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		count++;
		id = count;
	}
	size_t GetId()
	{
		return id;
	}
};
// инициализация статической переменной 
int Apple::count = 0;


int main ()
{
	Apple apple(150, "Red");
	Apple apple2(100, "Green");
	Apple apple3(200, "Yellow");
	// cout << Apple::count << endl;
	cout << apple.count << endl;
	cout << apple2.GetId() << endl;


	return 0;
}