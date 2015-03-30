#include "stdafx.h"

//Determine if a Sudoku is valid, according to : Sudoku Puzzles - The Rules.(http://sudoku.com.au/TheRules.aspx)
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//A partially filled sudoku which is valid.
//
//Note :
//	 A valid Sudoku board(partially filled) is not necessarily solvable.
//	 Only the filled cells need to be validated.
//

namespace Solution1
{
	bool validate(vector<vector<char> > &board, int row, int col, int map[])
	{
		char c = board[row][col];
		if (c == '.')
		{
			return true;
		}
		if (map[c - '0'] == 1)
		{
			return false;
		}
		else
		{
			map[c - '0'] = 1;
		}
		return true;
	}
	
	bool validateNineGrid(vector<vector<char> > &board, int row, int col, int map[])
	{
		for (int i = row; i < row + 3; i++)
		{
			for (int j = col; j < col + 3; j++)
			{
				if (!validate(board, i, j, map)) { return false; }
			}
		}
		return true;
	}

	bool isValidSudoku(vector<vector<char> > &board) {
		// check the row		
		for (unsigned int i = 0; i < board.size(); i++)
		{
			int map[10] = { 0 };
			for (unsigned int j = 0; j < board[i].size(); j++)
			{
				if (!validate(board, i, j, map)) { return false; }
			}
		}

		// check the colums		
		for (unsigned int i = 0; i < board[0].size(); i++)
		{
			int map[10] = { 0 };
			for (unsigned int j = 0; j < board.size(); j++)
			{
				if (!validate(board, j, i, map)) { return false; }
			}
		}
		
		// check for nine grid
		for (unsigned i = 0; i < board.size(); i += 3)
		{
			for (unsigned j = 0; j < board[0].size(); j += 3)
			{
				int map[10] = { 0 };
				if (!validateNineGrid(board, i, j, map))
				{
					return false;
				}
			}
		}
		return true;
	}

	void ValidSudoku()
	{
		string rawInput[9] = { ".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........" };
		vector<vector<char>> board = createMatrix(rawInput, 9);
		print(isValidSudoku(board));
	}
}