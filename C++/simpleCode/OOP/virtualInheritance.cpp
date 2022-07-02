#include <iostream>
using namespace std;

// ромбовидное наследование 
// виртуальное наследование
// https://www.youtube.com/watch?v=oqpx7L5ipbw&list=PLQOaTSbfxUtCrKs0nicOg2npJQYSPGO9r&index=132&ab_channel=%23SimpleCode

class Component
{
public:
	Component(string companyName)
	{
		cout << "constructor Component " << endl;
		this->companyName = companyName;
	}
	string companyName;
};
class GPU : public Component
{
public:
	GPU(string companyName) : Component(companyName)
	{
		cout << "constructor GPU " << endl;
	}	
};
class Memory : public Component
{
public:
	Memory(string companyName) : Component(companyName)
	{
		cout << "constructor Memory " << endl;
	}	
};
class GraphicCard : public GPU, public Memory
{
public:
	GraphicCard(string GPUCompanyName, string MemoryCompanyName) : GPU(GPUCompanyName), Memory(MemoryCompanyName)
	{
		cout << "constructor GraphicCard " << endl;
	}	
};

class Character
{
public:
	Character()
	{
		cout << "constructor Character" << endl;
	}
	int HP;
};
class Orc : public virtual Character
{
public:
	Orc()
	{
		cout << "constructor Orc" << endl;
	}
};
class Warrior : public virtual Character
{
public:
	Warrior()
	{
		cout << "constructor Warrior" << endl;
	}
};
class OrcWarrior : public Orc, public Warrior
{
public:
	OrcWarrior()
	{
		cout << "constructor OrcWarrior" << endl;
	}
};

int main()
{
	// конструкторы до ромбовидного(виртуального) наследования
	GraphicCard gc("AMD", "Samsung");
	cout << endl << endl;
	// конструкторы в ромбовидном наследовании
	OrcWarrior ow;



	return 0;
}