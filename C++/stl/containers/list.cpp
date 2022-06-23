#include <iostream>
#include <list>
using namespace std;

/**
 * Библиотека стандартных шаблонов STL.
 * 
 * list - реализация двусвязного списка
 * 
 */

template <typename T> void printList(const list<T> &lst);

int main ()
{
	list<int> myList = { 15, 64, 979, 54, 99 };
	list<int> myList2 = { 1, 6, 111, 33 };
	// myList.push_back(5);
	// myList.push_front(151);
	// myList.sort();
	// myList.pop_back();
	// myList.pop_front();
	// cout << myList.size() << endl << endl;
	// myList.reverse();
	// myList.clear();
	
	// убирает только те дубликаты, которые идут последовательно
	// myList.unique();

	// method insert or erase
	// auto it = myList.begin();
	// advance(it, 3);
	// myList.insert(it, 111);
	// myList.erase(it);

	// если элемент есть в списке, он удаляется, иначе ничего не происходит
	// myList.remove(99);

	// удаляет все элементы в списке и 3 раза записывает число 1234324
	// перезаписывает элементы
	// myList.assign(3, 1234324);
	myList.assign(myList2.begin(), myList2.end());
	
	printList(myList);
	return 0;	
}

template <typename T> void printList(const list<T> &lst)
{
	for (auto i = lst.cbegin(); i != lst.cend(); ++i) {	
		cout << *i << endl;
	}
}