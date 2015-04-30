#include "stdafx.h"

//Given a binary tree containing digits from 0 - 9 only, 
//each root - to - leaf path could represent a number.
//
//An example is the root - to - leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root - to - leaf numbers.
//
//For example,
//
//	  1
//   / \
//  2   3
//The root - to - leaf path 1->2 represents the number 12.
//The root - to - leaf path 1->3 represents the number 13.
//
//Return the sum = 12 + 13 = 25.

namespace Solution1
{
	void doSumNumbers(TreeNode* root, int curSum, int& sum)
	{
		curSum = curSum * 10 + root->val;
		if (!root->left && !root->right)
		{
			sum += curSum;
		}
		if (root->left)
		{
			doSumNumbers(root->left, curSum, sum);
		}
		if (root->right)
		{
			doSumNumbers(root->right, curSum, sum);
		}
	}

	int sumNumbers(TreeNode *root) 
	{
		if (!root) { return 0; }
		int result = 0;
		doSumNumbers(root, 0, result);
		return result;
	}

	void SumRootToLeafNumbers()
	{
	}
}