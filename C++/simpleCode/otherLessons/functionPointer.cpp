#include <iostream>
using namespace std;

// Указатель на функцию 
// тип функции(*имя указателя)(спецификация параметров)

int Foo1(int a)
{
	return a * a;
}
int Foo2(int a)
{
	return a * 2;
}

string DataFromBD()
{
	return "Data From BD";
}
string DataFromWebServer()
{
	return "Data From WebServer";
}
void ShowInfo(string (*foo)())
{
	cout << foo() << endl;
}

int main ()
{
	// int (*fooPointer)(int a);
	// fooPointer = Foo1;
	// cout << fooPointer(5) << endl;
	// fooPointer = Foo2;
	// cout << fooPointer(10) << endl;
	ShowInfo(DataFromBD);
	ShowInfo(DataFromWebServer);
	return 0;
}