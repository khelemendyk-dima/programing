#include <iostream>
using namespace std;

// Спецификаторы доступа при наследовании

class A
{
public:
	string msgOne = "Message one";

private:
	string msgTwo = "Message two";

protected:
	string msgThree = "Message three";

};
class B : protected A
{
public:
	void printMsg()
	{
		cout << msgOne << endl;
	}

};


int main ()
{
	B b;
	b.printMsg();

	return 0;
}