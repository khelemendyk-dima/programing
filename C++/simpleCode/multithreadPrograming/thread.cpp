#include <iostream>
#include <thread>
#include <ctime>
using namespace std;

// Многопоточное программирование
// потоки
// thread

void doWork()
{
	for (size_t i = 0; i < 10; i++) {
		cout << "Thread's ID - " << this_thread::get_id() << "\tdoWork\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

int main()
{
	clock_t start = clock();
	thread th(doWork); // далее нужно вызвать метод detach или join
	
	// detach - поток выполняется до прекращения работы главного потока. 
	// То есть его работа обрывается, если главный поток окончил работу 
	// раньше.
	// th.detach();
	
	thread th2(doWork);
	
	for (size_t i = 0; i < 10; i++) {
		cout << "Thread's ID - " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	// join - программа дожидается окончания выполнения работы потоком. 
	// Вызывать функцию нужно там, где мы хотим дождаться выполнения работы.
	// Когда программа доходит до метода join, она блокирует основной поток,
	// и ждет выполнения кода другим потоком
	th.join();
	th2.join();
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << seconds << endl;
	return 0;
}