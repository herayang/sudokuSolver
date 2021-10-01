#pragma once
class Sudoku
{	
	public: 
		int** readSudoku();
		bool isInCol(int col, int num,int** board);
		bool isInRow(int row, int num, int** board);
		bool isInBox(int mini_row, int mini_col, int num,int** board);
		bool isEmpty(int& row, int& col, int** board);
		bool isValidMove(int row, int col, int num, int** board);
		
		bool solveSudoku(int** board);
		void printSudoku(); 

};

