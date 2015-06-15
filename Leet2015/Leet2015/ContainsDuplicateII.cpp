#include "stdafx.h"

//Given an array of integers and an integer k, find out whether there there 
//are two distinct indices i and j in the array such that nums[i] = nums[j] 
//and the difference between i and j is at most k.

namespace Solution1
{
	bool containsNearbyDuplicate(vector<int>& nums, int k) 
	{
		int len = nums.size();
		if (len < 2) { return false; }
		
		unordered_map<int, int> map;
		for (int j = 0; j < len; j++)
		{
			int val = nums[j];			
			if (map.find(val) != map.end())
			{				
				if (j - map[val] <= k)
				{
					return true;
				}								
			}
			map[val] = j;
		}
		return false;
	}
	
	void ContainsDuplicateII()
	{
		vector<int> input = { -1, -1 };
		print(containsNearbyDuplicate(input, 1));
	}
}