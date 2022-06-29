#include <iostream>
using namespace std;

// вызов метода базового класса

class Msg
{
private:
	string msg;
public:
	Msg(string msg)
	{
		this->msg = msg;
	}
	virtual string GetMsg()
	{
		return msg;
	}
};
class BracketsMsg : public Msg
{
public:
	BracketsMsg(string msg) : Msg(msg)
	{
	}
	string GetMsg() override
	{
		// ::Msg::GetMsg() вызывает метод базового класса
		return "[" + ::Msg::GetMsg() + "]";
	}
};

class Printer
{
public:
	void Print(Msg *msg)
	{
		cout << msg->GetMsg() << endl;
	}
};

int main()
{
	BracketsMsg bm("Hello!");

	Printer p;
	p.Print(&bm);


	return 0;
}