#include <iostream>
using namespace std;

// несколько блоков catch

void Foo(int value)
{
	if (value < 0) {	
		throw "Number is below 0";
	}
	if (value == 0) {
		// throw runtime_error("Number is equal 0..."); 
		// или
		throw logic_error("Number is equal 0...");
	}
	if (value == 1) {
		throw 1;
	}
	cout << "Variable = " << value << endl;
}


int main()
{
	try
	{
		Foo(1);
	}
	catch(const exception &ex)
	{
		std::cerr << "Block 1 We catched " << ex.what() << endl;
	}
	catch(const char *ex)
	{
		std::cerr << "Block 2 We catched " << ex << endl;
	}
	catch(...)
	{
		std::cerr << "Block ... Something went wrong!" << endl;
	}
	

	return 0;
}