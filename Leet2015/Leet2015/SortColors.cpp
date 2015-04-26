#include "stdafx.h"

//Given an array with n objects colored red, white or blue, 
//sort them so that objects of the same color are adjacent, 
//with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent 
//the color red, white, and blue respectively.
//
//Note:
//You are not suppose to use the library's sort function for this problem.

namespace Solution1
{
	void swapColors(int A[], int a, int b)
	{
		int temp = A[a];
		A[a] = A[b];
		A[b] = temp;
	}
	int partition(int A[], int n, int start, int color)
	{
		if (start == n - 1) { return n - 1; }
		int pivot = start;
		for (pivot; pivot < n; pivot++)
		{
			if (A[pivot] == color) { break; }
		}
		if (pivot == n) { return start-1; }

		swapColors(A, pivot, n - 1);
		int back = start;
		int front = start;
		while (front < n-1)
		{
			if (A[front] <= A[n - 1])
			{
				swapColors(A, back, front);
				back++;
			}
			front++;
		}
		swapColors(A, back, n - 1);
		return back;
	}
	void sortColors(int A[], int n)
	{
		int pivot0 = partition(A, n, 0, 0);
		partition(A, n, pivot0 + 1, 1);
	}
	void SortColors()
	{
		// Error: note that both front and back should start with start position
		// Error: when did not find a specific color, partition function should return start -1
		int A[] = { 0, 1, 0 };
		sortColors(A, 3);
	}
}