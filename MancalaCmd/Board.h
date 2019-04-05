#pragma once

#include <vector>
#include <iostream>
using namespace std;

class Board
{
private:
	vector<vector <int>> opponentGrid;
	vector<vector <int>> playerGrid;
	void printRows();
	void printCols();

public:
	Board();
	~Board();
	// prints the current state of the board to the console
	void printBoard();
};

