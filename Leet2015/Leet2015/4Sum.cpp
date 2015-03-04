#include "stdafx.h"

//Given an array S of n integers, are there elements a, b, c, and d in S such 
//that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note :
//	 Elements in a quadruplet(a, b, c, d) must be in non - descending order. (ie, a ≤ b ≤ c ≤ d)
//	 The solution set must not contain duplicate quadruplets.
//	 For example, given array S = { 1 0 - 1 0 - 2 2 }, and target = 0.
//
//	 A solution set is :
//(-1, 0, 0, 1)
//(-2, -1, 1, 2)
//(-2, 0, 0, 2)

namespace Solution1
{
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int>> results;

		int len = num.size();
		if (len < 4)
		{
			return results;
		}

		sort(num.begin(), num.end());

		for (int i = 0; i < len-3; i++)
		{
			int threeSumTarget = target - num[i];
			for (int j = i + 1; j < len - 2; j++)
			{
				int twoSumTarget = threeSumTarget - num[j];
				
				int start = j + 1;
				int end = len - 1;

				while (start < end)
				{
					int curSum = num[start] + num[end];
					if (curSum == twoSumTarget)
					{
						vector<int> result;
						result.push_back(num[i]);
						result.push_back(num[j]);
						result.push_back(num[start]);
						result.push_back(num[end]);
						results.push_back(result);

						while (start < end && num[start] == num[start + 1])
						{
							start++;
						}
						while (start < end && num[end] == num[end - 1])
						{
							end--;
						}
						start++;
						end--;
					}
					else if (curSum < twoSumTarget)
					{
						start++;
					}
					else
					{
						end--;
					}
				}
				while (j + 1 < len && num[j] == num[j + 1])
				{
					j++;
				}
			}
			while (i + 1 < len && num[i] == num[i + 1])
			{
				i++;
			}
		}
		return results;
	}


	void FourSum()
	{
		// Error: forget to return a value at the end
		print(fourSum(createVector({ 1, 0, -1, 0, -2, 2 }), 0));
	}
};