#include "stdafx.h"

//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process : Starting with any positive integer, 
//replace the number by the sum of the squares of its digits, and repeat the process until the number
//equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those 
//numbers for which this process ends in 1 are happy numbers.
//
//Example : 19 is a happy number
//
//		  1^2 + 9^2 = 82
//		  8^2 + 2^2 = 68
//		  6^2 + 8^2 = 100
//		  1^2 + 0^2 + 0^2 = 1

namespace Solution1
{
	bool isHappy(int n)
	{
		unordered_set<int> set;
		int val = n;

		bool isHappy = false;

		while (set.count(val) == 0)
		{
			set.insert(val);
			int cur = 0;
			while (val)
			{
				int digit = val % 10;
				cur += digit * digit;
				val /= 10;
			}
			if (cur == 1) 
			{
				isHappy = true; 
				break;
			}
			val = cur;
		}
		return isHappy;
	}

	void HappyNumber()
	{
		print(isHappy(19));
	}
}