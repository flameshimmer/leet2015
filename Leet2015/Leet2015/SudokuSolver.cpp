#include "stdafx.h"


//Write a program to solve a Sudoku puzzle by filling the empty cells.
//
//Empty cells are indicated by the character '.'.
//
//You may assume that there will be only one unique solution.

namespace Solution1
{	
	bool isValid(vector<vector<char>>& board, int row, int col, char val)
	{
		// check the row
		for (unsigned int i = 0; i < board[row].size(); i++)
		{
			if (board[row][i] == val)
			{
				return false;
			}
		}
		// check the col
		for (unsigned int i = 0; i < board.size(); i++)
		{
			if (board[i][col] == val)
			{
				return false;
			}
		}
		// check the nine grid
		int startRow = row / 3 * 3;
		int startCol = col / 3 * 3;
		for (int i = startRow; i < startRow + 3; i++)
		{
			for (int j = startCol; j < startCol + 3; j++)
			{
				if (board[i][j] == val)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool recurse(vector<vector<char>>& board, int row, int col, int maxRow, int maxCol)
	{
		if (row == maxRow)
		{
			return true;
		}
		int nextRow = row;
		int nextCol = col + 1;
		if (nextCol == maxCol)
		{
			nextCol = 0;
			nextRow++;
		}

		if (board[row][col] != '.')
		{
			return recurse(board, nextRow, nextCol, maxRow, maxCol);
		}

		for (int i = 1; i <= 9; i++)
		{
			if (isValid(board, row, col, '0' + i))
			{
				board[row][col] = '0' + i;
				//print(board);
				if (recurse(board, nextRow, nextCol, maxRow, maxCol))
				{
					return true;
				}				
			}
		}
		board[row][col] = '.';
		return false;
	}
	
	
	void solveSudoku(vector<vector<char> > &board)
	{
		recurse(board, 0, 0, board.size(), board[0].size());
	}

	void SudokuSolver()
	{
		// Error: fill in number should be from 1 to 9, and no 0 is allowed. This means the candidate inspection should be from index1
		// Perf: just directly checking whether the filled in value is valid or not is better than passing out a candidate array
		// Perr: if the passed in parameter is vector<vector<char>> &, it is much much faster than using vector<vector<char>>, since in 
		//       the case of the latter, the copy constructor keeps duplicating the vector, which takes a big chunks of time.
		string rawInput[9] = { "..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.." };
		vector<vector<char>> board = createMatrix(rawInput, 9);
		solveSudoku(board);
		print(board);
//		if (isValidSudoku(board)) { cout << "Valid!\n"; }
	//	else { cout << "Not Valid!\n"; }
	}
}