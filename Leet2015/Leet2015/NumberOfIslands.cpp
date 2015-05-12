#include "stdafx.h"

//Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.
//An island is surrounded by water and is formed by connecting adjacent lands 
//horizontally or vertically.You may assume all four edges of the grid are all 
//surrounded by water.
//
//		Example 1:
//
//		11110
//		11010
//		11000
//		00000
//Answer : 1
//
//		 Example 2 :
//
//		 11000
//		 11000
//		 00100
//		 00011
//Answer : 3

namespace Solution1
{
	void flipOne(vector<vector<char>>& grid, int row, int col, int maxRow, int maxCol)
	{
		if (row < 0 || row > maxRow || col < 0 || col > maxCol || grid[row][col] == '0')
		{
			return;
		}
		grid[row][col] = '0';

		flipOne(grid, row - 1, col, maxRow, maxCol);
		flipOne(grid, row + 1, col, maxRow, maxCol);
		flipOne(grid, row, col-1, maxRow, maxCol);
		flipOne(grid, row, col+1, maxRow, maxCol);
	}
	
	int numIslands(vector<vector<char>>& grid) 
	{
		int result = 0;
		int rowCount = grid.size();
		if (rowCount == 0) { return result; }
		int colCount = grid[0].size();
		if (colCount == 0) { return result; }
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				if (grid[i][j] == '1')
				{
					flipOne(grid, i, j, rowCount-1, colCount-1);
					result++;
				}
			}
		}
		return result;
	}

	void NumberOfIslands()
	{
		vector<vector<char>> input = { { '1', '0' } };
		print(numIslands(input));
	}
}