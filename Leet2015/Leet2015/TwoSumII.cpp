#include "stdafx.h"

//Given an array of integers that is already sorted in ascending order, 
//find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that 
//they add up to the target, where index1 must be less than index2.Please 
//note that your returned answers(both index1 and index2) are not zero - based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers = { 2, 7, 11, 15 }, target = 9
//   Output : index1 = 1, index2 = 2

namespace Solution1
{

	vector<int> twoSum2(vector<int>& numbers, int target)
	{
		int len = numbers.size();
		vector<int> result;
		if (len < 2) { return result; }
		int start = 0;
		int end = len - 1;

		while (start < end)
		{
			int sum = numbers[start] + numbers[end];
			if (sum == target)
			{
				result.push_back(start + 1);
				result.push_back(end + 1);
				break;
			}
			else if (sum < target)
			{
				start++;
			}
			else
			{
				end--;
			}
		}
		return result;
	}



	void TwoSumII()
	{
		print(twoSum2(createVector({ 2, 7, 11, 15 }), 9));
	}
}