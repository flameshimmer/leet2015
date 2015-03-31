#include "stdafx.h"

//Given a sorted array, remove the duplicates in place such 
//that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array A = [1, 1, 2],
//
//Your function should return length = 2, and A is now[1, 2].

namespace Solution1
{
	int removeDuplicates(int A[], int n) 
	{
		if (n < 2) { return n; } 
		int slow = 1;
		int fast = 1;

		while (fast < n)
		{
			if (A[fast] != A[fast - 1])
			{
				A[slow] = A[fast];
				slow++;
			}
			fast++;
		}
		return slow;
	}

	void RemoveDuplicatesFromSortedArray()
	{
		// Error: note slow is already at the position that is ready to copy. So it's index is already at filled index + 1. 
		//        This means slow's value at the end of the calculation is already the length
		int A[3] = { 1, 1, 2 };
		print(removeDuplicates(A, 3));
	}
}