#include "pch.h"
#include "Board.h"


enum Rows
{
	topRow,
	bottomRow
};

void Board::printRows()
{
	// print first row, opponent then player
	for (int i = 0; i < opponentGrid.size(); i++) {
		cout << "[" << opponentGrid[i][topRow] << "] ";
	}
	for (int i = 0; i < playerGrid.size(); i++) {
		cout << "[" << playerGrid[i][topRow] << "] ";
	}

	//newline
	cout << endl;

	// print bottom row, opponent then player
	for (int i = 0; i < opponentGrid.size(); i++) {
		cout << "[" << opponentGrid[i][bottomRow] << "] ";
	}
	for (int i = 0; i < playerGrid.size(); i++) {
		cout << "[" << playerGrid[i][bottomRow] << "] ";
	}
}

void Board::printCols()
{
}

Board::Board()
{

	// opponent grid
	for (int i = 0; i < 3; i++) {
		opponentGrid.push_back(vector<int>());
		for (int j = 0; j < 3; j++) {
			opponentGrid[i].push_back(4);
		}
	}
	
	// player grid
	for (int i = 0; i < 3; i++) {
		playerGrid.push_back(vector<int>());
		for (int j = 0; j < 3; j++) {
			playerGrid[i].push_back(4);
		}
	}
}


Board::~Board()
{
}


// prints the current state of the board to the console
void Board::printBoard()
{
	printRows();
}
