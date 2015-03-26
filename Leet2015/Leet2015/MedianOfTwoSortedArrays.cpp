#include "stdafx.h"

//There are two sorted arrays A and B of size m and n respectively.
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
 
namespace Solution1
{
	double findKth(int A[], int m, int B[], int n, int k)
	{
		if (m == 0){ return B[k]; }
		if (n == 0){ return A[k]; }
		if (k <= 1) { return min(A[0], B[0]); }

		if (A[m / 2] <= B[n / 2])
		{
			if (m / 2 + n / 2 >= k)
			{
				findKth(A, m, B, n / 2, k);
			}
			else
			{
				findKth(A + m / 2, m - m / 2, B, n, k - m / 2);
			}
		}
		else
		{
			if (m / 2 + n / 2 >= k)
			{
				findKth(A, m / 2, B, n, k);
			}
			else
			{
				findKth(A, m, B + n / 2, n - n / 2, k - n / 2);
			}
		}
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {		
		if ((m + n) % 2 == 0)
		{
			double first = findKth(A, m, B, n, (m + n) / 2);
			double second = findKth(A, m, B, n, (m + n) / 2 - 1);
			double result =  (first + second) / 2.0;
			return result;
		}
		else
		{
			return findKth(A, m, B, n, (m + n) / 2);
		}
	}
	
	/* O(n) solution, which is simple but too slow
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
	}*/

	void MedianOfTwoSortedArrays()
	{
		int* A= {0};
		int B[1] = { 1 };
		// Error: note that mid2 can't be -1. Be sure to ensure it is positive
		//cout << findMedianSortedArrays(A, 0, B, 1);

		int A1[1] = { 1 };
		int B1[1] = { 1 };
		//cout << findMedianSortedArrays(A1, 1, B1, 1);

		int A2[2] = { 1, 2 };
		int B2[3] = { 1, 2, 3 };
		//cout << findMedianSortedArrays(A2, 2, B2, 3);

		int A3[1] = { 1 };
		int B3[2] = { 2, 3 };
		//cout << findMedianSortedArrays(A3, 1, B3, 2);

		int A4[1] = { 3 };
		int B4[2] = { 1, 2 };
		//cout << findMedianSortedArrays(A4, 1, B4, 2);

		int A5[1] = { 1 };
		int B5[3] = { 2, 3, 4 };
		//cout << findMedianSortedArrays(A5, 1, B5, 3);

		int A6[2] = { 1, 2 };
		int B6[2] = { 1, 2 };
		cout << findMedianSortedArrays(A6, 2, B6, 2);
	}
}