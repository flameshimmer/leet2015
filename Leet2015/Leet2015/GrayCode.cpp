#include "stdafx.h"

//The gray code is a binary numeral system where two successive values differ in only one bit.
//
//Given a non - negative integer n representing the total number of bits in the code, 
//print the sequence of gray code.A gray code sequence must begin with 0.
//
//For example, given n = 2, return[0, 1, 3, 2].Its gray code sequence is :
//
//00 - 0
//01 - 1
//11 - 3
//10 - 2
//Note :
//	 For a given n, a gray code sequence is not uniquely defined.
//
//	 For example, [0, 2, 3, 1] is also a valid gray code sequence according to the above definition.

namespace Solution1
{
	vector<int> grayCode(int n) 
	{
		vector<int> result;
		result.push_back(0);
		for (int j = 0; j < n; j++)
		{
			int len = result.size();
			int mask = 1 << j;
			for (int i = len - 1; i >= 0; i--)
			{				
				result.push_back(mask | result[i]);
			}
		}
		return result;
	}

	void GrayCode()
	{
		print(grayCode(3));
	}
}