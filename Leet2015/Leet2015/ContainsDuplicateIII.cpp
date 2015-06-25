#include "stdafx.h"

//Given an array of integers, find out whether there are two distinct indices i and j in 
//the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

namespace Solution1
{
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	{
		int len = nums.size();
		if (k < 0 || t < 0 || len < 2) 
		{ 
			return false; 
		}

		set<int> record;

		for (int i = 0; i < len; i++)
		{
			if (i > k) { 
				record.erase(nums[i - k - 1]); 
			}
			auto lower = record.lower_bound(nums[i] - t);
			if (lower != record.end() && abs(nums[i] - *lower) <= t)
			{
				return true;
			}
			record.insert(nums[i]);
		}
		return false;
	}

	void ContainsDuplicateIII()
	{
		vector<int> nums = { 0, 10, 22, 15, 0, 5, 22, 12, 1, 5 };
		print(containsNearbyAlmostDuplicate(nums, 3, 3));
	}
}
