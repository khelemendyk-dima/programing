#include <iostream>
using namespace std;

/**
 * Абстрактные классы
 * чисто виртуальные функции
 * virtual
 * override 
 * 
 *  Чисто виртуальная финкция - это виртуальная функция без реализации
 */

class Weapon
{
public:
	// чисто виртуальная функция, класс автоматически стает абстрактным,
	// то есть мы не можем его создавать
	virtual void Shoot() = 0; 
	void Foo() {
		cout << "Foo()" << endl;
	}
};

class Gun : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BANG!" << endl;
	}
};
class SubmachineGun : public Gun
{
public:
	void Shoot() override
	{
		cout << "BANG! BANG! BANG!" << endl;
	}
};
class Bazooka : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BADABUM!!!" << endl;
	}
};
class Knife : public Weapon
{
public:
	void Shoot() override
	{
		cout << "VJUH!!!" << endl;
	}
};


class Player
{
public:
	void Shoot(Weapon *weapon)
	{
		weapon->Shoot();
	}
};

int main ()
{
	Gun gun;
	SubmachineGun machinegun;
	Bazooka bazooka;
	Knife knife;

	Player player;
	player.Shoot(&knife);
	knife.Foo();

	return 0;
}