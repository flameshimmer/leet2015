#include "stdafx.h"

//Given a sorted array of integers, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].
//
//For example,
//Given[5, 7, 7, 8, 8, 10] and target value 8,
//return[3, 4].


namespace Solution1
{
	void search(int A[], int start, int end, int target, int& resultStart, int& resultEnd)
	{
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (A[mid] == target)
			{
				resultStart = (resultStart == -1) ? mid : min(mid, resultStart);
				resultEnd = (resultEnd == -1) ? mid : max(mid, resultEnd);
				if (A[start] == target) 
				{ 
					resultStart = (resultStart == -1) ? start : min(start, resultStart); 
				}
				else
				{
					search(A, start, mid - 1, target, resultStart, resultEnd);
				}
				
				if (A[end] == target)
				{ 
					resultEnd = (resultEnd == -1) ? end : max(end, resultEnd); 
				}
				else
				{
					search(A, mid + 1, end, target, resultStart, resultEnd);
				}				
				return;
			}
			else if (A[mid] > target)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
	}

	vector<int> searchRange(int A[], int n, int target) 
	{
		int resultStart = -1;
		int resultEnd = -1;

		search(A, 0, n - 1, target, resultStart, resultEnd);

		vector<int> result;
		result.push_back(resultStart);
		result.push_back(resultEnd);
		return result;
	}

	void SearchForARange()
	{
		int A[6] = { 5, 7, 7, 8, 8, 10 };
		print(searchRange(A, 6, 8));
	}
}