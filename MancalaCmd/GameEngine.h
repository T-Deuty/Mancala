#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
#include <algorithm>
#include "Board.h"
#include "InputExceptions.h"

using namespace std;

class GameEngine
{
private:
	Board *gameBoard;

	string inputStr;

	// holds which player's turn it currently is
	int currentPlayer;
	tuple<int, int> breakTuple = make_tuple(-1,-1);

	enum players
	{
		player,
		opponent
	};

	enum rowOrCol
	{
		row,
		col
	};

	enum errors 
	{
		exit,
		outOfRange,
		nonInt
	};

public:
	GameEngine();
	~GameEngine();
	// Called from main function to take user input until the user exits or the game finishes.
	void handleUserInput();
private:
	// Function to check validity of user input. Checks if input is in correct range for current player's turn, and if it is correct data type.
	// rowOrCol at 0 is row, at 1 is column
	bool checkValidInput(int rowOrCol, int input);
	bool checkValidInput(string input);
	// Takes in user input from the command line, returns it in the form of a tuple.
	tuple<int, int> takeUserInput();
	// Updates the board with a user-defined move, and prints out the result
	void makeMove(tuple<int, int> moveCoordinates);
	// Handles left movement on the board
	void moveLeft(int remaining, int moveCol);
	// Handles right movement on the board
	void moveRight(int remaining, int moveCol);
};

