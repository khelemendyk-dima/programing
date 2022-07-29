#include <iostream>
using namespace std;

// namespace
// пространство имен

namespace firstNS
{
	void Foo()
	{
		cout << "Foo firstNS" << endl;
	}
	int a;
	class Point
	{
	};
}

namespace secondeNS
{
	void Foo()
	{
		cout << "Foo secondNS" << endl;
	}
	int b;
	class Point
	{
	};
}

namespace thirdNS {
	namespace secondeNS
	{
		void Foo()
		{
			cout << "Foo thirdNS" << endl;
		}
	}
}

// using namespace secondeNS;

int main()
{
	firstNS::Foo();
	thirdNS::secondeNS::Foo();
	secondeNS::Foo();

	return 0;
}