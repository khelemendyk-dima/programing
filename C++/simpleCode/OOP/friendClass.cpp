#include <iostream>
using namespace std;

// дружественные методы класса

class Apple;

class Human
{
public:
	void takeApple(Apple &apple);
	void eatApple(Apple &apple)
	{
		apple.weight = 0;
	}
};
class Apple
{
	friend Human; // apple дружит с human
private:
	int weight;
	string color;
public:
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}
};

int main ()
{
	Apple apple(150, "Red");
	

	Human Dmytro;
	Dmytro.takeApple(apple);
	return 0;
}
void Human::takeApple(Apple &apple)
{
	cout << "takeApple " << "weight = " << apple.weight << " color = " << apple.color << endl;
}