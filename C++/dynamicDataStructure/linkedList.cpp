#include <iostream>
#include <string>
using namespace std;

/**
 * односвязный список
 */
template<typename T>
class List {
public:
	List();
	~List();

	int getSize() {return size;}

	void push_back(T data);
	void push_front(T data);
	void insert(T data, int index);
	void pop_back();
	void pop_front();
	void removeAt(int index);
	void clear();
	
	T& operator[](const int index);
private:
	template<typename R>
	class Node
	{
	public:
		Node *pNext;
		R data;

		Node(R data = R(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext; 
		}
	};
	int size;
	Node<T> *head;
};

int main () {
	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(15);
	lst.push_back(20);
	cout << lst.getSize() << endl << endl;
	lst.push_front(1);
	lst.push_front(2);
	lst.insert(11, 3);
	lst.pop_back();
	lst.removeAt(3);
	for (int i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << endl;
	}
	cout << endl << lst.getSize() << endl;
	return 0;
}
template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List()
{
	clear();
}
template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	} else {
		Node<T> *current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}
template<typename T>
T& List<T>::operator[](const int index)
{
	Node<T> *current = this->head;
	int i = 0;
	while (current != nullptr) {
		if (i == index) {
			return current->data;
		}
		current = current->pNext;
		i++;
	}
}
template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	size--;
}
template<typename T>
void List<T>::clear()
{
	while(size) {
		pop_front();
	}
}
template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}
template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0) {
		push_front(data);
	} else {
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		previous->pNext = new Node<T>(data, previous->pNext);
		// вот что проиходит в вверхней строке
		// Node<T> *newNode = new Node<T>(data, previous->pNext);
		// previous->pNext = newNode;
		size++;
	}
}
template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0) {
		pop_front();
	} else {
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<T> *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}
template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
}