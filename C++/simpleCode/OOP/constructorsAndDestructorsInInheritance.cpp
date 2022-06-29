#include <iostream>
using namespace std;

// Порядок вызова конструкторов при наследовании с++

class A
{
public:
	A()
	{
		cout << "Constructor A is called" << endl;
	}
	~A()
	{
		cout << "Destructor A is called" << endl;
	}
};
class B : public A
{
public:
	// конструктор класса В вызывает по конструктор по умолчанию класса А,
	// но если мы хочем вызвать другой конструктор класса А, то должны 
	// использовать другую запись:
	// B() : A(int value) {...}
	// запись по-умолчанию(которую неявно указывает компилятор): B() : A()
	B()
	{
		cout << "Constructor B is called" << endl;
	}
	~B()
	{
		cout << "Destructor B is called" << endl;
	}
};
class C : public B
{
public:
	C()
	{
		cout << "Constructor C is called" << endl;
	}
	~C()
	{
		cout << "Destructor C is called" << endl;
	}
};



int main ()
{
	C c;
	return 0;
}