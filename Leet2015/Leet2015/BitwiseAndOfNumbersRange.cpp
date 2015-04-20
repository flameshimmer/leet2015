#include "stdafx.h"

//Given a range[m, n] where 0 <= m <= n <= 2147483647, 
//return the bitwise AND of all numbers in this range, inclusive.
//
//For example, given the range[5, 7], you should return 4.

namespace Solution1
{
	int rangeBitwiseAnd(int m, int n) 
	{
		int diff = n - m;
		int x = 0;
		while (diff > 0)
		{
			x = x << 1 | 1;
			diff >>= 1;
		}
		return m & n & ~x;
	}

	void BitwiseAndOfNumbersRange()
	{
		print(rangeBitwiseAnd(5, 7));
		print(rangeBitwiseAnd(2, 2));
	}
}