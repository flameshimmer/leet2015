#include "stdafx.h"

//You are climbing a stair case.It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps.
//In how many distinct ways can you climb to the top ?

namespace Solution1
{
	int climbStairs(int n) {
		vector<int> ways(n+1, 0);
		ways[0] = 1;
		ways[1] = 1;
		for (int i = 2; i < n + 1; i++)
		{
			ways[i] = ways[i - 1] + ways[i - 2];
		}
		return ways[n];
	}

	void ClimbingStairs()
	{
	}
}