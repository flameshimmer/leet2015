#include "stdafx.h"

//Given a 2D binary matrix filled with 0's and 1's, 
//find the largest rectangle containing all ones and return its area.

namespace Solution1
{
	int getLargestRectInHistogram(vector<int> height)
	{
		int result = 0;
		stack<int> s;
		height.push_back(0);

		for (int i = 0; i < height.size(); i++)
		{
			if (s.empty() || height[s.top()] <= height[i])
			{
				s.push(i);
			}
			else
			{
				int temp = s.top();
				s.pop();
				int startIndex = s.empty() ? -1 : s.top();
				result = max(result, height[temp] * (i - startIndex - 1));
				i--;
			}
		}
		return result;
	}
	int maximalRectangle(vector<vector<char> > &matrix)
	{
		int rowCount = matrix.size();
		if (rowCount == 0) { return 0; }
		int colCount = matrix[0].size();
		if (colCount == 0) { return 0; }
		
		int result = 0;
		vector<int>height(matrix[0].size(), 0);
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				height[j] = (matrix[i][j] == '0') ? 0 : height[j] + 1;				
			}
			result = max(result, getLargestRectInHistogram(height));
		}
		return result;
	}

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
					int lastValue = (j >= 1) ? newMatrix[i][j - 1] : 0;
					newMatrix[i][j] = (matrix[i][j] == '0') ? 0 : lastValue + 1;
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
		//print(other::maximalRectangle(input));
	}
}