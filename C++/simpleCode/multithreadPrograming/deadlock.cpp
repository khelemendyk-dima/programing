#include <iostream>
#include <mutex>
#include <thread>
#include "simpleTimer.h"
using namespace std;

/**
 *   Многопоточное программирование
 * 
 *  Взаимная блокировка или Deadlock
 * 
 * 	   защита разделяемых данных
 * 	     синхронизация потоков
 */

mutex mtx1;
mutex mtx2;

void printRectangle()
{
	mtx2.lock();
	
	this_thread::sleep_for(chrono::milliseconds(1));
	
	mtx1.lock();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cout << '*';
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;

	mtx1.lock();

	mtx2.lock();
}

void printRectangle2()
{
	mtx1.lock();
	
	this_thread::sleep_for(chrono::milliseconds(1));
	
	mtx2.lock();
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cout << '#';
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;

	mtx1.lock();

	mtx2.lock();
}

int main()
{
	SimpleTimer st;
	thread t1(printRectangle);
	thread t2(printRectangle2);

	t1.join();
	t2.join();
	return 0;
}