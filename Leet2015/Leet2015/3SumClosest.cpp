#include "stdafx.h"

//Given an array S of n integers, find three integers in S such that the sum is
//closest to a given number, target.Return the sum of the three integers.You may
//assume that each input would have exactly one solution.
//
//For example, given array S = { -1 2 1 - 4 }, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

namespace Solution1
{
	int threeSumClosest(vector<int> &num, int target) {
		int result = 0;
		int len = num.size();
		if (len < 3){ return result; }
		
		int curMinDiff = INT_MAX;
		sort(num.begin(), num.end());

		for (int i = 0; i < len - 2; i++)
		{
			int lookFor = target - num[i];

			int start = i + 1;
			int end = len - 1;
			while (start < end)
			{
				int curSum = num[start] + num[end];
				int diff = abs(curSum - lookFor);
				if (diff < curMinDiff)
				{
					curMinDiff = diff;
					result = curSum + num[i];
				}
				if (curSum == lookFor)
				{
					//break;
					return result;
				}
				else if (curSum < lookFor)
				{
					start++;
				}
				else
				{
					end--;
				}
			}
		}
		return result;
	}

	void ThreeSumClosest()
	{
		print(threeSumClosest(createVector({ -1, 2, 1, -4 }), 1));
		
	}
};