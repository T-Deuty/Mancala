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
		if (moveCoordinates == breakTuple) {
			handleInvalidInput();
		}
		else {
			makeMove(moveCoordinates);
		}
	} while (inputStr != "exit");
}


// Function to check validity of user input. Checks if input is in correct range for current player's turn, and if it is correct data type.
bool GameEngine::checkValidInput(int rowOrCol, int input)
{
	bool returnVal = false;
	
	if (rowOrCol == row) {
		if (input >= 0 && input <= 5) {
			returnVal = true;
		}
	}
	else if (rowOrCol == col) {
		//TODO - add player validation
		if (input == 0 || input == 1) {
			returnVal = true;
		}
	}

	return returnVal;
}

bool GameEngine::checkValidInput(string input)
{
	bool returnVal = true;

	if (input == "exit") {
		return false;
	}

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
	// TODO: Add your implementation code here.
	cout << "\nEnter a row and column to make the next move. Type \"exit\" to end the program. \nEnter the row: ";
	getline(cin, inputStr);

	if (!checkValidInput(inputStr)) {
		handleInvalidInput(inputStr);
		return breakTuple;
	}

	stringstream(inputStr) >> moveRow;

	if (!checkValidInput(0, moveRow)) {
		handleInvalidInput("error", moveRow);
		return breakTuple;
	}

	cout << "\nEnter the column: ";
	getline(cin, inputStr);

	if (!checkValidInput(inputStr)) {
		handleInvalidInput(inputStr);
		return breakTuple;
	}

	stringstream(inputStr) >> moveCol;


	if (!checkValidInput(1, moveCol)) {
		handleInvalidInput("error", moveCol);
		return breakTuple;
	}

	return make_tuple(moveRow, moveCol);
}


// Handles invalid user input, displays error message per invalid case
void GameEngine::handleInvalidInput(string stringInput, int intInput)
{
	if (stringInput == "error") {
		// TODO: better message handling here
		cout << "\nInput is out of acceptable range for current player. The current player is " << currentPlayer << "." << endl;
		handleUserInput();
	}
	else if (stringInput == "exit") {
		cout << "\nExiting program. Thanks for playing!" << endl;
	}
	else {
		cout << "\nInvalid input, please try the move again.\n";
	}
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
		if (get<1>(moveCoordinates) == player) {
			moveLeft(remaining, moveCol);
		}
		else {
			moveRight(remaining, moveCol);
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

	while (remaining > 0 && moveCol > 0) {
		moveCol--;
		remaining = gameBoard->placeGem(0, moveCol, remaining);
	}

	if (remaining > 0 && moveCol == 0) {
		remaining = gameBoard->placeGem(player, remaining);
		if (remaining > 0) {
			moveRight(remaining, moveCol);
		}
	}
}


// Handles right movement on the board
void GameEngine::moveRight(int remaining, int moveCol)
{
	while (remaining > 0 && moveCol < 5) {
		moveCol++;
		remaining = gameBoard->placeGem(1, moveCol, remaining);
	}

	if (remaining > 0 && moveCol == 5) {
		remaining = gameBoard->placeGem(opponent, remaining);
		if (remaining > 0) {
			moveLeft(remaining, moveCol);
		}
	}
}
