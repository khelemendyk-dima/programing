#include <iostream>
#include <set>
using namespace std;

/**
 * Библиотека стандартных шаблонов STL.
 * 
 * set и multiset - реализация бинарного дерева.
 * 
 * В set нет push_back или push_front, или []. Здесь мы можем 
 * использовать insert. set НЕ МОЖЕТ хранить два одинаковых значения.
 * set НЕ МОЖЕТ изменить значение элемента.
 * 
 * multiset отличается от set тем, что может иметь несколько одинаковых значений.
 * 
 */


int main ()
{
	// 				SET
	//---------------------------------------------------------------
	// set<int> mySet = { 5, 45, 35, 11, 86 };
	// mySet.insert(1);

	// проверяет есть ли элемент в сете. Если его нет - итератор указывает в энд.
	// auto it = mySet.find(10);
	// практическое использование метода find
	// int value;
	// cin >> value;
	// if (mySet.find(value) != mySet.end()) {
	// 	cout << "number " << value << " is found" << endl;
	// } else {
	// 	cout << "number " << value << " isn't found" << endl;
	// }
	
	// mySet.erase(5);
	// erase возвращает тру фолс типа size_t
	// auto result = mySet.erase(5);
	// cout << result << endl << endl;
	// insert возвращает два значения(одно - итератор, указывающий на элемент в коллекции,
	// а во втором - булевая переменная)
	// auto result = mySet.insert(111);
	// cout << *result.first << endl;
	// cout << result.second << endl << endl;

	// for (auto &item : mySet) {
	// 	cout << item << endl;
	// }

	// 				MULTISET
	//---------------------------------------------------------------
	multiset<int> myMultiset = { 1, 66, 16, 48, 99 };
	myMultiset.insert(1);
	myMultiset.insert(1);

	// lower_bound вернет первую 1-цу которую найдет
	// auto it1 = myMultiset.lower_bound(1);
	// upper_bound вернет следующий элемент после 1-цы, то есть
	// элемент, который больше него
	// auto it2 = myMultiset.upper_bound(1);

	// equal_range возвращает диапазон(два итератора) чисел от lower_bound до upper_bound 
	auto a = myMultiset.equal_range(1);

	for (auto &item : myMultiset) {
		cout << item << endl;
	}

	return 0;
}