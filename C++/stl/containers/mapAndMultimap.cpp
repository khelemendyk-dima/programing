#include <iostream>
#include <map>
using namespace std;

/**
 * Библиотека стандартных шаблонов STL.
 * 
 * map и multimap хранят пары значений(pair). Упорядочивание 
 * происходит по первому элементу пары(он является ключом)
 * 
 * multimap отличается от map тем, что может хранить элементы с 
 * одинаковым ключем, также отсутствуют метод at() и оператор []
 * 
 */


int main ()
{
	// 			MAP
	//-----------------------------------------------------
	// map<int, string> myMap;

	// добавление пар в map
	// myMap.emplace(3, "monitor");
	// myMap.insert(make_pair(1, "phone"));
	// myMap.insert(pair<int, string>(2, "laptop"));

	// auto it = myMap.find(1);
	// if (it != myMap.end()) {
	// 	cout << it->second << endl;
	// } else {
	// 	cout << "Element isn't found!!" << endl;
	// }

	// cout << myMap[3] << endl;
	//-----------------------------------------------------
	// map<string, int> myMap;
	// myMap.emplace("Petr", 1313);
	// myMap.emplace("Masha", 222);
	// myMap.emplace("Misha", 4441);

	// myMap["Petr"] = 99;
	// cout << myMap["Petr"] << endl;

	// если элемента не было в списке, то он добавится 
	// myMap["Vasya"] = 9797;
	// если элемента не было в списке, то он не добавится
	// myMap.at("Vasya") = 3;

	// myMap.erase("Petr");
	// 				MULTIMAP
	//-----------------------------------------------------
	multimap<string, int> myMultimap;
	
	myMultimap.emplace("Masha", 222);
	myMultimap.emplace("Masha", 111);
	myMultimap.emplace("Misha", 4441);
	myMultimap.emplace("Misha", 321);
	
	for (auto el : myMultimap) {
		cout << el.second << endl;
	}
	return 0;
}