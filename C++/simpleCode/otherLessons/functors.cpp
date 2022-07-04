#include <iostream>
using namespace std;

// функтор - это объект класса, у которого перегружен оператор () и функтор может
// хранить промежуточные данные  


// class MyFunctor
// {
// public:
// 	// функтор
// 	int operator()(int a, int b)
// 	{
// 		cout << "i am functor " << endl;
// 		return a + b;
		
// 	}
// private:
// };

class EvenFunctor
{
public:
	int operator()(int value)
	{
		if (value % 2 == 0) {
			evenSum += value;
			evenCount++;
		}	
	}
	void ShowEvenSum()
	{
		cout << "Sum of even numbers = " << evenSum << endl;
	}
	void ShowEvenCount()
	{
		cout << "Count of even numbers = " << evenCount << endl;
	}
private:
	int evenSum = 0;
	int evenCount = 0;
};

int main()
{
	// MyFunctor f;
	// cout << f(2, 3) << endl;

	int arr[] = { 1, 2, 55, 99, 44, 3 };
	EvenFunctor ef;

	for (auto el : arr) {
		ef(el);
	}

	ef.ShowEvenCount();
	ef.ShowEvenSum();


	return 0;
}