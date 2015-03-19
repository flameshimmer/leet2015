#include "stdafx.h"

//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].
//
//Note:
//Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

namespace Solution1
{
	void reverse(int nums[], int start, int end)
	{
		while (start < end)
		{
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
			start++;
			end--;
		}
	}

	void rotate(int nums[], int n, int k) {
		k = n - k % n;

		reverse(nums, 0, k - 1);
		reverse(nums, k, n-1);
		reverse(nums, 0, n - 1);
	}

	void RotateArray()
	{
		int nums[7] = { 1, 2, 3, 4, 5, 6, 7 };
		rotate(nums, 7, 10);
		print(nums, 7);
	}
};