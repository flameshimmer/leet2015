#include "stdafx.h"

//Note: This is an extension of House Robber.
//
//After robbing those houses on that street, the thief has found himself a new 
//place for his thievery so that he will not get too much attention.This time, 
//all houses at this place are arranged in a circle.That means the first house 
//is the neighbor of the last one.Meanwhile, the security system for these houses
//remain the same as for those in the previous street.
//
//Given a list of non - negative integers representing the amount of money of 
//each house, determine the maximum amount of money you can rob tonight without 
//alerting the police.

namespace Solution1
{
	namespace II
	{
		int res(vector<int>& num, int start, int end)
		{
			int last = 0; int lastLast = 0;
			for (int i = start; i < end; i++)
			{
				lastLast = max(last, lastLast + num[i]);
				swap(lastLast, last);
			}
			return max(last, lastLast);
		}
		int rob(vector<int>& nums) 
		{
			int len = nums.size();
			if (len == 1) { return nums[0]; }
			return max(res(nums, 0, len - 1), res(nums, 1, len));
		}

		namespace other{
			int rob(vector<int>& nums) {
				int len = nums.size();
				if (len == 0) { return 0; }
				if (len == 1) { return nums[0]; }

				vector<int>M(len, 0);
				M[0] = nums[0];
				M[1] = max(nums[0], nums[1]);
				for (int i = 2; i < len; i++)
				{
					M[i] = max(M[i - 1], M[i - 2] + nums[i]);
				}
				int usedResult = M[len - 2];

				M[0] = 0;
				M[1] = nums[1];
				for (int i = 2; i < len; i++)
				{
					M[i] = max(M[i - 1], M[i - 2] + nums[i]);
				}
				int notUsedResult = M[len - 1];
				return max(usedResult, notUsedResult);
			}
		}
	}
	void HouseRobberII()
	{
		vector<int> input = {1};
		II::rob(input);
	}
}