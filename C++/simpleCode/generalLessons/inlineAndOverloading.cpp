#include <iostream>
using namespace std;

// ключевое слово inline. Встраиваемая функция. При inline компилятор встраивает
// функцию в код, а не передает аргументы в функцию и возращает результат.

// inline int Sum(int a, int b)
// {
// 	return a + b;
// }

// Перегрузка функций

int Sum(int a, int b, int c)
{
	a++;
	return a + b + c;
}
int Sum(int a, int b)
{
	return a + b;
}
double Sum(double a, double b)
{
	return a + b;
}

int main ()
{
	cout << Sum(1, 2) << endl;
	cout << Sum(1.24, 2.26) << endl;
	cout << Sum(1, 2, 2) << endl;

	return 0;
}