#include "stdafx.h"

//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed ?
//
//Would this affect the run - time complexity ? How and why ?
//
//Write a function to determine if a given target is in the array.


namespace Solution1
{
	bool search(int A[], int n, int target) 
	{
		if (n == 0){ return false; }
		if (n == 1) { return target == A[0]; }

		int start = 0;
		int end = n - 1;
		while (start <= end)
		{
			while (start < end && A[start] == A[end])
			{
				start++;
			}
			int mid = start + (end - start) / 2;
			if (A[mid] == target || A[start] == target || A[end] == target)
			{
				return true;
			}			
			else if ((A[start] < target && target < A[mid]) || (A[mid] <= A[end] && (target > A[end] || target < A[mid])))
			{
				end = mid - 1;
			}
			else if ((A[mid] < target && target < A[end]) || (A[start] <= A[mid] && (target > A[mid] || target < A[start])))
			{
				start = mid + 1;
			}
			else
			{
				return false;
			}
		}
		return false;
	}

	
	void SearchInRotatedSortedArrayII()
	{
		int input[15] = { 5,6,6,6, 7,7,8,1, 1,2,2,2, 2,3,4 };		
		int len = 15;		
		print(input, len); 
		int target = 8;
		print(search(input, len, target));

		// The trick is when the duplication is impacting the determination of which range is not impacted by the rotation.
		// To fix this is to advance start index to avoid this kind of situation.
		int input2[4] = {1, 1, 3, 1};
		int len = 4;
		print(input2, len);
		int target = 3;
		print(search(input2, len, target));
	}
}