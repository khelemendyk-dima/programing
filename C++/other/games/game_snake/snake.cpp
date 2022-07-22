#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int WIDTH = 20;
const int HEIGHT = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP, LEFT, RIGHT, UP, DOWN };
eDirection direction;

void setup()
{
	gameOver = false;
	direction = STOP;
	x = WIDTH / 2 - 1;
	y = HEIGHT / 2 - 1;
	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGHT;
	score = 0;
}
void draw()
{
	system("cls");
	// верхняя граница
	for (int i = 0; i < WIDTH + 1; i++)
		cout << '#';
	cout << endl;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (j == 0 || j == WIDTH - 1)
				cout << '#';
			if (i == y && j == x)
				cout << '0';
			else if (i == fruitY && j == fruitX)
				cout << 'F';
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						print = true;
						cout << 'o';
					}
				}
				if (!print)
					cout << ' ';
			}
		}
		cout << endl;	
	}

	// нижняя граница
	for (int i = 0; i < WIDTH + 1; i++)
		cout << '#';
	cout << endl;
	cout << "Score: " << score << endl;
}
void input()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			direction = LEFT;
			break;
		case 'd':
			direction = RIGHT;
			break;
		case 'w':
			direction = UP;
			break;
		case 's':
			direction = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
void logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (direction)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x >= WIDTH - 1)
		x = 0;
	else if (x < 0)
		x = WIDTH - 2;
	else if (y >= HEIGHT)
		y = 0;
	else if (y < 0)
		y = HEIGHT - 1;

	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y) {
			gameOver = true;
		}
	}
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;
		nTail++;
	}
}

int main()
{
	setup();
	while(!gameOver) {
		draw();
		input();
		logic();
		_sleep(150);
	}
	return 0;
}