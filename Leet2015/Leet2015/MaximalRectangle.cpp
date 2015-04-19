#include "stdafx.h"

//Given a 2D binary matrix filled with 0's and 1's, 
//find the largest rectangle containing all ones and return its area.

namespace Solution1
{
	namespace other{
		int maximalRectangle(vector<vector<char> > &matrix)
		{
			int result = 0;
			int rowCount = matrix.size();
			if (rowCount == 0) { return result; }
			int colCount = matrix[0].size();

			vector<vector<int> > newMatrix(rowCount, vector<int>(colCount, 0));
			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					newMatrix[i][j] = (matrix[i][j] == '0') ? 0 : newMatrix[i][j - 1] + 1;
				}
			}


			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					int higher = i-1; 
					int lower = i+1;
					while (higher >= 0 && newMatrix[higher][j] >= newMatrix[i][j])
					{
						higher--;
					}
					while (lower < rowCount && newMatrix[lower][j] >= newMatrix[i][j])
					{
						lower++;
					}
					int height = lower - higher - 1;
					result = max(result, height * newMatrix[i][j]);
				}
			}
			return result;
		}
	}
	

	void MaximalRectangle()
	{
		vector<vector<char>> input = { { '1' } };
		print(other::maximalRectangle(input));
	}
}