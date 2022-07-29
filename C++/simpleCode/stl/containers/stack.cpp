#include <iostream>

#include <vector>
#include <list>
#include <deque>

#include <stack>
using namespace std;

/**
 * Библиотека стандартных шаблонов STL.
 * 
 * 	Адаптеры контейнеров 
 * 
 * 		stack
 * 
 */


int main ()
{
	// SIMPLE STACK
	//---------------------------------------------------------
	stack<int> st;

	st.push(2);
	st.push(43);
	st.push(3);
	st.emplace(9);
	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
	//---------------------------------------------------------
	// STACK WITH LIST
	// Функциона стека не изменяется, меняется только суть его работы (например, 
	// на основе листа, вектора, дека)
	//---------------------------------------------------------
	// stack<int, list<int>> st;
	// st.push(2);
	// st.push(43);
	// st.push(3);
	// st.emplace(9);
	// while (!st.empty()) {
	// 	cout << st.top() << endl;
	// 	st.pop();
	// }

	return 0;
}