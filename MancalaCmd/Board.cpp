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
	for (size_t i = 0; i < grid[0].size(); i++) {
		gridStr += string("[") + to_string(grid[topRow][i]) + "] ";
	}

	//newline
	gridStr.append("|" + to_string(playerMancala) + string("|\n| | "));

	// build bottom row, opponent then player
	for (size_t i = 0; i < grid[1].size(); i++) {
		gridStr += string("[") + to_string(grid[bottomRow][i]) + "] ";
	}

	gridStr.append("| |\n| |");
	gridStr.append(25, ' ');
	gridStr.append("| |");

	return gridStr;
}

Board::Board()
{
	// build grid
	for (int i = 0; i < 2; i++) {
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


// Places a gem at the specified location
int Board::placeGem(int row, int col, int remaining)
{
	remaining--;

	grid[row][col]++;

	return remaining;
}

// Places a gem at the specified location
int Board::placeGem(int mancala, int remaining)
{
	remaining--;
	if (mancala) {
		opponentMancala++;
	}
	else {
		playerMancala++;
	}
	return remaining;
}

// Sets the number of gems in specified coordinates to 0
void Board::emptyContainer(int row, int col)
{
	// TODO: Add your implementation code here.
	grid[row][col] = 0;
}
