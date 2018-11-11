#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// entry point for the program
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	
	return 0;
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows!" << std::endl;
	std::cout << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram?" << std::endl;
	return;
}

void PlayGame()
{
	
	int MaxTries = BCGame.GetMaxTries();

	// loops for number of turns and asks for guesses
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		std::cout << "You guessed: " << Guess << std::endl;
		std::cout << std::endl;
	}
	return;
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	
	std::string Guess = "";
	std::cout << "Try " << CurrentTry << ". Please enter a guess: ";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n) ? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}