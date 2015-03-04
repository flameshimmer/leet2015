#include "stdafx.h"
using namespace std;

//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets 
// in the array which gives the sum of zero.

//Note :
//	 Elements in a triplet(a, b, c) must be in non - descending order. (ie, a ≤ b ≤ c)
//	 The solution set must not contain duplicate triplets.
//	 For example, given array S = { -1 0 1 2 - 1 - 4 },
//-4, -1, -1, 0, 1, 2
//	 A solution set is :
//  (-1, 0, 1)
//	(-1, -1, 2)


namespace Solution1
{
	vector<vector<int>> threeSum(vector<int> &num) {
		vector<vector<int>> result;
		int len = num.size();
		if (len < 3){ return result; }

		std::sort(num.begin(), num.end());
		//print(num);
		for (int i = 0; i < len-1; i++)
		{
			int target = 0 - num[i];

			int start = i + 1;
			int end = len - 1;

			while (start < end)
			{
				int curValue = num[start] + num[end];
				if (target == curValue)
				{
					vector<int> set;
					set.push_back(num[i]);
					set.push_back(num[start]);
					set.push_back(num[end]);
					result.push_back(set);
					while (start < end && num[start] == num[start + 1])
					{
						start++;
					}
					while (start < end && num[end] == num[end - 1])
					{
						end--;
					}
					start++;
					continue;
				}
				else if (curValue > target)
				{
					end--;
				}
				else
				{
					start++;
				}
			}
			while ((i+ 1 < len) && num[i] == num[i + 1])
			{
				i++;
			}
		}
		return result;
	}

	void ThreeSum()
	{

		//print(threeSum(createVector({ -1, 0, 1, 2, -1, -4 })));

		// Error: did not shrink index when find an answer
		// Error: did not keep looking when already find an answer
		// Error: did not realize how to achieve avoid duplication.
		print(threeSum(createVector({ 0,0,0,0 })));

		// Error: did not advance pointer properly after shrinking begin and end index in the case of result found
		//        should first check duplication then advance pointer
		print(threeSum(createVector({ -1, 0, 1, 0 })));

		// Error: should not shrink start and end index before results are found. Otherwise will miss potential hit result
		// Error: index out of bound in while loop using index i+1. Will need to check the i+1 is not out of bound. 
		print(threeSum(createVector({-2, 0, 1, 1, 2})));

		printf("complete!\n");
	}
};