#include "stdafx.h"
//
//Given an index k, return the kth row of the Pascal's triangle.
//
//
//[
//	[1],
//	[1, 1],
//	[1, 2, 1],
//	[1, 3, 3, 1],
//	[1, 4, 6, 4, 1]
//]
//For example, given k = 3,
//Return[1, 3, 3, 1].
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space ?

namespace Solution1
{
	vector<int> getRow(int rowIndex) {
		vector<int> result(rowIndex + 1, 0);
		result[0] = 1;

		for (int i = 1; i <= rowIndex; i++)
		{
			for (int j = i; j >= 0; j--)
			{
				result[j] += (j-1 >= 0) ? result[j - 1] : 0;
			}
		}
		return result;
	}


	void PascalsTriangleII()
	{
		print(getRow(3));
	}
};