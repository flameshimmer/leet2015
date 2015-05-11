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
	namespace tooSlow
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


			for (int start = 0; start < len; start++)
			{
				int curGas = 0;
				for (int i = start; i < len; i++)
				{
					curGas += diff[i];
					if (curGas < 0)
					{
						break;
					}
				}
				if (curGas >= 0)
				{
					for (int j = 0; j < start; j++)
					{
						curGas += diff[j];
						if (curGas < 0)
						{
							break;
						}
					}
					if (curGas >= 0)
					{
						return start;
					}
				}
			}
			return -1;
		}
	}
	
	namespace other
	{
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
		{
			int len = gas.size();

			for (int i = 0; i < len;)
			{
				int j = 0;
				int curGas = 0;
				for (j; j < len; j++)
				{
					int index = (i + j) % len;
					curGas += gas[index] - cost[index];
					if (curGas < 0)
					{
						i += j + 1;
						break;
					}
				}
				if (j == len) { return i; }
			}
			return -1;
		}
	}

	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		int len = gas.size();		
		int total = 0;
		int curGas = 0;
		int startNode = 0;
		for (int i = 0; i < len; i++)
		{
			int diff = gas[i] - cost[i];
			total += diff;
			curGas += diff;

			if (curGas < 0)
			{
				startNode = i + 1;
				curGas = 0;
			}
		}
		if (total < 0) { return -1; }
		return startNode;
	}

	void GasStation()
	{
		// Error: note that the curGas should be += the diff for every station
		print(canCompleteCircuit(createVector({ 1,2 }), createVector({2, 1})));
	}
} 