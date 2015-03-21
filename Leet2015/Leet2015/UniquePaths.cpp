#include "stdafx.h"

//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time.The robot is trying to reach the 
//bottom - right corner of the grid(marked 'Finish' in the diagram below).
//
//How many possible unique paths are there ?

namespace Solution1
{
	int uniquePaths(int m, int n) {
		vector<int>A(n, 1);

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				A[j] += A[j - 1];
			}
		}
		return A[n - 1];
	}

	void recurse(int m, int n, int curM, int curN, string result, vector<string>& results)
	{
		if (m == curM && n == curN)
		{
			results.push_back(result);
			return;
		}

		if (curM < m)
		{
			recurse(m, n, curM + 1, curN, result+ "Down->", results);
		}
		
		if (curN < n)
		{
			recurse(m, n, curM, curN + 1, result + "Left->", results);
		}		
	}

	int uniquePathsRecursive(int m, int n) {
		string result;
		vector<string> results;
		// Note that now that we are standing at 0, 0 position, we only need to move m-1, n-1 into the m, n position. 
		recurse(m-1, n-1, 0, 0, result, results);
		print(results);
		return results.size();
	}

	void UniquePaths()
	{
		// Error: note that the calculation for j should be from left to right. Instead of from right to left.
		print(uniquePaths(2, 2));

		print(uniquePaths(3, 3)); // 2ms

		print(uniquePathsRecursive(3, 3)); // 16ms
 	}
};