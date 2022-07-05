#include <iostream>
using namespace std;

// Интерфейс - это те публичные методы, с помощью которых вы можете 
// взаимодействовать с какой-то сущностью. В интерфейсе не может быть реализации
// То есть интерфейс - это абстрактный класс, который имеет только чисто виртуальные функции

class IBicycle
{
public:
	virtual void TwistTheWheel() = 0;
	virtual void Ride() = 0;
};
class SimpleBicycle : public IBicycle
{
public:
	void TwistTheWheel() override
	{
		cout << "method TwistTheWheel() SimpleBicycle" << endl;
	}
	void Ride() override
	{
		cout << "method Ride() SimpleBicycle" << endl;
	}
};
class SportBicycle : public IBicycle
{
public:
	void TwistTheWheel() override
	{
		cout << "method TwistTheWheel() SportBicycle" << endl;
	}
	void Ride() override
	{
		cout << "method Ride() SportBicycle" << endl;
	}
};

class Human
{
public:
	void RideOn(IBicycle &bicycle)
	{
		cout <<  "Twist the wheel!" << endl;
		bicycle.TwistTheWheel();
		cout << endl << "Lesssggooo!!!" << endl;
		bicycle.Ride();
	}
};

int main()
{
	SimpleBicycle sb;
	SportBicycle sportB;

	Human h;
	h.RideOn(sportB);

	return 0;
}