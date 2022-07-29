#include <iostream>
#include <thread>
using namespace std;

// Многопоточное программирование
// Запуск метода класса в отдельном потоке

class MyClass {
    public:
	void doWork()
	{
		this_thread::sleep_for(chrono::milliseconds(2000));

		cout << "Thread's ID - " << this_thread::get_id() << " =========\tdoWork STARTED\t=========" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));

		cout << "Thread's ID - " << this_thread::get_id() << " =========\tdoWork STOPPED\t=========" << endl;
	}
	void doWork2(int a)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));

		cout << "Thread's ID - " << this_thread::get_id() << " =========\tdoWork2 STARTED\t=========" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));

		cout << "doWork2 value of the parametr: " << a << endl;

		cout << "Thread's ID - " << this_thread::get_id() << " =========\tdoWork2 STOPPED\t=========" << endl;
	}
	int sum(int a, int b)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));

		cout << "Thread's ID - " << this_thread::get_id() << " =========\tdoWork STARTED\t=========" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));

		cout << "Thread's ID - " << this_thread::get_id() << " =========\tdoWork STOPPED\t=========" << endl;
		return a + b;
	}
};

int main()
{
	// int result;
	MyClass m;

	// thread t([&]() { result = m.sum(2, 5); });
	// thread t(&MyClass::doWork, m);
	thread t(&MyClass::doWork2, m, 5);
	for (size_t i = 1; i <= 10; i++) {
		cout << "Thread's ID - " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	t.join();
	// cout << "RESULT\t" << result << endl;
	return 0;
}