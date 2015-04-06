#include "stdafx.h"

//Implement pow(x, n).

namespace Solution1
{
	double pow(double x, int n) 
	{
		if (n == 0) { return 1; }
		if (n == 1) { return x; }
		bool isNeg = n < 0;
		if (isNeg) { n = -n; }
		double half = pow(x, n / 2);
		double result;
		if (n % 2 == 1)
		{
			result =  half * half * x;
		}
		else
		{
			result = half* half;
		}
		return isNeg ? 1 / result : result;
	}

	namespace other
	{
		double pow(double x, int n)
		{
			if (n == 0) { return 1; }
			if (n == 1) { return x; }
			bool isNeg = n < 0;
			if (isNeg) { n = -n; }
			
			double half = x;
			double result = 1;
			while (n>0)
			{
				if (n % 2 == 1)
				{
					result *= half;
				}
				half *= half;
				n = n / 2;
			}
			return isNeg ? 1 / result : result;
		}
	}
	void Pow()
	{
		using namespace other;
		other::pow(5.0, 5);
		other::pow(6.0, 4);
	}
}