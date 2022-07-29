#include <iostream>
#include <thread>
using namespace std;

// Многопоточное программирование
// Передача параметров в поток

void doWork(int a, int b, string msg)
{
	cout << msg << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "=========\tdoWork STARTED\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "a + b = " << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "=========\tdoWork STOPPED\t=========" << endl;
}

int main()
{
	thread th(doWork, 2, 5, "our message");

	for (size_t i = 0; true; i++) {
		cout << "Thread's ID - " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	th.join();
	return 0;
}