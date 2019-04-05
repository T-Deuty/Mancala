#include "pch.h"
#include "Board.h"


enum Rows
{
	topRow,
	bottomRow
};

string Board::buildGridString()
{
	string gridStr = "";

	// build opponent mancala
	gridStr.append("| |");
	gridStr.append(25, ' ');
	gridStr.append("| |\n|" + to_string(opponentMancala) + string("| "));

	// build first row, opponent then player
	for (size_t i = 0; i < opponentGrid.size(); i++) {
		//cout << "[" << opponentGrid[i][topRow] << "] ";
		gridStr += string("[") + to_string(opponentGrid[i][topRow]) + "] ";
	}
	for (size_t i = 0; i < playerGrid.size(); i++) {
		//cout << "[" << playerGrid[i][topRow] << "] ";
		gridStr += string("[") + to_string(playerGrid[i][topRow]) + "] ";
	}

	//newline
	gridStr.append("|" + to_string(playerMancala) + string("|\n| | "));

	// build bottom row, opponent then player
	for (size_t i = 0; i < opponentGrid.size(); i++) {
		//cout << "[" << opponentGrid[i][bottomRow] << "] ";
		gridStr += string("[") + to_string(opponentGrid[i][bottomRow]) + "] ";
	}
	for (size_t i = 0; i < playerGrid.size(); i++) {
		gridStr += string("[") + to_string(playerGrid[i][bottomRow]) + "] ";
	}

	gridStr.append("| |\n| |");
	gridStr.append(25, ' ');
	gridStr.append("| |");

	return gridStr;
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

	// print rows
	string boardString = buildGridString();

	cout << boardString;
}
