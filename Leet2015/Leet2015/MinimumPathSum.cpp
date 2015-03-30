#include "stdafx.h"

//Given a m x n grid filled with non - negative numbers, 
//find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.

namespace Solution1
{
	int minPathSum(vector<vector<int> > &grid) 
	{
		int rowCount = grid.size();
		if (rowCount == 0) { return 0; }
		int colCount = grid[0].size();

		vector<int> A(colCount, INT_MAX);
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				if (i == 0 && j == 0) { A[j] = grid[0][0]; continue; }
				int v1 = grid[i][j];
				int v2 = min(((j >= 1) ? A[j - 1] : INT_MAX), A[j]);
				A[j] = v1 + v2;
			}
		}
		return A[colCount - 1];
	}

	void MinimumPathSum()
	{
		// Error: note that the out of bound case should be INT_MAX instead of 0!
		//        The only special case is for 0, 0.
		vector<vector<int>> grid;
		grid.push_back(createVector({1, 3, 1}));
		grid.push_back(createVector({ 1, 5, 1}));
		grid.push_back(createVector({ 4, 2, 1 }));
		print(minPathSum(grid));
	}
}