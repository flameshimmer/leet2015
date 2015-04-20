#include "stdafx.h"

//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example :
//Given array A = [2, 3, 1, 1, 4]
//
//The minimum number of jumps to reach the last index is 2. 
//(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

namespace Solution1
{
	int jump(vector<int>& nums)
	{
		int len = nums.size();
		int start = 0;
		int end = 0;
		int totalStep = 0;
		while (end < len-1)
		{
			int maxRange = 0;
			totalStep++;
			for (int i = start; i <= end; i++)
			{		
				maxRange = max(maxRange, nums[i] + i);
			}
			start = end + 1;
			end = maxRange;
		}
		return totalStep;
	}

	namespace tooSlow{
		int getStartIndex(vector<int>& resource, int dest)
		{
			int i;
			for (i = dest - 1; i >= 0; i--)
			{
				if (resource[i] < dest - i)
				{
					break;
				}
			}
			return i + 1;
		}

		int jump(vector<int>& nums)
		{
			int len = nums.size();

			vector<int> resource(len, 0);
			resource[0] = nums[0];
			for (int k = 1; k < len; k++)
			{
				resource[k] = max(resource[k - 1] - 1, nums[k]);
			}

			vector<int> minStep(len, INT_MAX);
			minStep[0] = 0;
			minStep[1] = 1;

			for (int i = 2; i < len; i++)
			{
				int startIndex = getStartIndex(resource, i);
				for (int j = startIndex; j < i; j++)
				{
					minStep[i] = min(minStep[i], minStep[j] + 1);
				}
			}
			return minStep[len - 1];
		}
	}

	void JumpGameII()
	{
		// Error: not that the break out condition is end < len-1, instead of end < len. 
		//        since once end reaches len-1, we no longer need to jump again.
		print(jump(createVector({ 2, 3, 1, 1, 4 })));
	}
}