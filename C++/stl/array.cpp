#include <iostream>
#include <array>
using namespace std;

/**
 * Библиотека стандартных шаблонов STL.
 * 
 * array - это обычный статический массив.
 * может быть полезен, благодаря своим функциям.
 * 
 */


int main ()
{
	array<int, 4> arr = { 1, 94, 77, 9 };

	// метод at контролирует выход за границы массива, но работает дольше, чем []
	// cout << arr.at(10) << endl;		

	// заполняет массив заданным элементом
	// arr.fill(-1);

	// показывает первый элемент
	// cout << arr.front();
	// показывает последний элемент
	// cout << arr.back();

	for (auto el : arr) {
		cout << el << endl;
	}

	return 0;
}