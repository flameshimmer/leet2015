#include "stdafx.h"

//Find the kth largest element in an unsorted array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//For example,
//Given[3, 2, 1, 5, 6, 4] and k = 2, return 5.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ array's length.

namespace Solution1
{
	void swapForFindKthLargest(vector<int>& nums, int a, int b)
	{
		int temp = nums[a];
		nums[a] = nums[b];
		nums[b] = temp;
	}

	int partition(vector<int>& nums, int start, int end, int pivot)
	{
		if (start >= end) { return nums[start]; }
		int pivotVal = nums[start+pivot];
		swapForFindKthLargest(nums, start+pivot, end);

		int slow = start;
		int fast = start;

		while (fast <= end)
		{
			if (nums[fast] < pivotVal)
			{
				swapForFindKthLargest(nums, slow, fast);
				slow++;
			}
			fast++;
		}
		swapForFindKthLargest(nums, slow, end);

		if (pivot > slow - start)
		{
			pivot -= slow - start + 1;
			return partition(nums, slow + 1, end, pivot);
		}
		else if(pivot < slow - start)
		{
			return partition(nums, start, slow - 1, pivot);
		}
		else
		{
			return nums[slow];
		}
	}

	int findKthLargest(vector<int>& nums, int k) 
	{
		int len = nums.size();		
		return partition(nums, 0, len-1, len-k);
	}

	void KthLargestElementInAnArray()
	{
		// Error: notice that pivot value is the one that is relative to the start, not the absolute value
		vector<int> input = {3, 1, 2, 4  };
		print(findKthLargest(input, 2));

		input = { 99, 99 };
		print(findKthLargest(input, 1));

		input = { 2, 1 };
		print(findKthLargest(input, 2));

		input = { 3, 3, 3, 3, 4, 3, 3, 3, 3 };
		print(findKthLargest(input, 1));
	}
}