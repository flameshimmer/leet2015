#include "stdafx.h"

//Find all possible combinations of k numbers that add up to a number n, 
//given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//Ensure that numbers within the set are sorted in ascending order.
//
//Example 1:
//
//Input : k = 3, n = 7
//
//Output :
//
//	   [[1, 2, 4]]
//
//		Example 2 :
//
//		Input : k = 3, n = 9
//
//			Output :
//
//				   [[1, 2, 6], [1, 3, 5], [2, 3, 4]]

namespace Solution1
{
	void combinationSumk(int k, int n, int start, bool* candidate, vector<int>& result, vector<vector<int>>& results)
	{
		if (n <= 0 || k == 0)
		{
			if (n == 0 && k == 0)
			{
				results.push_back(result);
			}
			return;
		}
		
		for (int i = start; i < 10; i++)
		{
			if (candidate[i])
			{
				candidate[i] = false;
				result.push_back(i);
				combinationSumk(k - 1, n - i, i+1, candidate, result, results);
				result.pop_back();
				candidate[i] = true;
			}
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) 
	{
		bool candidate[10];
		for (int i = 0; i < 10; i++)
		{
			candidate[i] = true;
		}
		vector<int> result;
		vector<vector<int>> results;
		combinationSumk(k, n, 1, candidate, result, results);
		return results;
	}

	void CombinationSumIII()
	{
		print(combinationSum3(3, 7));
		print(combinationSum3(3, 9));
	}
}