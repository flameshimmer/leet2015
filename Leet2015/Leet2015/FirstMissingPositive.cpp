#include "stdafx.h"

//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given[1, 2, 0] return 3,
//and[3, 4, -1, 1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.

namespace Solution1
{
	int firstMissingPositive(int A[], int n) 
	{		
		for (int i = 0; i < n; i++)
		{			
			int target = A[i];
			while (target <= n && target > 0 && A[target-1] != target)
			{
				int temp = A[target-1];
				A[target-1] = target;
				target = temp;
			} 			
		}
		
		for (int i = 0; i < n; i++)
		{
			if (A[i] != i+1)
			{
				return i+1;
			}
		}
		return n+1;
	}

	void FirstMissingPositive()
	{

		// Error: Attempted to use A[i] to store i. Which in reality to fit in every positive number need to use A[i-1] to store i. 
		//        This will ensure all positive numbers in the array can be fit into the A[i]
		int A1[3] = {1 ,2 ,0};
		print(firstMissingPositive(A1, 3));

		int A2[4] = { 3, 4, -1, 1 };
		print(firstMissingPositive(A2, 4));

		int A3[2] = { 2, 1 };
		print(firstMissingPositive(A3, 2));

		print(firstMissingPositive(NULL, 0));
	}
}