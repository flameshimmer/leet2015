#include "stdafx.h"

//Given a triangle, find the minimum path sum from top to bottom.Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//[
//	[2],
//	[3, 4],
//	[6, 5, 7],
//	[4, 1, 8, 3]
//]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//

namespace Solution1
{
	int minimumTotal(vector<vector<int> > &triangle) 
	{
		int rowCount = triangle.size();
		if (rowCount == 0) { return 0; }
		int colCount = triangle[rowCount-1].size();

		vector<int>M(colCount, INT_MAX);
		M[0] = triangle[0][0];
		for (int i = 1; i < rowCount; i++)
		{
			int size = triangle[i].size();
			for (int j = size-1; j >=0; j--)
			{
				int top = M[j];
				int left = j>=1 ? M[j - 1] : INT_MAX;
				M[j] = triangle[i][j] + min(top, left);
			}
		}
		int result = M[0];
		for (int i = 1; i < colCount; i++)
		{
			result = min(result, M[i]);
		}
		return result;
	}

	void Triangle()
	{
		// Error: colCount should be the size of the last row of the triangle, not the first row
		// Error: use row size -1 to define the start index of the j
		vector<vector<int>> triangle = {
			{ -7 }, 
			{ -2, 1 }, 
			{ -5, -5, 9 }, 
			{ -4, -5, 4, 4 }, 
			{ -6, -6, 2, -1, -5 }, 
			{ 3, 7, 8, -3, 7, -9 }, 
			{ -9, -1, -9, 6, 9, 0, 7 }, 
			{ -7, 0, -6, -8, 7, 1, -4, 9 }, 
			{ -3, 2, -6, -9, -7, -6, -9, 4, 0 }, 
			{ -8, -6, -3, -9, -2, -6, 7, -5, 0, 7 }, 
			{ -9, -1, -2, 4, -2, 4, 4, -1, 2, -5, 5 },
			{ 1, 1, -6, 1, -2, -4, 4, -2, 6, -6, 0, 6 },
			{ -3, -3, -6, -2, -6, -2, 7, -9, -5, -7, -5, 5, 1 } 
		};
		print(minimumTotal(triangle));
	}
};