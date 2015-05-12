#include "stdafx.h"

//Given an array of n positive integers and a positive integer s, 
//find the minimal length of a subarray of which the sum ≥ s.If there isn't one, return 0 instead.
//
//For example, given the array[2, 3, 1, 2, 4, 3] and s = 7,
//the subarray[4, 3] has the minimal length under the problem constraint.
//
//click to show more practice.
//
//More practice :
//If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).


namespace Solution1
{
	int minSubArrayLen(int s, vector<int>& nums) {
		int len = nums.size();
		if (len == 0) { return 0; }

		int start = 0;
		int end = 0;
		int curSum = 0;
		int minLen = INT_MAX;
		while (end < len)
		{			
			curSum += nums[end];
			while (curSum >= s && start <= end)
			{
				minLen = min(minLen, end - start + 1);
				curSum -= nums[start];
				start++;
			}
			end++;
		}
		if (curSum < s) { return 0; }
		return minLen;
	}

	namespace other
	{
		int bsearch(int start, int end, int target, vector<int>& nums)
		{
			while (start <= end)
			{
				int mid = start + (end - start) / 2;
				if (nums[mid] < target)
				{
					start = mid + 1;
				}
				else
				{
					end = mid - 1;
				}
			}
			return start;
		}
		int minSubArrayLen(int s, vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			vector<int> sum(len+1, 0);
			for (int i = 1; i <= len; i++)
			{
				sum[i] = sum[i - 1] + nums[i-1];
			}
			int minLen = INT_MAX;
			for (int i = 0; i < len + 1; i++)
			{
				int targetVal = sum[i] + s;
				int endIndex = bsearch(i + 1, len, targetVal, sum);
				if (endIndex == len + 1) { break; }
				minLen = min(minLen, endIndex - i);
			}
			return minLen == INT_MAX ? 0 : minLen;
		}
	}

	void MinimumSizeSubarraySum()
	{
		// Error: use while loop to shink the start pointer! otherwise might encounter end index is at len-1 but start hasn't shrink short enough!
		//print(minSubArrayLen(4, createVector({ 1, 4, 4 })));
		print(other::minSubArrayLen(11, createVector({ 1, 2, 3, 4, 5 })));
	}
}