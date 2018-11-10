#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();

// entry point for the program
int main()
{
	PrintIntro();
	PlayGame();

	return 0;
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows!" << endl;
	cout << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram?" << endl;
	return;
}

void PlayGame()
{
	// loops for number of turns and asks for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
		cout << "You guessed: " << Guess << endl;
		cout << endl;
	}
	return;
}

string GetGuess()
{
	string Guess = "";
	cout << "Please enter a guess: ";
	getline(cin, Guess);

	return Guess;
}