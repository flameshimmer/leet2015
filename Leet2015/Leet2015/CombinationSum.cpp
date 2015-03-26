#include "stdafx.h"

//Given a set of candidate numbers(C) and a target number(T), 
//find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//All numbers(including target) will be positive integers.
//Elements in a combination(a1, a2, …, ak) must be in 
//non - descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//
//For example, given candidate set 2, 3, 6, 7 and target 7,
//
//A solution set is :
//[7]
//[2, 2, 3]

namespace Solution1
{
	void recurse(vector<int>candidates, int target, int start, vector<int> result, vector<vector<int>>& results)
	{		
		if (target == 0)
		{
			results.push_back(result);
			return;
		}		

		int len = candidates.size();
		for (int i = start; i<len; i++)
		{
			if (i>start && candidates[i] == candidates[i - 1]){ continue; }
			if (candidates[i] <= target)
			{
				result.push_back(candidates[i]);
				recurse(candidates, target - candidates[i], i, result, results);
				result.pop_back();
			}
		}
	}

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> result;
		vector<vector<int>> results;
		if (candidates.empty()) { return results; }

		recurse(candidates, target, 0, result, results);
		return results;
	}
	
	
	void CombinationSum()
	{
		print(combinationSum(createVector({2, 3, 6, 7}), 7));
		print(combinationSum(createVector({ 1 }), 1));
	}
};