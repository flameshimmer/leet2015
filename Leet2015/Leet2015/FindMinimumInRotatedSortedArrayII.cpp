#include "stdafx.h"

//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//The array may contain duplicates.

namespace Solution1
{
	int findMin2(vector<int> &num) {
		int result = INT_MAX;

		int start = 0;
		int end = num.size() - 1;

		while (start <= end)
		{
			int mid = start + (end - start) / 2;
		
			if (num[start] < num[mid])
			{
				result = min(result, num[start]);
				start = mid + 1;
			}
			else if (num[mid] < num[end])
			{
				result = min(result, num[mid]);
				end = mid - 1;
			}
			else
			{
				start++;
				result = min(result, num[start]);
			}
		}

		return result;
	}

	void FindMinimumInRotatedSortedArrayII()
	{
		//print(findMin2(createVector({ 1, 1 })));
		
		//print(findMin2(createVector({ 10, 1, 10, 10, 10 })));
		//print(findMin2(createVector({ 1 })));
		print(findMin2(createVector({ 3, 0, 1, 1, 3 })));
	}
};