#include <iostream>
using namespace std;

// дружественные функции
class Test;

class Point
{
private:
	int x;
	int y;
public:
	Point()
	{
		x = 0;
		y = 0;
		cout << this << " constructor" << endl;
	}
	Point(int valueX, int valueY)
	{
		x = valueX;
		y = valueY;
		cout << this << " constructor" << endl;
	}
	bool operator==(const Point &other)
	{
		return this->x == other.x && this->y == other.y;
	}
	bool operator!=(const Point &other)
	{
		return !(this->x == other.x && this->y == other.y);
	}
	Point operator+(const Point &other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}
	int GetX()
	{
		return x;
	}
	void SetX(int valueX)
	{
		x = valueX;
	}
	int GetY()
	{
		return y;
	}
	void SetY(int valueY)
	{
		y = valueY;
	}
	void Print()
	{
		cout << "x = " << x << "\t y = " << y << endl << endl;
	}
	Point &operator++()
	{
		this->x++;
		this->y += 1;
		return *this;
	}
	Point operator++(int value)
	{
		Point temp(*this);
		this->x++;
		this->y++;

		return temp;
	}
	Point &operator--()
	{
		this->x--;
		this->y -= 1;
		return *this;
	}
	Point operator--(int value)
	{
		Point temp(*this);
		this->x--;
		this->y--;

		return temp;
	}
	friend void ChangeX(Point &value, Test &testValue);
	void Change();
};
class Test
{
	private:
	int data = 0;
	friend void ChangeX(Point &value, Test &testValue);
};

void ChangeX(Point &value, Test &testValue)
{
	value.x = -1;
	testValue.data = 10;
}

int main ()
{
	Test test;
	Point a(5, 12);
	a.Print();
	ChangeX(a, test);
	a.Print();
	return 0;
}