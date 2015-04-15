#include "stdafx.h"

//Given a sorted array and a target value, return the index if the target is found.
//If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Here are few examples.
//[1, 3, 5, 6], 5 → 2
//[1, 3, 5, 6], 2 → 1
//[1, 3, 5, 6], 7 → 4
//[1, 3, 5, 6], 0 → 0

namespace Solution1
{	
	int searchInsert(int A[], int n, int target)
	{
		if (n == 0) { return 0; }

		int start = 0;
		int end = n - 1;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (A[mid] == target)
			{
				return mid;
			}
			else if (A[mid] < target)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		return max(start, end);
	}

	void SearchInsertionPosition()
	{
		int A[4] = { 1, 3, 5, 6 };
		print(searchInsert(A, 4, 5));
		print(searchInsert(A, 4, 2));
		print(searchInsert(A, 4, 7));
		print(searchInsert(A, 4, 0));
	}
}