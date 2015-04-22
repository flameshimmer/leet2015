#include "stdafx.h"

//Given a matrix of m x n elements(m rows, n columns), 
//return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix :
//
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//]
//You should return[1, 2, 3, 6, 9, 8, 7, 4, 5].

namespace Solution1
{
	vector<int> spiralOrder(vector<vector<int> > &matrix) 
	{
		vector<int> result;
		int rowCount = matrix.size();
		if (rowCount == 0) { return result; }
		int colCount = matrix[0].size();
		
		vector<string>options = { "right", "down", "left", "up" };
		int turnCount = 0;

		int row = 0;
		int col = 0;
		int maxRow = rowCount - 1;
		int minRow = 0;
		int maxCol = colCount - 1;
		int minCol = 0;

		while (maxRow >= minRow &&
			maxCol >= minCol)
		{
			string direction = options[turnCount % 4];
			if (direction == "right")
			{
				row = minRow;
				col = minCol;
				while (col <= maxCol)
				{
					result.push_back(matrix[row][col]);
					col++;
				}
				minRow++;
			}
			else if (direction == "down")
			{
				row = minRow;
				col = maxCol;
				while (row <= maxRow)
				{
					result.push_back(matrix[row][col]);
					row++;
				}
				maxCol--;
			}
			else if (direction == "left")
			{				
				row = maxRow;
				col = maxCol;
				while (col >= minCol)
				{
					result.push_back(matrix[row][col]);
					col--;
				}
				maxRow--;
			}
			else if (direction == "up")
			{
				row = maxRow;
				col = minCol;
				while (row >= minRow)
				{
					result.push_back(matrix[row][col]);
					row--;
				}
				minCol++;
			}
			turnCount++;
		}
		return result;
	}

	void SpiralMatrix()
	{
		vector<vector<int> > matrix =  {{1, 2, 3},
										{4, 5, 6},
										{7, 8, 9}};

		vector<vector<int> > matrix2 = { { 1, 2, 3 }};
		print(spiralOrder(matrix));
	}
}