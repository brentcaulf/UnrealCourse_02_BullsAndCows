#include <iostream>
#include <string>

using namespace std;

int main()
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;	
	cout << "Welcome to Bulls and Cows!" << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thining of?" << endl;

	// get guess from player
	string Guess = "";
	cout << "Please enter a guess: ";
	cin >> Guess;
	cout << endl;
	
	// repeat the guess back to player
	cout << "You guessed: " << Guess;
	cout << endl;

	// get guess from player
	cout << "Please enter a guess: ";
	cin >> Guess;
	cout << endl;

	// repeat the guess back to player
	cout << "You guessed: " << Guess;
	cout << endl;

	return 0;
}