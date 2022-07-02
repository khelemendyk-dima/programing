#include <iostream>
#include <fstream>
using namespace std;

// чтение\сохранение объекта класса в файл

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
	void print()
	{
		cout << "X: " << x << "\tY: " << y << "\tZ: " << z << endl;
	}
	
};



int main()
{
	string path = "myFile.txt";
	// запись в файл
	// Point point(5, 10, 46);
	// point.print();

	// ofstream fout;
	// fout.open(path, ofstream::app);
	// if (!fout.is_open()) {
	// 	cout << "Error..." << endl;
	// } else {
	// 	cout << "File is opened" << endl;
	// 	fout.write((char *)&point, sizeof(Point)); // побайтово записывает объект в файл
	// }
	// fout.close();
	
	// чтение с файла
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		cout << "Error..." << endl;
	} else {
		cout << "File is opened" << endl;
		Point pnt;
		while (fin.read((char *)&pnt, sizeof(Point))) {
			pnt.print();
		}
	}
	fin.close();
	



	return 0;
}