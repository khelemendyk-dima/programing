#include <iostream>
using namespace std;

// обработка исключений 
// throw

void Foo(int value)
{
	if (value < 0) {	
		// throw runtime_error("Number is below 0..."); 
		// или
		throw logic_error("Number is below 0...");
	}
	cout << "Variable = " << value << endl;
}


int main()
{
	try
	{
		Foo(-55);
	}
	catch(const exception &ex)
	{
		std::cerr << "We catched " << ex.what() << '\n';
	}
	

	return 0;
}