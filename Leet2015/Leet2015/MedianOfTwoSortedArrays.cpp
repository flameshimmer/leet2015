#include "stdafx.h"

//There are two sorted arrays A and B of size m and n respectively.
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
 
namespace Solution1
{
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int mid1 = (m > n) ? (n + (m - n) / 2) : (m + (n - m) / 2);

		int mid2 = mid1 - 1;
		if ((m % 2 == 0 && n % 2 != 0) || (m % 2 != 0 && n % 2 == 0) || mid1 < 1)
		{
			mid2 = mid1;
		}
		
		int curM = 0;
		int curN = 0;
		int count = 0;
		int median = 0;
		while (curM < m && curN < n && count <= mid1)
		{
			int val;
			if (A[curM] < B[curN])
			{
				val = A[curM];
				curM++; 
			}
			else
			{ 
				val = B[curN];
				curN++; 
			}
			
			if (count == mid1)
			{
				median += val;
			}
			if (count == mid2)
			{
				median += val;
			}
			count++;
		}

		int* Remain = (curM < m) ? A : B;
		int index = (curM < m) ? curM : curN;

		while (count <= mid1)
		{
			if (count == mid1)
			{
				median += Remain[index];
			}
			if (count == mid2)
			{
				median += Remain[index];
			}
			count++;
			index++;
		}
		double result = double(median) / 2.0;
		return result;
	}

	void MedianOfTwoSortedArrays()
	{
		int* A= {0};
		//int B[1] = { 1 };
		// Error: note that mid2 can't be -1. Be sure to ensure it is positive
		int B[2] = { 2, 3 };
		cout << findMedianSortedArrays(A, 0, B, 2);
	}
}