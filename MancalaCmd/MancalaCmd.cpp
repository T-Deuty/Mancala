// MancalaCmd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Board.h"

int main()
{
	Board gameBoard = Board();

	gameBoard.printBoard();

	int moveRow, moveCol;
	string inputStr;

	do {
		cout << "\nEnter a row and column to make the next move. Type \"exit\" to end the program. \nEnter the row: ";
		getline(cin, inputStr);
		if (inputStr == "exit") break;
		stringstream(inputStr) >> moveRow;
		cout << "\nEnter the column: ";
		getline(cin, inputStr);
		if (inputStr == "exit") break;
		stringstream(inputStr) >> moveCol;
	} while (inputStr != "exit");

	exit(0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
