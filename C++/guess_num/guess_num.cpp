// Game guess number
// Игра "Угадай число"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int guessed_number = rand() % 100 + 1;
	int tries = 0;
	int guess;
	cout << "\tWelcome to Guess My Number\n\n";
	do {
		tries++;
		cout << "Enter a guess: ";
		cin >> guess;
		if (guess > guessed_number)
			cout << "Too high!\n\n" << endl;
		else if (guess < guessed_number)
			cout << "Too low!\n\n" << endl;
		else
			cout << "\nThats's it! You got it in " << tries << " guesses!" << endl;
	} while (guess != guessed_number);
	return 0;
}