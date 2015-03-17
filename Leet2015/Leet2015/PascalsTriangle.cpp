#include "stdafx.h"

//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//	[1],
//	[1, 1],
//	[1, 2, 1],
//	[1, 3, 3, 1],
//	[1, 4, 6, 4, 1]
//]
namespace Solution1
{
	vector<vector<int> > generate(int numRows) 
	{
		vector<vector<int>> results(numRows);
		if (numRows == 0) { return results; }

		results[0] = vector<int>(1, 1);
		for (int i = 1; i < numRows; i++)
		{
			vector<int> result = vector<int>(i+1, 0);
			vector<int> prevRow = results[i-1];
			for (int j = i; j >= 0; j--)
			{
				int top = j > ((int)(prevRow.size()) - 1) ? 0 : prevRow[j];
				int left = j >= 1 ? prevRow[j - 1] : 0;
				result[j] = top + left;
			}
			results[i] = result;
		}
		return results;
	}
	
	void PascalsTriangle()
	{
		// Error: did not consider the special case of 0. Fixed by early return when 0 is passed as parameter
		print(generate(5));
	}
};