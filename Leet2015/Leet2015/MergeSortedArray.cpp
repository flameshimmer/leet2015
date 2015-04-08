#include "stdafx.h"

//Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
//Note:
//You may assume that A has enough space(size that is greater or equal to m + n) to hold 
//additional elements from B.The number of elements initialized in A and B are m and n respectively.


namespace Solution1
{
	void merge(int A[], int m, int B[], int n) 
	{
		if (!B || !A || n<=0) { return; }

		int len = m + n;
		m--;
		n--;
		for (int i = len - 1; i >= 0; i--)
		{
			int valA = INT_MIN;
			int valB = INT_MIN;
			if (m >= 0) 
			{
				valA = A[m];
			}
			if (n >= 0)
			{
				valB = B[n];
			}
			A[i] = valA > valB ? valA : valB;
			if (valA > valB) { m--; }
			else{ n--; }
		}
	}

	void MergeSortedArray()
	{
		int B[1] = { 1 };
		int A[1] = { 0 };
		merge(A, 0, B, 1);
	}
}