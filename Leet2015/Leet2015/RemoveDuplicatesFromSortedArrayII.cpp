#include "stdafx.h"

//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice ?
//
//For example,
//Given sorted array A = [1, 1, 1, 2, 2, 3],
//
//Your function should return length = 5, and A is now[1, 1, 2, 2, 3]

namespace Solution1
{
	int removeDuplicatesII(int A[], int n)
	{
		if (n < 3) { return n; }
		int slow = 1;
		int fast = 1;
		int count = 1;

		while (fast < n)
		{
			if (A[fast] != A[fast - 1] || count < 2)
			{				
				if (A[fast] != A[fast - 1])
				{
					count = 1;
				}
				else
				{
					count++;
				}
				A[slow] = A[fast];
				slow++;
			}
			fast++;
		}
		return slow;
	}

	void RemoveDuplicatesFromSortedArrayII()
	{
		int B[6] = { 1, 1, 1, 2, 2, 3 };
		print(removeDuplicatesII(B, 6));

		int A[3] = { 1, 2, 2};
		print(removeDuplicatesII(A, 3));
	}
}