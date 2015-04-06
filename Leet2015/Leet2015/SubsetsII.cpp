#include "stdafx.h"

//Given a collection of integers that might contain duplicates, S, return all possible subsets.
//
//Note:
//Elements in a subset must be in non - descending order.
//The solution set must not contain duplicate subsets.
//For example,
//If S = [1, 2, 2], a solution is :
//
//[
//	[2],
//	[1],
//	[1, 2, 2],
//	[2, 2],
//	[1, 2],
//	[]
//]

namespace Solution1
{
	void subsetsWithDup(vector<int>& s, int start, int maxLevel, vector<int> result, vector<vector<int>>& results)
	{
		for (int i = start; i < maxLevel; i++)
		{
			result.push_back(s[i]);
			results.push_back(result);
			subsetsWithDup(s, i + 1, maxLevel, result, results);
			result.pop_back();

			while (i+1 < maxLevel && s[i] == s[i + 1])
			{
				i++;
			}
		}
	}

	vector<vector<int> > subsetsWithDup(vector<int> &S)
	{
		int len = S.size();
		vector<vector<int>>results;
		if (len == 0) { return results; }

		sort(S.begin(), S.end());
		vector<int> result;
		results.push_back(result);
		subsetsWithDup(S, 0, len, result, results);
		return results;
	}

	void SubsetsII()
	{
		print(subsetsWithDup(createVector({1,2, 2})));
	}
}