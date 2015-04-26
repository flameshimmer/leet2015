#include "stdafx.h"

//Given a binary tree and a sum, determine if the tree has a root 
//- to - leaf path such that adding up all the values along the path equals the given sum.
//
//For example :
//Given the below binary tree and sum = 22,
//	      5
//	     / \
//	    4   8
//	   /   / \
//   11   13  4
//   /\        \
//  7  2        1
//return true, as there exist a root - to - leaf path 5->4->11->2 which sum is 22.

namespace Solution1
{
	bool hasPathSum(TreeNode* root, int sum, int curSum)
	{
		curSum += root->val;
		if (!root->left && !root->right)
		{
			return curSum == sum;
		}
		return (root->left != NULL && hasPathSum(root->left, sum, curSum)) || (root->right != NULL && hasPathSum(root->right, sum, curSum));
	}

	bool hasPathSum(TreeNode *root, int sum) 
	{
		if (!root) { return false; }
		return hasPathSum(root, sum, 0);
	}

	void PathSum()
	{
		TreeNode* n1 = new TreeNode(1);
		n1->left = new TreeNode(2);

		print(hasPathSum(n1, 0));
	}
}