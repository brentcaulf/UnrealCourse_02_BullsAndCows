#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// recieves a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length(); // calls the 'length' method on the MyHiddenWord variable, returns the numeric value of its length and stores it in the new variable
	
	for (int32 HWChar = 0; HWChar < HiddenWordLength; HWChar++) // run a loop, start counting from zero and keep increasing the count by one each time the loop runs until it's the same as the length of the hidden word, then stop looping. Name this count-number "HWChar"
	{											 

		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) // run a second loop, start counting from zero and keep increasing the count by one each time the loop runs until it's the same as the length of the hidden word, then stop looping. Name this count-number "GChar"
		{											
			
			if (Guess[GChar] == MyHiddenWord[HWChar]) // if any letter returned by running the incremented index-number lookup on the Guess word (eg. Guess[2] matches any letter returned by doing the same to the Hidden word, proceed to the following conditions
			{

				if (HWChar == GChar) // if the index-numbers are the same for the matching letters
				{
					BullCowCount.Bulls++; // increment the 'Bulls' in our object of FBullCowCount type
				}
			
				else // if the index-numbers are NOT the same for the matching letters
				{
					BullCowCount.Cows++; // increment the 'Cows'
				}

			} // if No letters are the same in either word, END the bigger if-loop
		}
	}
	return BullCowCount;
}
