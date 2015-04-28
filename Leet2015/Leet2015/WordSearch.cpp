#include "stdafx.h"

//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, 
//where "adjacent" cells are those horizontally or vertically neighboring.
//The same letter cell may not be used more than once.
//
//For example,
//Given board =
//
//[
//	["ABCE"],
//	["SFES"],
//	["ADEE"]
//]
//word = "ABCCED", ->returns true,
//word = "SEE", ->returns true,
//word = "ABCB", ->returns false.

namespace Solution1
{
	bool wordSearch(vector<vector<char>>&board, string word, vector<vector<bool>>&map, int level, int row, int col, int rowCount, int colCount, int len)
	{
		if (level == len)
		{
			return true;
		}

		int nextRow = row + 1;
		int nextCol = col + 1;
		int prevRow = row - 1;
		int prevCol = col - 1;

		if (nextRow < rowCount)
		{
			if (map[nextRow][col] == false && board[nextRow][col] == word[level])
			{
				map[nextRow][col] = true;
				if (wordSearch(board, word, map, level + 1, nextRow, col, rowCount, colCount, len))
				{
					return true;
				}
				map[nextRow][col] = false;
			}
		}
		if (nextCol < colCount)
		{
			if (map[row][nextCol] == false && board[row][nextCol] == word[level])
			{
				map[row][nextCol] = true;
				if (wordSearch(board, word, map, level + 1, row, nextCol, rowCount, colCount, len))
				{
					return true;
				}
				map[row][nextCol] = false;
			}
		}
		if (prevRow >= 0)
		{
			if (map[prevRow][col] == false && board[prevRow][col] == word[level])
			{
				map[prevRow][col] = true;
				if (wordSearch(board, word, map, level + 1, prevRow, col, rowCount, colCount, len))
				{
					return true;
				}
				map[prevRow][col] = false;
			}
		}
		if (prevCol >= 0)
		{
			if (map[row][prevCol] == false && board[row][prevCol] == word[level])
			{
				map[row][prevCol] = true;
				if (wordSearch(board, word, map, level + 1, row, prevCol, rowCount, colCount, len))
				{
					return true;
				}
				map[row][prevCol] = false;
			}
		}
		return false;
	}

	bool exist(vector<vector<char> > &board, string word) 
	{
		int rowCount = board.size();
		if (rowCount == 0){ return false; }
		int colCount = board[0].size();
		if (colCount == 0) { return false; }
		vector<vector<bool>>map(rowCount, vector<bool>(colCount, false));

		char c = word[0];
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				if (board[i][j] == c)
				{
					map[i][j] = true;
					if (wordSearch(board, word, map, 1, i, j, rowCount, colCount, word.length()))
					{
						return true;
					}
					map[i][j] = false;
				}
			}
		}
		return false;
	}

	void WordSearch()
	{
		//string rawInput[9] = { "ABCE", "SFCS", "ADEE"};
		//vector<vector<char>> board = createMatrix(rawInput, 3);
		//print(exist(board, "ABCCED"));
		//print(exist(board, "SEE"));
		//print(exist(board, "ABCB"));

		string rawInput[9] = { "ABCE", "SFES", "ADEE" };
		vector<vector<char>> board = createMatrix(rawInput, 3);
		print(exist(board, "ABCESEEEFS"));

		//string rawInput[9] = { "ab" };
		//vector<vector<char>> board = createMatrix(rawInput, 1);
		//print(exist(board, "ab"));
	}
}