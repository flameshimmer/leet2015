#include "stdafx.h"

//Given an array of non - negative integers, you are 
//initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example :
//A = [2, 3, 1, 1, 4], return true.
//
//A = [3, 2, 1, 0, 4], return false.

namespace Solution1
{
	bool canJump(vector<int>& nums) {
		int len = nums.size();
		int resource = 0;
		for (int i = 0; i < len; i++)
		{
			resource = max(resource - 1, nums[i]);
			if (resource == 0 && i != len - 1) { return false; }
		}
		return true;
	}

	void JumpGame()
	{
	}
}