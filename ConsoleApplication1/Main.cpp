
/***
	Main for sudoku solver which solves and fills out empty spaces 
	(represented with 0) in unsolved Sudoku. 
***/
#include <iostream>
#include "Sudoku.h"
using namespace std;


int main() {
	Sudoku s; 
	int** grid = s.readSudoku();

	//print out grid before solving
	cout << "Unsolved Sudoku: \n";
	s.printSudoku(grid);

	
	//print out solved grid 
	if (s.solveSudoku(grid) == true) {
		cout << "After solving: \n";
		s.printSudoku(grid);
		s.saveSolution(grid);
	}

	//error message for when a puzzle couldn't be solved 
	else {

		cout << "Uh oh, I couldn't find the solution";
	}

};
