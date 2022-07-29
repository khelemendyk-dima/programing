#include <iostream>
using namespace std;

/**
 * бинарное дерево
 */
template <typename T> class Tree {
    private:
	template <typename R> class Node {
	    public:
		Node *left;
		Node *right;
		R data;

		Node(R data = R(), Node *left = nullptr, Node *right = nullptr)
		{
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};
	Node<T> *root;

    public:
	Tree();
	~Tree();

	void insert(const T data);
	T findElement(const T data);
	void printTree(Node<T> *node = nullptr, int u = 0);
	static void destroyNode(Node<T> *node);
};

int main()
{
	Tree<int> tree;
	tree.insert(10);
	tree.insert(15);
	tree.insert(7);
	tree.insert(5);
	tree.insert(8);
	tree.insert(20);
	tree.insert(21);
	tree.insert(19);
	tree.insert(11);
	tree.insert(1);
	cout << tree.findElement(1111) << endl << endl;
	tree.printTree();
	return 0;
}
template <typename T> Tree<T>::Tree()
{
	root = nullptr;
}
template <typename T> Tree<T>::~Tree()
{
	destroyNode(root);
}
template <typename T> void Tree<T>::insert(const T data)
{
	Node<T> **current = &root;
	while (*current) {
		Node<T> &node = **current;
		if (data < node.data) {
			current = &node.left;
		} else if (data > node.data) {
			current = &node.right;
		} else {
			return;
		}
	}
	*current = new Node<T>(data);
}
template <typename T> T Tree<T>::findElement(const T data)
{
	Node<T> **current = &root;
	while (*current) {
		Node<T> &node = **current;
		if (data < node.data) {
			current = &node.left;
		} else if (data > node.data) {
			current = &node.right;
		} else {
			return node.data;
		}
	}
	return 0;
}
template <typename T> void Tree<T>::printTree(Node<T> *node, int u)
{
	if (u == 0) {
		node = root;
	}
	if (node == nullptr) {
		return;
	} else {
		printTree(node->left, ++u);
		cout << node->data << endl;
		u--;
		printTree(node->right, ++u);
	}
}
template <typename T> void Tree<T>::destroyNode(Node<T> *node)
{
	if (node) {
		destroyNode(node->left);
		destroyNode(node->right);
		delete node;
	}
}