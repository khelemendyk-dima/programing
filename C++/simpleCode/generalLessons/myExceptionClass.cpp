#include <iostream>
#include <string>
#include <exception>
using namespace std;

// создание собственных исключений

class MyException : public exception
{
private:
	int dataState;
public:
	MyException(char *msg, int dataState) : exception(runtime_error(msg))
	{
		this->dataState = dataState;
	}
	int GetDataState()
	{
		return dataState;
	}
};

void Foo(int value)
{
	if (value < 0) {	
		throw logic_error("Number is below 0");
	}
	if (value == 1) {
		throw MyException((char *)"Number is equal to 1", value);
	}
	cout << "Variable = " << value << endl;
}

int main()
{
	try
	{
		Foo(1);
	}
	catch(MyException &ex)
	{
		std::cerr << "Block 1 We catched " << ex.what() << endl;
		cout << "Data state " << ex.GetDataState() << endl;
	}

	return 0;
}