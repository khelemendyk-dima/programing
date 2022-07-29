#include <iostream>
#include <fstream>
using namespace std;

// обработка исключений try catch

int main()
{
	string path = "myFile.txt";
	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
		cout << "Trying to open file!" << endl;
	
		fin.open(path);
		
		cout << "File is opened!" << endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
		std::cerr << "Error opening file!" << endl;
	}
	
	return 0;
}