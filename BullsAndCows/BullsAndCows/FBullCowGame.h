#pragma once

class FBullCowGame
{
public:
	void Reset(); // TODO make a better return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(); // TODO make a better return value

private:
	int MyCurrentTry;
	int MyMaxTries;

};