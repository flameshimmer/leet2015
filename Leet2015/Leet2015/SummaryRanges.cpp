#include "stdafx.h"

//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//For example, given[0, 1, 2, 4, 5, 7], return["0->2", "4->5", "7"].

namespace Solution1
{
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		int len = nums.size();
		if (len == 0) { return result; }

		int start = 0;
		while (start < len)
		{
			int end = start + 1;
			while (start < len && end < len && nums[end] == nums[end-1] + 1)
			{
				end++;
			}
			end--;
			string range = (start == end) ? to_string(nums[start]) : (to_string(nums[start]) + "->" + to_string(nums[end]));
			result.push_back(range);
			start = end + 1;
		}

		return result;
	}

	void SummaryRanges()
	{
		vector<int> input;
		input = {-1};
		print(summaryRanges(input));

		input = { 1, 3 };
		print(summaryRanges(input));

		input = { 0, 1};
		print(summaryRanges(input));

		input = { INT_MIN, INT_MIN + 1, INT_MAX };
		print(summaryRanges(input));
	}
}