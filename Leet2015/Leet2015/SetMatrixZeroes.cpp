#include "stdafx.h"

//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

namespace Solution1
{
	void setZeroes(vector<vector<int> > &matrix) 
	{
		int rowCount = matrix.size();
		if (rowCount == 0) { return; }
		int colCount = matrix[0].size();
		if (colCount == 0) { return; }

		bool firstRowHasZero = false;
		for (int i : matrix[0])
		{
			if (i == 0)
			{
				firstRowHasZero = true;
				break;
			}
		}
		bool firstColHasZero = false;
		for (int i = 0; i < rowCount; i++)
		{
			if (matrix[i][0]==0)
			{
				firstColHasZero = true;
				break;
			}
		}

		for (int i = 1; i < rowCount; i++)
		{
			for (int j = 1; j < colCount; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < rowCount; i++)
		{
			if (matrix[i][0] == 0)
			{
				for (int j = 1; j < colCount; j++)
				{
					matrix[i][j] = 0;
				}
			}
		}
		for (int i = 1; i < colCount; i++)
		{
			if (matrix[0][i] == 0)
			{
				for (int j = 1; j < rowCount; j++)
				{
					matrix[j][i] = 0;
				}
			}
		}
		if (firstRowHasZero)
		{
			for (int i = 0; i < colCount; i++)
			{
				matrix[0][i] = 0;
			}
		}
		if (firstColHasZero)
		{
			for (int i = 0; i < rowCount; i++)
			{
				matrix[i][0] = 0;
			}
		}
	}

	void SetMatrixZeroes()
	{
		vector<vector<int> > matrix = { {1} };
		setZeroes(matrix);
	}
}