#include <iostream>
using namespace std;

/**
 * двусвязный список
 */
template <typename T> class List {
    private:
	template <typename R> class Node {
	    public:
		Node *pNext;
		Node *pPrev;
		R data;

		Node(R data = R(), Node *pNext = nullptr, Node *pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	size_t size;
	Node<T> *head;
	Node<T> *tail;

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
	// cout << lst.getSize() << endl << endl;
	lst.push_front(1);
	lst.push_front(2);
	lst.insert(11, 4);
	lst.insert(12, 4);
	lst.insert(13, 4);
	lst.pop_front();
	lst.pop_back();
	lst.removeAt(3);
	for (size_t i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << endl;
	}
	cout << endl << lst.getSize() << endl;
	return 0;
}
template <typename T> List<T>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template <typename T> List<T>::~List()
{
	clear();
}
template <typename T> void List<T>::push_back(const T data)
{
	if (size == 0) {
		head = tail = new Node<T>(data, nullptr, tail);
	} else {
		tail->pNext = new Node<T>(data, nullptr, tail);
		tail = tail->pNext;
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
	} else if (index == size) {
		push_back(data);
	} else {
		if (index <= size - index) {
			Node<T> *previous = this->head;
			for (size_t i = 0; i < index - 1; i++) {
				previous = previous->pNext;
			}
			Node<T> *temp = previous->pNext;
			previous->pNext = new Node<T>(data, previous->pNext, previous);
			temp->pPrev = previous->pNext;
		} else {
			Node<T> *next = this->tail;
			for (size_t i = size - 1; i > index; i--) {
				next = next->pPrev;
			}
			Node<T> *temp = next->pPrev;
			next->pPrev = new Node<T>(data, next, next->pPrev);
			temp->pNext = next->pPrev;
		}
		size++;
	}
}
template <typename T> void List<T>::pop_back()
{
	Node<T> *toDelete = this->tail;
	tail = tail->pPrev;
	tail->pNext = nullptr;
	delete toDelete;
	size--;
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
		if (index <= size - index) {
			Node<T> *previous = this->head;
			for (size_t i = 0; i < index - 1; i++) {
				previous = previous->pNext;
			}
			Node<T> *toDelete = previous->pNext;
			Node<T> *temp = toDelete->pNext;
			temp->pPrev = toDelete->pPrev;
			previous->pNext = toDelete->pNext;
			delete toDelete;
		} else {
			Node<T> *next = this->tail;
			for (size_t i = size - 1; i > index; i--) {
				next = next->pPrev;
			}
			Node<T> *toDelete = next->pPrev;
			Node<T> *temp = toDelete->pPrev;
			temp->pNext = toDelete->pNext;
			next->pPrev = toDelete->pPrev;
			delete toDelete;
		}
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
	if (index <= size - index) {
		size_t i = 0;
		Node<T> *current = this->head;
		while (current != nullptr) {
			if (i == index) {
				break;
			}
			current = current->pNext;
			i++;
		}
		return current->data;
	} else {
		size_t i = size - 1;
		Node<T> *current = this->tail;
		while (current != nullptr) {
			if (i == index) {
				break;
			}
			current = current->pPrev;
			i--;
		}
		return current->data;
	}
}
