#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// entry point for the program
int main()
{
	PrintIntro();

	// loops for number of turns and asks for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		GetGuessAndPrintBack();
		cout << endl;
	}

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

string GetGuessAndPrintBack()
{
	string Guess = "";
	cout << "Please enter a guess: ";
	getline(cin, Guess);

	// repeat the guess back to player
	cout << "You guessed: " << Guess;
	cout << endl;
	
	return Guess;
}