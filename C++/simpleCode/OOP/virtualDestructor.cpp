#include <iostream>
using namespace std;

/**
 * Виртуальный деструктор
 */

class A
{
public:
	A()
	{
		cout << "Dynamic memory is allocated, class A" << endl;
	}
	virtual ~A()
	{
		cout << "Dynamic memory is freed, class A" << endl;
	}

};
class B : public A
{
public:
	B()
	{
		cout << "Dynamic memory is allocated, class B" << endl;
	}
	~B() override
	{
		cout << "Dynamic memory is freed, class B" << endl;
	}
};

int main ()
{
	A *bptr = new B;
	delete bptr;
	return 0;
} 