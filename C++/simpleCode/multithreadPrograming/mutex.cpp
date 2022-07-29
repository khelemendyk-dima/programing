#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

/**
 * Многопоточное программирование
 * 
 * 			  mutex
 * 
 * 	защита разделяемых данных
 * 	  синхронизация потоков
 */

// mutex блокирует доступ к коду другим потокам при использовании этого
// кода одним потоком
mutex mtx;

void printRectangle(char ch)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	mtx.lock();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;
	mtx.unlock();
	this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
	thread t1(printRectangle, '*');
	thread t2(printRectangle, '#');

	t1.join();
	t2.join();
	return 0;
}