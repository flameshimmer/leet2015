#include "stdafx.h"

//Follow up for "Unique Paths":
//
//Now consider if some obstacles are added to the grids.How many unique paths would there be ?
//
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//For example,
//There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
//[
//	[0, 0, 0],
//	[0, 1, 0],
//	[0, 0, 0]
//]
//The total number of unique paths is 2.
//
//Note: m and n will be at most 100.

namespace Solution1{

	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int row = obstacleGrid.size();
		int col = (row > 0) ? obstacleGrid[0].size() : 0;

		if (row == 0 || col == 0) { return 0; }
		if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1) { return 0; }

		vector<int>A(col, 1);
		int k = 0;
		for (k; k < col; k++)
		{
			if (obstacleGrid[0][k] == 1)
			{
				break;
			}			
		}
		while (k < col)
		{
			A[k] = 0;
			k++;
		}

		for (int i = 1; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (obstacleGrid[i][j] == 1)
				{
					A[j] = 0;
				}
				else
				{
					A[j] += (j>=1) ? A[j - 1] : 0;
				}
			}
		}
		return A[col - 1];
	}

	void UniquePathsII()
	{
		vector<vector<int>>map(1, vector<int>(1, 0));	
		print(uniquePathsWithObstacles(map));

		vector<vector<int>>map2(1, createVector({0, 1}));
		print(uniquePathsWithObstacles(map2));

		// Error: Note that in this case we need to process the first column of the A array, since the A[0] can change to 0 if the map said that position is blocked
		vector<vector<int>>map3; 
		map3.push_back(createVector({ 0 }));
		map3.push_back(createVector({ 1 }));
		print(uniquePathsWithObstacles(map3));

		vector<vector<int>>map4(2, vector<int>(2, 0));
		print(uniquePathsWithObstacles(map4));
	}
};