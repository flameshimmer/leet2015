#include "stdafx.h"


//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.



namespace Solution1
{
	int search(int A[], int n, int target) {
		if (n == 0) { return -1; }
		if (n == 1)
		{
			return (A[0] == target ? 0 : -1);
		}

		int start = 0;
		int end = n - 1;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (A[mid] == target)
			{
				return mid;
			}
			else if ((A[start] < A[mid] && target > A[start] && target < A[mid]) || (A[mid] < A[end] && (target < A[mid] || target > A[end])))
			{
				end = mid - 1;			
			}
			else if ((A[mid] < A[end] && target > A[mid] && target < A[end]) || (A[start] < A[mid] && (target > A[mid] || target < A[start])))
			{
				start = mid + 1;
			}
			else
			{
				if (A[start] == target) { return start; }
				if (A[end] == target) { return end; }
				return -1;
			}
		}
		return -1;
	}

	void SearchInRotatedSortedArray()
	{
		int input[7] = { 4, 5, 6, 7, 0, 1, 2 };
		int len = 7;
		int target = 8;
		//print(search(input, len, target));


		int input2[7] = { 1, 3, 5};
		len = 3;
		target = 1;
		//print(search(input2, len, target));

		int input3[7] = { 3, 5, 1 };
		len = 3;
		target = 1;
		//print(search(input3, len, target));

		int input4[7] = { 5, 1, 3 };
		len = 3;
		target = 3;
		//print(search(input4, len, target));

		int input5[7] = { 4, 5, 6, 7, 0, 1, 2 };
		len = 7;
		target = 0;
		print(search(input5, len, target));
	}
};