#include <iostream>
#include <typeinfo>
using namespace std;

// наследование шаблонов

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
template<typename T>
class TypeSize
{
protected:
	T value;
public:
	TypeSize(T value)
	{
		this->value = value;
	}
	void dataTypeSize()
	{
		cout << "value " << sizeof(value) << endl;
	}
};
template<typename T>
class TypeInfo : public TypeSize<T>
{
public:
	TypeInfo(T value) : TypeSize<T>(value)
	{
	}
	void showTypeName()
	{
		cout << "Type name: " << typeid(this->value).name() << endl;
	}
};

int main()
{
	int a = 5;
	TypeInfo<int> c(a);
	c.showTypeName();
	c.dataTypeSize();
	return 0;
}