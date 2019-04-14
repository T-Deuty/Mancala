#include "pch.h"
#include "GameEngine.h"


GameEngine::GameEngine()
{
	gameBoard = new Board();


	gameBoard->printBoard();
}


GameEngine::~GameEngine()
{
	delete gameBoard;
}


// Called from main function to take user input until the user exits or the game finishes.
void GameEngine::handleUserInput()
{
	do {
		tuple<int, int> moveCoordinates;
		moveCoordinates = takeUserInput();
		if (moveCoordinates != breakTuple) {
			makeMove(moveCoordinates);
		}
	} while (inputStr != "exit");
}


// Function to check validity of user input. Checks if input is in correct range for current player's turn, and if it is correct data type.
bool GameEngine::checkValidInput(int rowOrCol, int input)
{
	bool returnVal = false;
	
	if (rowOrCol == col) {
		if (input >= 0 && input <= 5) {
			returnVal = true;
		}
	}
	else if (rowOrCol == row) {
		if (input == currentPlayer) {
			returnVal = true;
		}
	}

	return returnVal;
}

bool GameEngine::checkValidInput(string input)
{
	bool returnVal = true;

	for (auto ch : input) {
		returnVal = isdigit(ch);
		if (!returnVal) break;
	}

	return returnVal;
}


// Takes in user input from the command line, returns it in the form of a tuple.
tuple<int, int> GameEngine::takeUserInput()
{
	int moveRow, moveCol;
	bool errorDetected = false;
	cout << "\nEnter a row and column to make the next move. Type \"exit\" to end the program. \nEnter the row: ";
	getline(cin, inputStr);
	
	try
	{
		if (inputStr == "exit") {
			throw exitException();
		}
		else if (!checkValidInput(inputStr)) {
			throw nonIntException();
		}

		stringstream(inputStr) >> moveRow;

		if (!checkValidInput(0, moveRow)) {
			throw out_of_range("Out of range");
		}

		cout << "\nEnter the column: ";
		getline(cin, inputStr);

		if (inputStr == "exit") {
			throw exitException();
		}
		else if (!checkValidInput(inputStr)) {
			throw nonIntException();
		}

		stringstream(inputStr) >> moveCol;


		if (!checkValidInput(1, moveCol)) {
			throw out_of_range("Out of range");
		}
	}
	catch (const nonIntException& nonIntE)
	{
		errorDetected = true;
		cout << "\nInvalid input, please try the move again.\n";
	}
	catch (const exitException& exitE)
	{
		errorDetected = true;
		cout << "\nExiting program. Thanks for playing!" << endl;

	}
	catch (const out_of_range& outOfRangeE)
	{
		errorDetected = true;
		cout << "\nInput is out of acceptable range for current player. The current player is " << currentPlayer << "." << endl;
	}

	tuple<int, int> returnTuple;

	errorDetected ? returnTuple = breakTuple : returnTuple = make_tuple(moveRow, moveCol);

	return returnTuple;
}


// Updates the board with a user-defined move, and prints out the result
void GameEngine::makeMove(tuple<int, int> moveCoordinates)
{
	int startingGems = gameBoard->grid[get<0>(moveCoordinates)][get<1>(moveCoordinates)];
	int remaining = startingGems;
	int moveRow = get<0>(moveCoordinates), moveCol = get<1>(moveCoordinates);

	if (startingGems != 0) {

		gameBoard->emptyContainer(moveRow, moveCol);

		// player is top row
		if (get<0>(moveCoordinates) == player) {
			moveLeft(remaining, --moveCol);
		}
		else {
			moveRight(remaining, ++moveCol);
		}
	}
	else {
		// TODO - handle illegal move
	}

	// end of turn, swap players
	currentPlayer ? currentPlayer = 0 : currentPlayer = 1;

	gameBoard->printBoard();
}


// Handles left movement on the board
void GameEngine::moveLeft(int remaining, int moveCol)
{
	while (remaining > 0 && moveCol >= 0) {
		remaining = gameBoard->placeGem(0, moveCol, remaining);
		moveCol--;
	}

	if (remaining > 0 && moveCol < 0) {
		remaining = gameBoard->placeGem(player, remaining);
		if (remaining > 0) {
			moveCol = 0;
			moveRight(remaining, moveCol);
		}
	}
}


// Handles right movement on the board
void GameEngine::moveRight(int remaining, int moveCol)
{
	while (remaining > 0 && moveCol <= 5) {
		remaining = gameBoard->placeGem(1, moveCol, remaining);
		moveCol++;
	}

	if (remaining > 0 && moveCol > 5) {
		remaining = gameBoard->placeGem(opponent, remaining);
		if (remaining > 0) {
			moveCol = 5;
			moveLeft(remaining, moveCol);
		}
	}
}
