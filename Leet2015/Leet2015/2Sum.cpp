#include "stdafx.h"

//Given an array of integers, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, 
//where index1 must be less than index2.Please note that your returned answers(both index1 and index2) are not zero - based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers = { 2, 7, 11, 15 }, target = 9
//   Output : index1 = 1, index2 = 2

namespace Solution1{
	bool comparePair(pair<int, int> p1, pair<int, int>p2)
	{
		return p1.first < p2.first;
	}

	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		int len = numbers.size();

		if (len < 2) { return result; }

		vector<pair<int, int>> sortedData;
		for (int i = 0; i < len; i++)
		{
			sortedData.push_back(make_pair(numbers[i], i+1));
		}

		std::sort(sortedData.begin(), sortedData.end(), comparePair);

		int first = 0;
		int second = len - 1;
		while (first < second)
		{
			int sum = sortedData[first].first + sortedData[second].first;
			if (sum == target)
			{				
				result.push_back(sortedData[first].second);
				result.push_back(sortedData[second].second);
				if (result[1] < result[0])
				{
					int temp = result[0];
					result[0] = result[1];
					result[1] = temp;
				}
				break;
			}
			else if (sum < target)
			{
				first++;
			}
			else
			{
				second--;
			}
		}

		return result;
	}

	void TwoSum()
	{
		print(twoSum(createVector({ 2, 7, 11, 15 }), 9));
		
		// Error1: found out the output index is the re-arranged index, not the original index
		// Error2: boolean does not name a type (should use bool)
		// Error3: Line 21: invalid use of non-static member function (the comparason function will need to be static)
		// Error4: The result is looking for 1 based index. I returned 0 based index result
		print(twoSum(createVector({ 3, 2, 4 }), 6));

		// Error5: Did not notice the result is requiring first index must smaller than the second.
		// Error6: Reversed the swapping condition. 
		print(twoSum(createVector({ -1, -2, -3, -4, -5 }), -8));
	}
}