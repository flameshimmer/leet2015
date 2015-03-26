#include "stdafx.h"

//Given an array of integers, every element appears twice except for one.Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory?

namespace Solution1
{
	int singleNumber(int A[], int n) {
		int result = A[0];
		for (int i = 1; i < n; i++)
		{
			result ^= A[i];
		}
		return result;
	}
	
	void SingleNumber()
	{
	
	}
};