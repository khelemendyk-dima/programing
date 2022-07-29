#include <iostream>
#include <thread>
using namespace std;

// Многопоточное программирование
// Получение результатов работы функции из потока

int sum(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Thread's ID - " << this_thread::get_id() << " =========\tdoWork STARTED\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "Thread's ID - " << this_thread::get_id() << " =========\tdoWork STOPPED\t=========" << endl;
	return a + b;
}

int main()
{
	int result;
	thread th([&result]() { result = sum(3, 5); });

	for (size_t i = 0; i < 10; i++) {
		cout << "Thread's ID - " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	th.join();
	cout << "Sum results = " << result << endl;
	return 0;
}