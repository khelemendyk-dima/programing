#include <iostream>
#include <string>
using namespace std;

struct student
{
	int grade;
	string name;
};

int main()
{	
	const int ARRAY_SIZE = 10;
	student studentArray[ARRAY_SIZE] = {
		{87, "Fred"},
		{28, "Tom"},
		{100, "Alistair"},
		{78, "Sasha"},
		{84, "Erin"},
		{98, "Belinda"},
		{75, "Leslie"},
		{70, "Candy"},
		{81, "Aretha"},
		{68, "Veronica"}
	};
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE - 1; j++)
		{
			if (studentArray[j].grade > studentArray[j + 1].grade)
			{
				int tempi = studentArray[j].grade;
				string temps = studentArray[j].name;
				studentArray[j].grade = studentArray[j + 1].grade;
				studentArray[j].name = studentArray[j + 1].name;
				studentArray[j + 1].grade = tempi;
				studentArray[j + 1].name = temps;
			}	
		}
	}
	int twentyFivePercent = ARRAY_SIZE / 4;
	if (ARRAY_SIZE % 4 != 0)
		twentyFivePercent++;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (i <= twentyFivePercent)
			cout << studentArray[i].name << " is lower than 25%... He's grade is " << studentArray[i].grade << endl;
		else if (i >= twentyFivePercent && i <= twentyFivePercent * 2)
			cout << studentArray[i].name << " is better than 25%. He's grade is " << studentArray[i].grade << endl;
		else if (i > twentyFivePercent * 2 && i < twentyFivePercent * 3)
			cout << studentArray[i].name << " is better than 50%! He's grade is " << studentArray[i].grade << endl;
		else
			cout << studentArray[i].name << " is better than 75%. He's grade is " << studentArray[i].grade << endl;
	}
	return 0;
}