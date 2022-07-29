#include <iostream>
#include <thread>
using namespace std;

// время выполнения участка кода

class SimpleTimer {
    public:
	SimpleTimer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~SimpleTimer()
	{
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		cout << "Duration " << duration.count() << " s" << endl;
	}

    private:
	std::chrono::time_point<std::chrono::_V2::system_clock> start, end;
};

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
	SimpleTimer st;
	int result = 0;
	thread t([&result]() { result = sum(2, 5); });

	for (size_t i = 1; i <= 10; i++) {
		cout << "Thread's ID - " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	t.join();
	cout << "Sum results = " << result << endl;
	return 0;
}