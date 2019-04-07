#pragma once

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Board
{
private:
	string buildGridString();

public:
	vector<vector <int>> grid;
	int opponentMancala = 0;
	int playerMancala = 0;
	Board();
	~Board();
	// prints the current state of the board to the console
	void printBoard();
};

