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

	// build first row
	for (size_t i = 0; i < grid.size(); i++) {
		gridStr += string("[") + to_string(grid[i][topRow]) + "] ";
	}

	//newline
	gridStr.append("|" + to_string(playerMancala) + string("|\n| | "));

	// build bottom row, opponent then player
	for (size_t i = 0; i < grid.size(); i++) {
		gridStr += string("[") + to_string(grid[i][bottomRow]) + "] ";
	}

	gridStr.append("| |\n| |");
	gridStr.append(25, ' ');
	gridStr.append("| |");

	return gridStr;
}

Board::Board()
{

	// build grid
	for (int i = 0; i < 6; i++) {
		grid.push_back(vector<int>());
		for (int j = 0; j < 6; j++) {
			grid[i].push_back(4);
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
