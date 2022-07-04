#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// лямбда-функции


void Foo(int a)
{
	if (a > 10 && a < 40) {
		cout << "Foo " << a << endl;
	}
}
void Bar(int a)
{
	if (a % 2 == 0) {
		cout << "Bar " << a << endl;
	}
}
void Baz(int a)
{
	cout << "Baz" << endl;
}
void DoWork(vector<int> &vc, function<void(int)> func)
{
	for (auto el : vc) {
			func(el);
	}
}

int main()
{

	vector<int> vc = { 1, 51, 4, 10, 44, 98, 8, 22, 12, 43 };
	DoWork(vc, [](int a) 
	{
		if (a % 2 == 0) {
			cout << "Lambda " << a << endl;
		}
	});


	int p;
	auto f = [&p]()
	{
		p = 5;
		cout << p << endl;
	};
	f();



	auto func = []()
	{
		return 1.123;
	};

	auto q = func();

	return 0;
}