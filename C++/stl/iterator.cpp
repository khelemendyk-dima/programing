#include <iostream>
#include <vector>
using namespace std;
/**
 * Библиотека стандартных шаблонов STL.
 * 
 * Iterator
 * 
 */

int main()
{
	vector<int> myVector = { 1, 9, 44, 422, 676, 78 };


	myVector.insert(myVector.begin() + 1, 999);
	// deleting all elements from 0 to 3
	myVector.erase(myVector.begin(), myVector.begin() + 3);
	// myVector.erase(myVector.begin() + 2);

    // ----------------------------------------------------------------------------
	// vector<int>::iterator it = myVector.begin();
	// cout << *(it + 3) << endl;
	// if iterator doesn't support previous line of code, we can use "advance" function
	// 
	// advance(it, 3);
	// cout << *it << endl;
    // ----------------------------------------------------------------------------
	// simple iterator, we can change value of vector
	// 
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++) {
		cout << *i << endl;
	}
    // ----------------------------------------------------------------------------
	// const interator, we can't change value of vector
	//
	//  for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); i++) {
	// 	cout << *i << endl;
	// }
    // ----------------------------------------------------------------------------
	// reverse iterator for printing vector in reverse range
	// 
	// for (vector<int>::reverse_iterator i = myVector.rbegin(); i != myVector.rend(); i++) {
	// 	cout << *i << endl;
	// }

	

	return 0;
}