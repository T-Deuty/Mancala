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
	gridStr.append("| |\n|" + to_string(playerMancala) + string("| "));

	// build first row
	for (size_t i = 0; i < grid[0].size(); i++) {
		gridStr += string("[") + to_string(grid[topRow][i]) + "] ";
	}

	//newline
	gridStr.append("|" + to_string(opponentMancala) + string("|\n| | "));

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
int Board::placeGem(int row, int col, int remaining, int currentPlayer)
{
	// catch the case where the gem landed in an empty spot on the player's side
	if (remaining == 1 && grid[row][col] == 0 && currentPlayer == row) {

		// add final gem and contents of opposite grid spot to player's mancala

		if (currentPlayer == 0) {
			playerMancala += (grid[1][col] + 1);
		}
		else {
			opponentMancala += (grid[0][col] + 1);
		}
	}
	else {
		grid[row][col]++;
	}

	remaining--;

	return remaining;
}

// Places a gem at the specified location
int Board::placeGem(int mancala, int remaining)
{

	if (mancala) {
		opponentMancala++;
	}
	else {
		playerMancala++;
	}
	
	remaining--;

	return remaining;
}

// Sets the number of gems in specified coordinates to 0
void Board::emptyContainer(int row, int col)
{
	// TODO: Add your implementation code here.
	grid[row][col] = 0;
}
