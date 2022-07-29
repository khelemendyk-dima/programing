#include <iostream>
#include <memory>
using namespace std;

/**
 * smart pointers
 * auto_ptr
 * unique_ptr
 * shared_ptr
 */

template<typename T>
class SmartPointer
{
private:
	T *ptr;
public:
	SmartPointer(T *ptr)
	{
		this->ptr = ptr;
		cout << "Constructor" << endl;
	}
	~SmartPointer()
	{
		delete ptr;
		cout << "Destructor" << endl;
	}
	T& operator*()
	{
		return *ptr;
	}
};


int main()
{
	// SmartPointer<int> sp1 = new int(5);
	// SmartPointer<int> sp2 = sp1;
	
	// auto_ptr уже устарел, похож на unique_ptr
	// auto_ptr<int> ap1(new int(5));
	// auto_ptr<int> ap2(ap1);

	// unique_ptr не разрешает указывать на двум указателям на один участок памяти
	// unique_ptr<int> p1(new int(5));
	// unique_ptr<int> p2;
	// p2 = move(p1);

	// int *p = p1.get();
	// cout << *p << endl;

	// shared_ptr самый умный и самый популярный из умных указателей
	// В shared_ptr указатели могут указывать на один участок памяти и память освободится один раз(реализован счетчик указателей) 
	shared_ptr<int> p1(new int(5));
	shared_ptr<int> p2(p1);
	return 0;
}