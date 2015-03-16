#include "stdafx.h"

//Given an integer n, return the number of trailing zeroes in n!.
//
//Note: Your solution should be in logarithmic time complexity.

namespace Solution1
{
	int trailingZeroes(int n) 
	{
		int count = 0;
		while (n >= 5)
		{
			n /= 5;
			count += n;
		}
		return count;
	}

	void FactorialTrailingZeroes()
	{		
		int n = 30;
		print(trailingZeroes(n));
	}
};