#include "stdafx.h"


//Given an array of integers, every element appears three times except for one.Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?

namespace Solution1
{
	int singleNumberII(int A[], int n) 
	{
		int ones = 0;
		int twos = 0;
		int threes = 0;
		for (int i = 0; i < n; i++)
		{
			twos |= ones & A[i];
			ones ^= A[i];
			threes = ones & twos;
			ones &= ~threes;
			twos &= ~threes;
		}
		return ones;
	}

	int singleNumber2(int A[], int n)
	{
		int map[32] = { 0 };
		int mask = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 32; j++)
			{
				if (A[i] == 0) { break; }
				if (A[i] & mask)
				{
					map[j]++;
				}
				A[i] >>= 1;
			}
			
		}

		int result = 0;
		for (int i = 31; i >=0; i--)
		{
			result = (result << 1) | (map[i] % 3);
		}
		return result;
	}

	void SingleNumberII()
	{
		int A[4] = {5, 5, 5, 2};
		// Error: need to >> A[i] by 1 regardless current bit is 1 or 0.
		// Error: when reconstruct the final result, note that since we are <<. so we need to start with the high bits instead of the lower bits
		//print(singleNumber2(A, 4));
		print(singleNumberII(A, 4));
	}
}