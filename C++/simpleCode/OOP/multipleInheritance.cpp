#include <iostream>
using namespace std;

// Множественное наследование

class Car
{
public:
	string str = "Car's field";
	void use()
	{
		cout << "I'm driving!" << endl;
	}
};
class Airplane
{
public:
	string str2 = "Plane's field";
	void use()
	{
		cout << "I'm flying!" << endl;
	}
};
class FlyingCar : public Car, public Airplane
{
public:

};

int main()
{
	FlyingCar fc;
	// fc.drive();
	// fc.fly();

	// Car *ptrC = &fc;
	// Airplane *ptrA = &fc;
	
	// ((Car)fc).use();
	fc.::Airplane::use();

	return 0;
}