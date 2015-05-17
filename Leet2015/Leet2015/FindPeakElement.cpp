#include "stdafx.h"

//A peak element is an element that is greater than its neighbors.
//
//Given an input array where num[i] ≠ num[i + 1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that num[-1] = num[n] = -∞.
//
//For example, in array[1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
//
//click to show spoilers.
//
//Note:
//Your solution should be in logarithmic complexity.

namespace Solution1
{
	int findPeakElement(vector<int>& nums)
	{
		int len = nums.size();
		if (len == 1) { return 0; }
		int start = 0;
		int end = len - 1;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			int leftVal = mid - 1 < 0 ? INT_MIN : nums[mid - 1];
			int rightVal = mid + 1 >= len ? INT_MIN : nums[mid + 1];
			int midVal = nums[mid];
			if (midVal > leftVal && midVal > rightVal)
			{
				return mid;
			}
			else if (midVal < leftVal)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		return -1;
	}

	namespace tooSlow
	{
		int findPeakElement(vector<int>& nums)
		{
			int result = 0;
			int peakVal = INT_MIN;
			int len = nums.size();
			if (len == 1) { return 0; }

			for (int i = 0; i < len; i++)
			{
				if (nums[i] > peakVal)
				{
					result = i;
					peakVal = nums[i];
				}
			}
			return result;
		}
	}


	void FindPeakElement()
	{
		vector<int> input = createVector({ 1, 2, 3, 1 });
		print(findPeakElement(input));
	}
}