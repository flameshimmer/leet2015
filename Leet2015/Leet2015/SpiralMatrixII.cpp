#include "stdafx.h"

//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//Given n = 3,
//
//You should return the following matrix :
//[
//	[1, 2, 3],
//	[8, 9, 4],
//	[7, 6, 5]
//]

namespace Solution1
{
	vector<vector<int> > generateMatrix(int n) {
		
		vector<vector<int>> result(n, vector<int>(n, 0));
		if (n == 0) { return result; }
		int minRow = 0;
		int maxRow = n - 1;
		int minCol = 0;
		int maxCol = n - 1;

		int row = 0;
		int col = 0;
		int val = 1;
		int turnCount = 0; // 0 -> left, 1->down, 2->right, 3->up
		while (minRow <= maxRow && minCol <= maxCol)
		{
			switch (turnCount % 4)
			{
			case 0:
				row = minRow;
				col = minCol;
				while (col <= maxCol)
				{
					result[row][col] = val;
					val++;
					col++;
				}
				minRow++;
				break;
			case 1:
				row = minRow;
				col = maxCol;
				while (row <= maxRow)
				{
					result[row][col] = val;
					val++;
					row++;
				}
				maxCol--;
				break;
			case 2:
				row = maxRow;
				col = maxCol;
				while (col >= minCol)
				{
					result[row][col] = val;
					val++;
					col--;
				}
				maxRow--;
				break;
			case 3:
				row = maxRow;
				col = minCol;
				while (row >= minRow)
				{
					result[row][col] = val;
					val++;
					row--;
				}
				minCol++;
				break;
			}
			turnCount++;
		}
		return result;
	}

	void SpiralMatrixII()
	{
		print(generateMatrix(3));
	}
}