#include <iostream>
#include <mutex>
#include <thread>
#include "simpleTimer.h"
using namespace std;

/**
 *   Многопоточное программирование
 * 
 *			unique_lock
 * 
 * 	   защита разделяемых данных
 *		 синхронизация потоков
 */

mutex mtx;

void printRectangle(char ch)
{
	// при добавлении вторым аргументом defer_lock - не начнется синхронизация
	// unique_lock работает также как и lock_guard, но может блокировать и 
	// разблокировать перманентный поток
	unique_lock<mutex> ul(mtx, defer_lock);
	
	// unique_lock<mutex> ul(mtx);
	this_thread::sleep_for(chrono::milliseconds(2000));
	ul.lock();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
	ul.unlock();
	this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
	SimpleTimer st;
	thread t1(printRectangle, '*');
	thread t2(printRectangle, '#');

	t1.join();
	t2.join();
	return 0;
}