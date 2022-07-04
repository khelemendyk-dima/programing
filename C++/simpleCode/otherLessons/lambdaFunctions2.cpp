#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// лямбда-функции
// захват переменных в контекст

class MyClass
{
public:
	int a = 11;
	void Msg()
	{
		cout << "msg" << endl;
	}

	void Lampda()
	{
		auto f = [this]()
		{
			this->Msg();
		};
		f();	
	}
};	

int main()
{
	int a = 55;
	int b = 10;
	// знак = позволяет работать со всеми переменными, но не изменять их значение,
	// а амперсанд & позволяет работать со всеми переменными по ссылке
	// слово mutable может изменить значение переменных в функции, но не вне её
	// auto f = [&]()
	// auto f = [&a, b]()
	// auto f = [&a, b]() mutable
	// {
	// 	cout << a << endl;
	// 	a = 1313;
	// 	cout << b << endl;
	// 	b = 11;
	// };
	// f();

	// MyClass m;
	// m.Lampda();


	// можно принудительно указать тип возвращаемого значения
	auto f = []()->float
	{

		return 111;
	};
	f();

	auto q = f();

	return 0;
}