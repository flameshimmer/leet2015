#include "stdafx.h"

//Given an array and a value, remove all instances of that value in place and return the new length.
//
//The order of elements can be changed.It doesn't matter what you leave beyond the new length.

namespace Solution1
{
	int removeElement(int A[], int n, int elem) 
	{
		if (n == 0) { return 0; }

		int fast = 0;
		int slow = 0;
		while (fast < n)
		{
			if (A[fast] != elem)
			{
				A[slow] = A[fast];
				slow++;
			}
			fast++;
		}
		return slow;
	}

	void RemoveElement()
	{
	}
}