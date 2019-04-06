#include "pch.h"
#include "GameEngine.h"


GameEngine::GameEngine()
{
}


GameEngine::~GameEngine()
{
}


// Called from main function to take user input until the user exits or the game finishes.
void GameEngine::HandleUserInput()
{
	int moveRow, moveCol;
	string inputStr;

	do {
		cout << "\nEnter a row and column to make the next move. Type \"exit\" to end the program. \nEnter the row: ";
		getline(cin, inputStr);
		if (inputStr == "exit") break;
		stringstream(inputStr) >> moveRow;
		cout << "\nEnter the column: ";
		getline(cin, inputStr);
		if (inputStr == "exit") break;
		stringstream(inputStr) >> moveCol;
	} while (inputStr != "exit");
}


// Function to check validity of user input. Checks if input is in correct range for current player's turn, and if it is correct data type.
bool GameEngine::checkValidInput()
{
	// TODO: Add your implementation code here.
	return false;
}


// Takes in user input from the command line, returns it in the form of a tuple.
tuple<int, int> GameEngine::takeUserInput()
{
	// TODO: Add your implementation code here.
	return make_tuple(0,0);
}
