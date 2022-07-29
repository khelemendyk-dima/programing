#include <iostream>
#include <mutex>
#include <thread>
#include "simpleTimer.h"
using namespace std;

/**
 * Многопоточное программирование
 * 
 * 			  lock_guard
 * 
 * 	   защита разделяемых данных
 * 	     синхронизация потоков
 */

mutex mtx;

void printRectangle(char ch)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	// lock_guard в конструкторе блокирует поток с помощью mutex
	// и открывает поток в деструкторе
	{
		lock_guard<mutex> guard(mtx);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 10; j++) {
				cout << ch;
				this_thread::sleep_for(chrono::milliseconds(20));
			}
			cout << endl;
		}
		cout << endl;
	}
	this_thread::sleep_for(chrono::milliseconds(2000));	
}

int main()
{
	SimpleTimer st;
	thread t1(printRectangle, '*');
	thread t2(printRectangle, '#');
	thread t3(printRectangle, '@');

	t1.join();
	t2.join();
	t3.join();
	return 0;
}