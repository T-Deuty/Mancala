#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <tuple>

using namespace std;

class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	// Called from main function to take user input until the user exits or the game finishes.
	void HandleUserInput();
private:
	// Function to check validity of user input. Checks if input is in correct range for current player's turn, and if it is correct data type.
	bool checkValidInput();
	// Takes in user input from the command line, returns it in the form of a tuple.
	tuple<int, int> takeUserInput();
};

