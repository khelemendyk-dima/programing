#include <iostream>
using namespace std;

// Наследование

class Human
{
private:
	string name = "Ivan Ivanovich";
public:
	string GetName()
	{
		return name;
	}
	void SetName(string name)
	{
		this->name = name;
	}
};
class Student : public Human
{
public:
	string group;
	void Learn()
	{
		cout << "I'm learning!" << endl;
	}
};
class ExtramuralStudent : public Student
{
public:
	void Learn()
	{
		cout << "I'm learning sometimes!" << endl;
	}
};
class Professor : public Human
{
public:
	string subject;
};


int main ()
{
	Student st;
	st.Learn();
	st.SetName("Dimonchik");
	cout << st.GetName() << endl;

	ExtramuralStudent extraSt;
	extraSt.Learn();
	extraSt.SetName("Petr");
	cout << extraSt.GetName() << endl;

	return 0;
}