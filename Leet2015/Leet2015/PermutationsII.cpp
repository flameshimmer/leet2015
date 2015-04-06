#include "stdafx.h"

//Given a collection of numbers that might contain duplicates,
//return all possible unique permutations.
//
//For example,
//[1, 1, 2] have the following unique permutations :
//[1, 1, 2], [1, 2, 1], and[2, 1, 1].

namespace Solution1
{
	void permuteUnique(vector<int>& num, vector<bool>& lookup, int level, int maxLevel, vector<int>& result, vector<vector<int>>& results)
	{
		if (level == maxLevel)
		{
			results.push_back(result);
			return;
		}
		for (int i = 0; i < maxLevel; i++)
		{
			if (lookup[i]){ continue; }
			lookup[i] = true;
			result.push_back(num[i]);
			permuteUnique(num, lookup, level + 1, maxLevel, result, results);
			result.pop_back();
			lookup[i] = false;
			while (i+1 < maxLevel && num[i] == num[i + 1])
			{
				i++;
			}
		}
	}

	vector<vector<int> > permuteUnique(vector<int> &num) 
	{
		vector<vector<int>>results;
		int len = num.size();
		if (len == 0) { return results; }

		sort(num.begin(), num.end());
		vector<int> result;
		vector<bool> lookup(len, false);
		permuteUnique(num, lookup, 0, len, result, results);
		return results;		
	}

	void PermutationII()
	{
		print(permuteUnique(createVector({1, 1, 2})));
	}
}
