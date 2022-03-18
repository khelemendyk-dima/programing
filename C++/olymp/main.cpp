#include <iostream>

using namespace std;

int EncryptNumber(int n)
{
	int fourthDigit = n % 10;
	n /= 10;
	int thirdDigit = n % 10;
	n /= 10;
	int secondDigit = n % 10;
	n /= 10;
	int firstDigit = n % 10;

	int firstPlusSecond = (firstDigit + secondDigit) % 10;
	int secondPlusThird = (secondDigit + thirdDigit) % 10;
	int thirdPlusFour = (thirdDigit + fourthDigit) % 10;

	int result = firstDigit * 1e6 + firstPlusSecond * 1e5 +
		secondDigit * 1e4 + secondPlusThird * 1e3 + 
		thirdDigit * 1e2 + thirdPlusFour * 1e1 +
		fourthDigit * 1e0;

	result *= 42;

	return result;
}

int main()
{
	int nums[4]; // input data
	for (int i = 0; i < 4; i++)
		cin >> nums[i];

	for (int i = 0; i < 4; i++)
	{

		bool is_right_crypt = false;
		
		for (int j = 1000; j < 10000; j++)
		{
			if (EncryptNumber(j) == nums[i])
			{
				cout << j << " ";
				is_right_crypt = true;
				break;
			}
		}

		if (!is_right_crypt)
			cout << "???? ";
	}
}