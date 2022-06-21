#include <iostream>
#include <forward_list>
using namespace std;

/**
 * Библиотека стандартных шаблонов STL.
 * 
 * forward_list - реализация односвязного списка. Предназначен для работы
 * с элементами в начале списка.
 * 
 */


int main ()
{
	forward_list<int> fl = { 131, 94, 494 };
	// fl.push_front(1);

	// before_begin нужен для того, чтобы добавить элемент в начало списка
	// зачем это нужно не понятно, ибо можно использовать push_front и pop_front
	// fl.before_begin();
	
	auto it = fl.before_begin();

	// добавляет элемент после того, на который указывает итератор
	// То же самое и с остальными функциями с after
	fl.insert_after(it, 9999);
	// fl.erase_after(it);

	// valid
	// it++;

	// нельзя уменьшать итератор из-за односвязного списка
	// it--;
	// cout << *it << endl;


	for (auto el : fl) {
		cout << el << endl;
	}
	

	return 0;
}