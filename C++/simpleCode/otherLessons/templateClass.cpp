#include <iostream>
using namespace std;

// шаблоны классов

class Point
{
public:
	int x;
	int y;
	int z;
	Point()
	{
		x = y = z = 0;
	}
	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}		
};
template<typename T1, typename T2>
class MyClass
{
private:
	T1 value;
	T2 value2;
public:
	MyClass(T1 value, T2 value2)
	{
		this->value = value;
		this->value2 = value2;
	}
	void dataTypeSize()
	{
		cout << "value " << sizeof(value) << endl;
		cout << "value2 " << sizeof(value2) << endl;
	}
};



int main()
{
	Point p;
	int a = 5;
	MyClass<int, Point> c(a, p);
	c.dataTypeSize();

	return 0;
}