#include "stdafx.h"

//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array.

namespace Solution1
{
	bool isMin(vector<int> num, int i)
	{
		int len = num.size();
		if (len == 1) { return true; }
		int prev = (i == 0) ? num[len - 1] : num[i - 1];
		int next = (i == len-1) ? num[0] : num[i + 1];
		return (num[i] < prev && num[i] < next);
	}
	int findMin(vector<int> &num) 
	{
		int start = 0;
		int end = num.size() - 1;

		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (isMin(num, mid))
			{
				return num[mid];
			}
			else if (isMin(num, start))
			{
				return num[start];
			}
			else if (isMin(num, end))
			{
				return num[end];
			}
			else if (num[start] < num[mid])
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		return -1;
	}

	void FindMinimumInRotatedSortedArray()
	{		
		print(findMin(createVector({ 4, 5, 6, 7, 0, 1, 2 })));
		// Error: did not take care of the special case where there is only one number in the vector, in which case both the prev and the next 
		//        would be equal to the current number
		print(findMin(createVector({ 1 })));
	}
};