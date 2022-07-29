#include <iostream>
#include <thread>
using namespace std;

// Многопоточное программирование
// Получение результатов работы функции из потока

void doWork(int &a)
{
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "Thread's ID - " << this_thread::get_id() << " =========\tdoWork STARTED\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	a *= 2;
	cout << "Thread's ID - " << this_thread::get_id() << " =========\tdoWork STOPPED\t=========" << endl;
}

int main()
{
	int q = 5;

	thread th(doWork, std::ref(q));

	for (size_t i = 0; i < 10; i++) {
		cout << "Thread's ID - " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	th.join();
	cout << q << endl;
	return 0;
}