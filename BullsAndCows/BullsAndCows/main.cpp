/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class */

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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
	std::cout << "Welcome to Bulls and Cows, a simple word game!" << std::endl;
	std::cout << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram?" << std::endl;
	std::cout << std::endl;
	std::cout << "An isogram is a word with no repeating letters." << std::endl;
	std::cout << "When you guess a word you will get a number of Bulls and Cows." << std::endl;
	std::cout << "A Bull means you have the same letter in your word and it's in the same place." << std::endl;
	std::cout << "A Cow means you have the same letter but it's in the wrong place." << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loops asking for guesses while the game is NOT won and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		// gets a valid guess
		FText Guess = GetValidGuess();

		// submit valid guess
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl << std::endl;
	}

	PrintGameSummary();

	return;
}

// loop until the user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid;
	do {
			// get a guess from player
			int32 CurrentTry = BCGame.GetCurrentTry();

			std::cout << std::endl;
			std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Please enter a guess: ";
			std::getline(std::cin, Guess);
			// check the guess is valid
			Status = BCGame.CheckGuessValidity(Guess);
			switch (Status)
			{
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
				break;
			case EGuessStatus::Not_Isogram:
				std::cout << "Please enter a isogram (word with no repeating letters).\n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "Please enter a word with all lower case letters.\n";
				break;
			default:
				// assume the guess is valid
				break;
			}
			
	} while (Status != EGuessStatus::Ok); // keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << std::endl;
	std::cout << "Do you want to play again (y/n) ? ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Great work you won the game!\n";
	}
	else
	{
		std::cout << "Nice try, better luck next time.\n";
	}
}