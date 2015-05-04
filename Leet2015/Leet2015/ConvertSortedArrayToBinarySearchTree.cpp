#include "stdafx.h"

//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

namespace Solution1
{
	TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end)
	{
		if (end < start) { return NULL; }
		int mid = start + (end - start) / 2;

		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBSTHelper(nums, start, mid-1);
		root->right = sortedArrayToBSTHelper(nums, mid+1, end);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) 
	{
		return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
	}

	void ConvertSortedArrayToBinarySearchTree()
	{
	}
}