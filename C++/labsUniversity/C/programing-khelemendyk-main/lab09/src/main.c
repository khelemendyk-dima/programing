/**
 * @mainpage
 * # Загальне завдання
 * Без допомоги зовнішніх бібліотек,
 * отримати корінь заданого числа, реалізуючи
 * алгоритм ітераційної формули Герона.
 *
 * @author Khelemendyk D.
 * @date 07-nov-2021
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури
 * та методів оперування ним.
 *
 * @author Khelemendyk D.
 * @date 07-nov-2021
 */
#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створюю змінну а(число, корінь якого потрібно знайти).
 * - знаходження кореню за допомогою функції geron
 * - @return успішний код повернення з програми (0)
 */
int main()
{
	float res = geron(A);
	return 0;
}