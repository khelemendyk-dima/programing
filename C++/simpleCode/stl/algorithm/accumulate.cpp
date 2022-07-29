#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

/**
 * Библиотека стандартных шаблонов (STL)
 * 
 * 			  Алгоритмы
 * 
 * 		   сумма элементов 
 * 
 *     произведение элементов
 * 
 * 		сумма четных элементов
 * 
*/

int main ()
{
	int v [] = { 2, 3, 4, 5, 7, 10 };

	// считает сумму всех чисел вектора  её к нулю
	// auto result = accumulate(begin(v), end(v), 0);
	// умножает все числа
	// auto result = accumulate(begin(v), end(v), 1, [](int a, int b)
	// {
	// 	return a * b;
	// });

	// считает сумму четных чисел
	// auto result = accumulate(begin(v), end(v), 0, [](int a, int b)
	// {
	// 	if (b % 2 == 0) {	
	// 		return a + b;
	// 	} else {
	// 		return a;
	// 	}
	// });

	// конвертируем числа в строку
	auto result = accumulate(next(begin(v)), end(v), to_string(v[0]), [](string a, int b)
	{
		return a + "-" + to_string(b);
	});

	cout << "Result\t" << result << endl;



	return 0;
}