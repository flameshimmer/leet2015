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

	int findKthLargest(vector<int>& nums, int k) 
	{
		int len = nums.size();
		int pivot = len - k ;

		while (true)
		{
			int pivotVal = nums[pivot];
			swapForFindKthLargest(nums, pivot, len - 1);

			int slow = 0;
			int fast = 0;
			while (fast < len)
			{
				if (nums[fast] <= pivotVal)
				{
					swapForFindKthLargest(nums, slow, fast);
					slow++;
				}
				fast++;
			}
			swapForFindKthLargest(nums, slow-1, len - 1);
			if (slow-1 == pivot) { break; }
		}
		return nums[pivot];
	}

	void KthLargestElementInAnArray()
	{
		vector<int> input = { 99, 99 };
		print(findKthLargest(input, 1));
	}
}