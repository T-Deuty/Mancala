#pragma once

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Board
{
private:
	string buildGridString();
	int playerMancala = 0;
	int opponentMancala = 0;

public:
	vector<vector <int>> grid;
	Board();
	~Board();
	// prints the current state of the board to the console
	void printBoard();
	// Places a gem at the specified location
	int placeGem(int row, int col, int remaining, int currentPlayer);
	int placeGem(int mancala, int remaining);
	// 
	// Sets the number of gems in specified coordinates to 0
	void emptyContainer(int row, int col);
};

