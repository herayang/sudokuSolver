
#include <iostream>
#include<fstream>
#include "Sudoku.h"
using namespace std;

/**
	Reads in a textfile and returns a 9x9 Sudoku board represented 
	in a two-dimensional int array. 


	@returns int** A two-dimensional int array which represents a Sudoku baord (grid[9][9]) 
*/
int** Sudoku::readSudoku() {
	// reads puzzle #5 text file 
	ifstream file{ "puzzle5.txt" };

	if (file.fail()) {
		cout << "no file";
	};

	//makes a 2D array from text file containing unsolved Sudoku. 
	int** grid = new int*[9];
	 
	for (int i = 0; i < 9; i++) {
		grid[i] = new int[9];
		for (int j = 0; j < 9; j++) {
			file >> grid[i][j];
		}
	}
	return grid;
}


/**
	Checks a given column in a sudoku board and checks if a number is in the 
	row. 

	@param row: Nth row of the board being checked.
	@param num: A guess to be checked whether if it's in the given row. 
	@param board: 9x9 sudoku board read from txt file  

	@returns bool Returns True if num is found in row.  
*/
bool Sudoku::isInRow(int row, int num, int** board) {
	for (int col = 0; col < 9; col++) {
		if (board[row][col] == num) {
			return true;
		}
	}
	return false;
}

/**
	Checks a given column in a sudoku board and checks if a number is in the
	column.

	@param col: Nth column of the board being checked.
	@param num: A guess to be checked whether if it's in the given row.
	@param board: 9x9 sudoku board read from txt file

	@returns bool Returns True if the num is found in the column
*/
bool Sudoku::isInCol(int col, int num, int** board) {

	for (int row = 0; row < 9; row++) {
		if (board[row][col] == num) {
			return true;
		}
	}
	return false;
}

/**
	Checks a given column in a sudoku board and checks if a number is in the
	mini 3x3 box.

	@param mini_row: starting row of mini 3x3 box within the 9x9 Sudoku board. 
	@param mini_col: starting column of mini 3x3 box within the 9x9 Sudoku board 
	@param num: A guess to be checked whether if it's in the given row.
	@param board: 9x9 sudoku board read from txt file.

	@returns bool Returns True if the num is found in the mini 3x3 box with given mini_row, mini_col values. 
*/
bool Sudoku::isInBox(int mini_row, int mini_col, int num, int** board) {
	
	// go through mini box
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {

			//if any space in the 3x3 mini box contains the same value as num, return True 
			if (board[row + mini_row][col + mini_col] == num) {
				return true;
			}
		}
	}
	return false; 
}

/**
	Looks through the row and columns of the Sudoku board and checks for empty 
	spaces represented with a value 0. If empty space is found, returns True. 

	@param row: row of the board being checked.
	@param col: column of the board being checked.
	@param board: 9x9 sudoku board read from txt file.

	@returns bool Returns True if an empty space was found in the given Sudoku board. 
*/
bool Sudoku::isEmpty(int& row, int& col, int** board) {

	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			// found empty space represented with 0 
			if (board[row][col] == 0)
				return true;
		}	
	}	
	return false;
}

/**
	Checks if the given num in a given position (row and column) is a valid guess.
	If the guess number was found in the given row, column, or 3x3 box it is in, it returns 
	false. 

	@param row: row of the board being checked.
	@param col: column of the board being checked.
	@param num: the guess number for the position. 
	@param board: 9x9 sudoku board read from txt file.

	@returns bool Returns True when the num can be in the given row and columnn. 
*/
bool Sudoku::isValidMove(int row, int col, int num, int** board) {

	// number found in row; invalid 
	if (isInRow(row, num, board)) {
		return false;
	}
	// number found in column; invalid 
	if (isInCol(col, num,board)) {
		return false; 
	}
	// number found in box; invalid 
	if (isInBox(row - row % 3, col - col % 3,num, board )) {
		return false; 
	}

	// number not found in row, column, or 3x3 box! Valid move. 
	return true; 
}

/**
	Solves the empty sudoku board using recursion/backtracking. 

	@param board: 9x9 sudoku board read from txt file.

	@returns bool Returns True when the puzzle is solved. 
*/
bool Sudoku::solveSudoku(int** board) {
	int row, col;

	// All solved
	if (!isEmpty(row, col, board)) {
		return true;
	}

	//valid guesses 1-9
	for (int num = 1; num <= 9; num++) {
		if (isValidMove(row, col, num, board)) {
			board[row][col] = num;
			//recursively go through 
			if (solveSudoku(board)) {
				return true;
			}
			board[row][col] = 0;
		}	
	}
	return false;
}