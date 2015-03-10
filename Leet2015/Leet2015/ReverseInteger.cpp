#include "stdafx.h"

//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//	  Example2 : x = -123, return -321

namespace Solution1
{
	int reverse(int x) 
	{
		int result = 0;
		while (x)
		{
			if ((x > 0 && (INT_MAX - x % 10) / 10 < result) || (x < 0 && (INT_MIN - x % 10) / 10 > result))
			{
				return 0;
			}
			else
			{
				result = result * 10 + x % 10;
				x /= 10;
			}
		}
		return result;
	}

	void ReverseInteger()
	{
		// Error: x can't be using /= 10 and also having div*= 10 at the same time. 
		print(reverse(123));
		print(reverse(-123));

		//// To get the number from right to left one by one, use number / div % 10, where div is multiplied by 10 every loop.
		//// To get the number from left to right one by one, use number % div1 / div2, where div1 10 ^ (n - 1) and div2 is 10 ^ (n - 2)
		//
		//// To get rid of the first digit of a number, use num % 10 ^ (n-1), where n is the digit count of this number
		//// eg. 123 % 100 = 23
		//// To get rid of the last digit of a number, use num / 10
		//// eg. 123 / 10 = 12

		//// To get the first digit of a number, use num / 10 ^ (n-1)
		//// eg. 123 / 100 = 1
		//// To get the last digit of a number, use num % 10
		//// eg. 123 % 10 = 3
		print(reverse(100));
		print(reverse(-100));


		// INT_MAX is 2147483647
		// INT_MIN is -2147483648
		// Error: don't multiply -1 to the input since the input can be INT_MIN, which has one more digit than INT_MAX.
		// Error: don't bother to check the sign of the input, just use the negative number to do the calculateion
		// Error: don't use while( x/10 > 0), should user while (x/10), because in the case of x is negative, x/10 will be smaller than 0
		// Error: have a div to multiply by 10 every time, this eventually cause div to go out of bound. Should use x/=10 to avoid using div at all
		print(reverse(1534236469));
		print(reverse(-2147483412));

	}
}