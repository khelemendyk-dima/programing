#include <iostream>
using namespace std;

// дружественные методы класса

class Apple;

class Human
{
public:
	void takeApple(Apple &apple);
};
class Apple
{
private:
	int weight;
	string color;
public:
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}
	friend void Human::takeApple(Apple &apple);
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