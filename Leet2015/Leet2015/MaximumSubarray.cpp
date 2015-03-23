#include "stdafx.h"

//Find the contiguous subarray within an array(containing at least one number)
//which has the largest sum.
//
//For example, given the array[−2, 1, −3, 4, −1, 2, 1, −5, 4],
//the contiguous subarray[4, −1, 2, 1] has the largest sum = 6.

namespace Solution1
{
	int maxSubArray(int A[], int n) 
	{		
		if (n == 0) { return 0; }
		int curSum = A[0];
		int maxSum = A[0];
		for (int i = 1; i < n; i++)
		{			
			if (curSum <= 0)
			{
				curSum = A[i];
			}
			else
			{
				curSum += A[i];
			}
			maxSum = max(curSum, maxSum);
		}
		return maxSum;
	}

	void MaximumSubarray()
	{
		// Error: Should start the for loop at index 1. Because selecting no element in the array is not an option.
	}
};