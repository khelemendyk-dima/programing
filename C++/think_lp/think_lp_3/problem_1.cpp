#include <iostream>
using namespace std;

int main()
{
	const int ARRAY_SIZE = 12;
	int array[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
	int counter = 0;
	int mode = 0; // число, которое встречается чаще всего
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		int temp = 0;
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			if (array[i] == array[j])
				temp++;
		}
		if (temp > counter)
		{
			counter = temp;
			mode = array[i];
		}
	}
	if (counter == 1)
		cout << "All numbers are appear with equal frequency.";
	else
		cout << mode << endl;
	return 0;
}