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

private:
	int MyCurrentTry;
	int MyMaxTries;

};