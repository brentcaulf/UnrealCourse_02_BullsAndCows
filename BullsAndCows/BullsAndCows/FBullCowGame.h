#pragma once

#include <string>

class FBullCowGame
{

public:
	FBullCowGame(); // constructor
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); // TODO make a better return value
	bool CheckGuessValidity(std::string); // TODO make a better return value
	// provide a method for counting bulls and cows and increasing try number

private:
	int MyCurrentTry;
	int MyMaxTries;

};