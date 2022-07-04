#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// std::function


int Sum(int a, int b)
{
	return a + b;
}


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
void DoWork(vector<int> &vc, vector<function<void(int)>> funcVector)
{
	for (auto el : vc) {
		for (auto &fel : funcVector) {
			fel(el);
		}
	}
}

int main()
{
	// function<int(int, int)> s;
	// s = Sum;
	// cout << s(2, 3) << endl;

	vector<int> vc = { 1, 51, 3, 10, 44, 98, 8, 12, 22, 29, 49 };

	vector<function<void(int)>> fVector;
	fVector.emplace_back(Foo);
	fVector.emplace_back(Bar);
	fVector.emplace_back(Baz);
	
	DoWork(vc, fVector);

	return 0;
}