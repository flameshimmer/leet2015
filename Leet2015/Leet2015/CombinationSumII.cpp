#include "stdafx.h"

//Given a collection of candidate numbers(C) and a target number(T), 
//find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//All numbers(including target) will be positive integers.
//Elements in a combination(a1, a2, …, ak) must be in non - descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//For example, given candidate set 10, 1, 2, 7, 6, 1, 5 and target 8,
//A solution set is :
//[1, 7]
//[1, 2, 5]
//[2, 6]
//[1, 1, 6]

namespace Solution1{

	void recurse(vector<int>& num, int target, unsigned int start, vector<int>result, vector<vector<int>>& results)
	{
		if (target == 0)
		{
			results.push_back(result);
			return;
		}

		for (unsigned int i = start; i < num.size(); i++)
		{
			if (i>start && num[i] == num[i - 1]){ continue; }
			if (num[i] <= target)
			{ 
				result.push_back(num[i]);
				recurse(num, target - num[i], i + 1, result, results);
				result.pop_back();
			}
		}
	}
	
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int>> results;
		if (num.empty()){ return results; }
		vector<int> result;
		sort(num.begin(), num.end());
		recurse(num, target, 0, result, results);
		return results;
	}
	
	void CombinationSumII()
	{
		print(combinationSum2(createVector({ 10, 1, 2, 7, 6, 1, 5 }), 8));
	}
};