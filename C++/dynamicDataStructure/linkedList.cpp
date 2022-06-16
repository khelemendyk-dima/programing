#include <iostream>
using namespace std;

/**
 * односвязный список
 */
template <typename T> class List {
    private:
	template <typename R> class Node {
	    public:
		Node *pNext;
		R data;

		Node(R data = R(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	size_t size;
	Node<T> *head;

    public:
	List();
	~List();

	size_t getSize() const
	{
		return size;
	}

	void push_back(const T data);
	void push_front(const T data);
	void insert(const T data, size_t index);
	void pop_back();
	void pop_front();
	void removeAt(size_t index);
	void clear();

	T &operator[](const size_t index);
};

int main()
{
	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(15);
	lst.push_back(20);
	cout << lst.getSize() << endl << endl;
	lst.push_front(1);
	lst.push_front(2);
	lst.insert(11, 2);
	lst.pop_back();
	lst.removeAt(2);
	for (size_t i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << endl;
	}
	cout << endl;
	cout << lst.getSize() << endl;
	return 0;
}
template <typename T> List<T>::List()
{
	size = 0;
	head = nullptr;
}
template <typename T> List<T>::~List()
{
	clear();
}
template <typename T> void List<T>::push_back(const T data)
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
template <typename T> void List<T>::push_front(const T data)
{
	head = new Node<T>(data, head);
	size++;
}
template <typename T> void List<T>::insert(const T data, size_t index)
{
	if (index > size) {
		index = size;
	}
	if (index == 0) {
		push_front(data);
	} else {
		Node<T> *previous = this->head;
		for (size_t i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		previous->pNext = new Node<T>(data, previous->pNext);
		// вот что проиходит в вверхней строке
		// Node<T> *newNode = new Node<T>(data, previous->pNext);
		// previous->pNext = newNode;
		size++;
	}
}
template <typename T> void List<T>::pop_back()
{
	removeAt(size - 1);
}
template <typename T> void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	size--;
}
template <typename T> void List<T>::removeAt(size_t index)
{
	if (index >= size) {
		index = size - 1;
	}
	if (index == 0) {
		pop_front();
	} else {
		Node<T> *previous = this->head;
		for (size_t i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<T> *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}
template <typename T> void List<T>::clear()
{
	while (size) {
		pop_front();
	}
}
template <typename T> T &List<T>::operator[](const size_t index)
{
	Node<T> *current = this->head;
	size_t i = 0;
	while (current != nullptr) {
		if (i == index) {
			break;
		}
		current = current->pNext;
		i++;
	}
	return current->data;
}
