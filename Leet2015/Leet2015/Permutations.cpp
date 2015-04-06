#include "stdafx.h"

//Given a collection of numbers, return all possible permutations.
//
//For example,
//[1, 2, 3] have the following permutations :
//[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and[3, 2, 1].

namespace Solution1
{
	void permute(vector<int>& num, vector<bool>lookup, int level, int maxLevel, vector<int>&result, vector<vector<int>>& results)
	{
		if (level == maxLevel)
		{
			results.push_back(result);
			return;
		}

		for (int i = 0; i < maxLevel; i++)
		{
			if (lookup[i]) { continue; }			
			result.push_back(num[i]);
			lookup[i] = true;
			permute(num, lookup, level + 1, maxLevel, result, results);
			lookup[i] = false;
			result.pop_back();
		}
	}
	vector<vector<int> > permute(vector<int> &num) 
	{
		vector<vector<int>>results;
		int len = num.size();
		if (len == 0) { return results; }

		vector<bool>lookup(len, false);
		vector<int>result;
		permute(num, lookup, 0, len, result, results);
		return results;
	}

	void Permutation()
	{
		print(permute(createVector({1, 2, 3})));
	}
}