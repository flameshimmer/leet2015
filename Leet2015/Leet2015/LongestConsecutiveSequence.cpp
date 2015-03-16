#include "stdafx.h"


//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//For example,
//Given[100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is[1, 2, 3, 4].Return its length : 4.
//
//Your algorithm should run in O(n) complexity.


namespace Solution1
{
	int longestConsecutive(vector<int> &num) {
		int length = num.size();
		if (length < 2) { return length; }

		map<int, int> myMap; // key, count
		for (int val : num)
		{
			myMap[val]++;
		}
		int result = 0;
		int curIndex = 0;
		int lastValue = 0;
		int curLen = 0;
		for (auto item : myMap)
		{
			if (curIndex != 0 && item.first == lastValue + 1)
			{
				curLen++;
			}
			else
			{
				curLen = 1;				
			}
			result = max(result, curLen);
			lastValue = item.first;
			curIndex++;
		}

		return result;
	}

	void LongestConsecutiveSequence()
	{
		// Error: Did not consider the input can contain repeated numbers. If using hash map we need to keep count,
		// to keep track of the repeated numbers
		print(longestConsecutive(createVector({ 100, 4, 200, 1, 3, 2 })));

		print(longestConsecutive(createVector({ 0, 0 })));

	}
}