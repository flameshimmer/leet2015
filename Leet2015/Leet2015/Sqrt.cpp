#include "stdafx.h"

//Implement int sqrt(int x).
//
//Compute and return the square root of x.

namespace Solution1
{
	int mySqrt(int x)
	{
		long long start = 0;
		long long end = x / 2 + 1;
		while (start <= end)
		{
			long long mid = start + (end - start) / 2;
			long long val = mid* mid;			
			if (val == x)
			{
				return mid;
			}
			else if (val < x)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}			
		}
		return end;
	}

	namespace NewtonsMethod
	{
		int mySqrt(int x)
		{
			if (x == 0) { return 0; }
			double last = 0;
			double cur = 1;
			while (last != cur)
			{
				last = cur;
				cur = (last + x / last) / 2;
			}
			return (int)cur;
		}
	}

	namespace other
	{
		int mySqrt(int x)
		{
			if (x < 2) { return x; }
			int start = 0;
			int end = x;

			while (start <= end)
			{
				int mid = start + (end - start) / 2;

				int remain = x / mid;
				if (remain == mid)
				{
					return mid;
				}
				else if (remain > mid)
				{
					start = mid + 1;
				}
				else
				{
					end = mid - 1;
				}
			}
			return end;
		}
	}
	void Sqrt()
	{
		print(NewtonsMethod::mySqrt(0));
		print(NewtonsMethod::mySqrt(1));
		print(NewtonsMethod::mySqrt(INT_MAX));
	}
}