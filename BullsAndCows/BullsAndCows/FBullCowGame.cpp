#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }
	
	TMap<char, bool> LetterSeen; // map setup
	for (auto Letter : Word)	// for all letters of the word
	{
		Letter = tolower(Letter); // handle mixed case letters
		
		if (LetterSeen[Letter]) { return false; } // if the letter is in the map we do NOT have an isogram
		else // otherwise
		{
			LetterSeen[Letter] = true; // add the letter to the map as seen (true)
		}	
	}
	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	if (Word.length() <= 0 || NULL) { return true; }
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	
	if (!IsIsogram(Guess)) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase; // TODO write function
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess is the wrong length
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{ 
		return EGuessStatus::Ok; // otherwise return OK
	} 
}

// recieves a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	// calls the 'length' method on the MyHiddenWord variable, returns the numeric value of its length and stores it in the new variable
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
	
	// run a loop, start counting from zero and keep increasing the count by one each time the loop runs until it's the same as the length of the hidden word, then stop looping. Name this count-number "HWChar"
	for (int32 HWChar = 0; HWChar < WordLength; HWChar++) 
	{											 
		// run a second loop, start counting from zero and keep increasing the count by one each time the loop runs until it's the same as the length of the hidden word, then stop looping. Name this count-number "GChar"
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
		{											
			// if any letter returned by running the incremented index-number lookup on the Guess word (eg. Guess[2] matches any letter returned by doing the same to the Hidden word, proceed to the following conditions
			if (Guess[GChar] == MyHiddenWord[HWChar]) 
			{
				// if the index-numbers are the same for the matching letters
				if (HWChar == GChar) 
				{
					// increment the 'Bulls' in our object of FBullCowCount type
					BullCowCount.Bulls++; 
				}
				// if the index-numbers are NOT the same for the matching letters
				else 
				{
					// increment the 'Cows'
					BullCowCount.Cows++; 
				}

			} // if No letters are matching in either word, END the bigger if-loop
		}
	}
	if (BullCowCount.Bulls == WordLength) { bGameIsWon = true; }
	else { bGameIsWon = false; }

	return BullCowCount;
}
