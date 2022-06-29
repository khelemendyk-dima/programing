#include <iostream>
using namespace std;

/**
 * Полиморфизм
 * Виртуальные функции
 * virtual
 * override 
 */

class Gun
{
public:
	virtual void Shoot()
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
class Bazooka : public Gun
{
public:
	void Shoot() override
	{
		cout << "BADABUM!!!" << endl;
	}
};
class Player
{
public:
	void Shoot(Gun *gun)
	{
		gun->Shoot();
	}
};

int main ()
{
	Gun gun;
	SubmachineGun machinegun;
	Bazooka bazz;

	Player player;
	player.Shoot(&bazz);

	return 0;
}