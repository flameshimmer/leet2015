#include "stdafx.h"

//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.

namespace Solution1
{
	int divide(int dividend, int divisor) 
	{
		long long  result = 0;
		long long  count = 1;
		long long  total = dividend > 0 ? dividend : ((long long)dividend * -1);
		long long  div = divisor > 0 ? divisor : ((long long)divisor * -1);
		long long  tempDiv = div;

		bool isNeg = !((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0));

		while (total >= div)
		{
			while (total >= tempDiv)
			{
				tempDiv <<= 1;
				count <<= 1;		
			}
			total -= tempDiv >> 1;
			result += count >> 1;
			tempDiv = div;
			count = 1;
		}
		if (isNeg) { result *= -1; }
		if (result > INT_MAX) { return INT_MAX; }
		if (result < INT_MIN) { return INT_MIN; }
		return (int)result;
	}

	void DivideTwoIntegers()
	{
		// Error: did not consider the negative input case
		// Error: note that to avoid overflow and bunch of checks use long long
		//print(divide(7, 2));
		//print(divide(1, -1));
		//print(divide(2147483647, 1));
		//print(divide(-1010369383, INT_MIN));
		//print(divide(2147483647, -1));
		print(divide(INT_MIN, -1));

	}
}

