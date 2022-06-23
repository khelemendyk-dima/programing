#include <iostream>
 
#include <vector>
#include <list>
#include <deque>

#include <queue>
#include <stack>
using namespace std;

/**
 * Библиотека стандартных шаблонов STL.
 * 
 * 		Адаптеры контейнеров 
 * 
 * 				queue
 * 
 * 			priority_queue
 * 
 */


int main ()
{
	// QUEUE
	// ---------------------------------------------------------
	// также как и со стеком, в очереде можно поменять её основу
	// (из стандартного дека на лист). Вектор не работает с очередью
	// queue<int, list<int>> ql;
	// queue<int> q;
	// q.emplace(5);
	// q.emplace(75);
	// q.emplace(43);
	// q.emplace(11);

	// while (!q.empty()) {
	// 	cout << q.front() << endl;
	// 	q.pop();
	// }

	// ---------------------------------------------------------
	// PRIOTIRITY_QUEUE (элементы сортируются от большего к меньшему)
	// ---------------------------------------------------------
	// Приоритетная очередь может работать с деком или вектором
	// (по умолчанию вектор в отличии от обычной очереди)
	// priority_queue<int, vector<int>> pq;
	priority_queue<int> pq;
	pq.emplace(5);
	pq.emplace(75);
	pq.emplace(43);
	pq.emplace(11);

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}