#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

// чтение/запись в файл с помощью fstream

int main()
{
	string path = "myFile.txt";
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open()) {
		cout << "Error..." << endl;
	} else {
		string msg;
		int value;
		cout << "File is opened" << endl;
		cout << "Input 1 for writting data to file: " << endl;
		cout << "Input 2 for reading data from file: " << endl;
		cin >> value;
		if (value == 1) {
			cout << "Input your message: " << endl;
			SetConsoleCP(1251);
			cin >> msg;
			fs << msg << "\n";
			SetConsoleCP(866);
		}
		if (value == 2) {
			cout << "Reading messages..." << endl;
			while (!fs.eof()) {
				msg = "";
				fs >> msg;
				cout << msg << endl;
			}
		}
	}
	fs.close();
	



	return 0;
}