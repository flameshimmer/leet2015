#include "stdafx.h"

//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i
//to its next station(i + 1).You begin the journey with an empty tank at one of the gas stations.
//
//Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
//
//Note:
//The solution is guaranteed to be unique.

namespace Solution1
{
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
	{
		int len = gas.size();
		if (len == 0) { return -1; }
		vector<int> diff(len, 0);
		for (int i = 0; i < len; i++)
		{
			diff[i] = gas[i] - cost[i];
		}


	}

	void GasStation()
	{
	}
} 