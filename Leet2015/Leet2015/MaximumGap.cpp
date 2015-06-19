#include "stdafx.h"
#include <set>

//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Try to solve it in linear time / space.
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.

namespace Solution1
{
	int maximumGap(vector<int>& nums) 
	{
		int len = nums.size();
		if (len < 2) { return 0; }

		set<int> s;
		for (int i : nums){ s.insert(i); }

		int maxGap = INT_MIN;
		int last = -1;
		for (int i : s)
		{
			if (last < 0) { last = i; }
			else
			{
				maxGap = max(maxGap, i - last);
				last = i;
			}
		}
		return maxGap;
	}

	void MaximumGap()
	{
	}
}