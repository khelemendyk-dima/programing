#include <iostream>
using namespace std;

struct Node
{
    string nameAuthor;
    string nameBook;
    Node *next;
};

class List
{
private:
    Node *head; //"голова" связанного списка

public:
    List() //конструктор класса без параметров
    {
        head = NULL; //первого элемента пока нет
    }

    //метод, добавляющий новый узел в список
    void addNode(string author, string book)
    {
        Node *nd = new Node; //динамически создаем новый узел

        nd->nameAuthor = author;        //задаем узлу данные
        nd->nameBook = book;

        nd->next = NULL;     //новый узел в конце, поэтому NULL

        if(head == NULL)     //если создаем первый узел
            head = nd;
        else                 //если узел уже не первый
        {
            Node *current = head;

            //ищем в цикле предшествующий последнему узел
            while(current->next != NULL)
                current = current->next;

            //предшествующий указывает на последний
            current->next = nd;
        }
    }


    //метод, выводящий связанный список на экран
    void printList()
    {
        Node *current = head;

        while(current != NULL)
        {
            cout << "Author: " << current->nameAuthor << endl;
            cout << "Book: " << current->nameBook << endl << endl;
            current = current->next;
        }
    }
};

int main()
{
    List myList;

    myList.addNode("Leo Tolstoy", "War and Peace");
    myList.addNode("Mark Twain", "The Adventures of Huckleberry Finn");
    myList.addNode("Charles Dickens", "Great Expectations");
    myList.addNode("George Eliot", "Middlemarch");
    myList.addNode("Gustave Flaubert", "Madame Bovary");

    myList.printList();

    return 0;
}