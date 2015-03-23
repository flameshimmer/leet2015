#include "stdafx.h"

//Given two integers n and k, return all possible combinations 
//of k numbers out of 1 ... n.
//
//For example,
//If n = 4 and k = 2, a solution is :
//
//[
//	[2, 4],
//	[3, 4],
//	[2, 3],
//	[1, 2],
//	[1, 3],
//	[1, 4],
//]

namespace Solution1
{
	void recurse(int n, int k, int curLevel, vector<int> result, vector<vector<int>>& results)
	{
		if (result.size() == k || curLevel >= n)
		{
			if (result.size() == k)
			{
				results.push_back(result);
			}			
			return;
		}

		recurse(n, k, curLevel + 1, result, results);
		result.push_back(curLevel + 1);
		recurse(n, k, curLevel + 1, result, results);
	}

	vector<vector<int> > combine(int n, int k) {
		vector<int> result;
		vector<vector<int>> results;
		recurse(n, k, 0, result, results);
		return results;
	}

	void recurse2(int n, int k, int curLevel, vector<int> result, vector<vector<int>>& results)
	{
		if (result.size() == k)
		{
			results.push_back(result);
			return;
		}

		for (int i = curLevel; i <= n; i++)
		{
			result.push_back(i);
			recurse2(n, k, i + 1, result, results);
			result.pop_back();
		}
	}

	vector<vector<int> > combine2(int n, int k) {
		vector<int> result;
		vector<vector<int>> results;
		recurse2(n, k, 1, result, results);
		return results;
	}

	void Combinations()
	{
		print(combine(4, 2));
		
		// Error: note that the curLevel for the nest recursion should start with i+1, instead of curLevel+1
		print(combine2(4, 2)); // 22ms
	}
};