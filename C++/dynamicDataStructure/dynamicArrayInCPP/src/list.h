#ifndef LAB_19_LIST_H
#define LAB_19_LIST_H

/**
 * @file list.h
 * @brief Файл з описом функцій класа "список": конструктор, деструктор, 
 * гетери та сетери, додавання та видалення лампочки у динамічному масиві, 
 * отримання лампочки за позицією, вивод списку на екран, знаходження 
 * згорівших лампочок, зчитування даних з файла та запис даних у файл, 
 * оператори індексування, вводу/виводу на екран та у файл.
 *
 * @author Khelemendyk D.
 * @date 14-may-2022
 * @version 0.1
 */

#include "entity.h"

/**
 * Клас "список". Зберігає клас "лампочка"
 * та його розмір. Створює динамічний масив.
 */
class List {
    private:
	Bulb **bulbs;
	size_t size;

    public:
	List();
	~List();

	// гетери/сетери
	size_t getSize() const;
	void setSize(const size_t s);

	/**
	 * Додавання лампочки у список.
	 *
	 * Функція виділяє пам'ять для більшого масива, переписує 
	 * в нього старі лампочки(якщо вони є) та додає нову лампочку 
	 * в задану позицію.
	 * Отримує силку на лампочку та позицію для додавання.
	 */
	void addBulb(const Bulb &bulb, size_t pos = 0);
	/**
	 * Видалення елемента зі списку.
	 *
	 * Функція видаляє лампочку зі списку шляхом виділення пам'яті для меншого 
	 * масива та заповненням в нього всіх елементів окрім лампочки для видалення.
	 * Отримує позицію для видалення.
	 */
	void removeBulb(size_t pos);
	/**
	 * Отримання лампочки за індексом.
	 * 
	 * Функція повертає силку на лампочку за певним індексом.
	 * Отримує індекс - позицію лампочки.
	 */
	Bulb &getBulb(size_t index);
	/**
	 * Вивод списка.
	 *
	 * Функція друкує список на екран.
	 */
	void print() const;
	/**
	 * Знаходження згорівших лампочок.
	 *
	 * Функція перевіряє чи є лампочки взагалі, якщо є - перевіряє 
	 * на наявність згорівшої лампочки, та при наявності хоча б однієї 
	 * згорівшої лампочки - друкує її.
	 */
	void findBurnedBulbs() const;
	/**
	 * Читання файла.
	 *
	 * Функція обнуляє список, зчитує дані з файла та записує їх у список.
	 * Отримує адрес файла.
	 * 
	 */
	void readFromFile(string &fileName);
	/**
	 * Запис у файл.
	 *
	 * Функція записує у файл весь список. Отримує адрес файла.
	 */
	void writeToFile(string &fileName);
	/**
	 * Оператор індексації.
	 *
	 * Функція повертає лампочку по індексу зі списка.
	 */
	Bulb &operator[](size_t i) const;
	/**
	 * Оператор виводу.
	 *
	 * Функція виводить змінні лампочки через кому.
	 */
	friend ostream &operator<<(ostream &output, const List &l);
	/**
	 * Оператор вводу.
	 *
	 * Функція запитує у користувача дані та записує їх у об'єкт.
	 */
	friend istream &operator>>(istream &input, List &l);
	/**
	 * Оператор запису.
	 *
	 * Функція записує лампочки через кому у файл.
	 */
	friend ofstream &operator<<(ofstream &output, const List &l);
	/**
	 * Оператор вводу.
	 *
	 * Функція зчитує всі дані з файла та записує їх у об'єкт.
	 */
	friend ifstream &operator>>(ifstream &input, List &l);
};

#endif