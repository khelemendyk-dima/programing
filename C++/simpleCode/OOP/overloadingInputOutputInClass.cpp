#include <iostream>
#include <fstream>
using namespace std;

// перегрузка операторов потокового ввода вывода

class Point
{
private:
	int x;
	int y;
	int z;
public:
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
	friend ostream& operator<<(ostream& os, const Point &point);
	friend istream& operator>>(istream& is, Point &point);
};
ostream& operator<<(ostream& os, const Point &point)
{
	os << point.x << " " << point.y << " " << point.z;
	return os;
}
istream& operator>>(istream& is, Point &point)
{
	is >> point.x >> point.y >> point.z;
	return is;
}


int main()
{
	// Point p(122, 234, 564);
	// cout << p << endl;
	string path = "myFile.txt";
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open()) {
		cout << "Error..." << endl;
	} else {
		cout << "File is opened" << endl;
		// fs << p << endl;	
		while (true) {
			Point p;
			fs >> p;
			if (fs.eof()) {
				break;
			}
			cout << p << endl;
		}
	}
	fs.close();

	return 0;
}