#include <iostream>
using namespace std;

// static. Статические методы класса.
// позволяет получить значение к приватному статическому полю

class Apple
{
private:
	static int count;
	int weight;
	string color;
	int id;
public:

	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		count++;
		id = count;
	}
	int GetWeight()
	{
		return weight;
	}
	void SetWeight(int weight)
	{
		this->weight = weight;
	}
	string GetColor()
	{
		return color;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	int GetId()
	{
		return id;
	}
	// статический метод
	static int GetCount()
	{
		return count;
	}
	static void ChangeColor(Apple &apple, string color)
	{
		apple.color = color;
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
	// cout << apple.count << endl;
	// cout << apple2.GetId() << endl;
	// cout << Apple::GetCount() << endl;
	apple.ChangeColor(apple, "yellow");
	Apple::ChangeColor(apple3, "red");


	return 0;
}