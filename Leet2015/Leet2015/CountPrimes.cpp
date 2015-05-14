#include "stdafx.h"

//Count the number of prime numbers less than a non - negative number, n

namespace Solution1
{
	int countPrimes(int n) {
		if (n <= 2) { return 0; }
		int sum = 1;
		int upper = sqrt(n);
		bool* passed = new bool[n];
		for (int i = 3; i < n; i += 2)
		{
			if (!passed[i])
			{
				sum++;
				if (i > upper) { continue; }
				for (int j = i*i; j < n; j += i)
				{
					passed[j] = true;
				}
			}
		}
		delete passed;
		return sum;
	}

	void CountPrimes()
	{
		print(countPrimes(10));
	}
}