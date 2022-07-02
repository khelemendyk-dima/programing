#include <iostream>
using namespace std;

// enum


class PC
{
public:
	enum PCState
	{
		OFF,
		ON,
		SLEEP
	};
	PCState getState()
	{
		return state;
	}
	void SetState(PCState state)
	{
		this->state = state;
	}
private:
	PCState state;
};

enum Speed
{
	MIN = 150,
	RECOMEND = 600,
	MAX = 800
};

int main()
{
	PC pc;
	pc.SetState(PC::PCState::ON);
	// if (pc.getState() == PCState::ON) {
	// 	cout << "PC works!" << endl;
	// }

	switch (pc.getState()) {
	case PC::PCState::OFF:
		cout << "Off!" << endl;
		break;
	case PC::PCState::ON:
		cout << "On!" << endl;
		break;
	case PC::PCState::SLEEP:
		cout << "Sleep!" << endl;
		break;
	default:
		break;
	}

	Speed sp = MAX;
	cout << sp << endl;

	return 0;
}