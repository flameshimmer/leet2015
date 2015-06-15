#include "stdafx.h"

//Given an array of integers, find if the array contains any duplicates.
//Your function should return true if any value appears at least twice in the array, 
//and it should return false if every element is distinct.

namespace Solution1
{
	bool containsDuplicate(vector<int>& nums) 
	{
		unordered_set<int> set;
		for (int val : nums)
		{
			if (set.find(val) == set.end())
			{
				set.insert(val);
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	void ContainsDuplicate()
	{
	}
}