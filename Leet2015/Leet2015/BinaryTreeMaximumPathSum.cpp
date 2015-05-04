#include "stdafx.h"

//Given a binary tree, find the maximum path sum.
//
//The path may start and end at any node in the tree.
//
//For example :
//Given the below binary tree,
//
//		 1
//		/ \
//	   2   3
//Return 6.

namespace Solution1
{
	int findMaxSum(TreeNode* root, int& maxAcrossRoot)
	{
		if (!root) { return 0; }
		int left = findMaxSum(root->left, maxAcrossRoot);
		int right = findMaxSum(root->right, maxAcrossRoot);
		
		int acrossRoot = root->val;
		if (left > 0)
		{
			acrossRoot += left;
		}
		if (right > 0)
		{
			acrossRoot += right;
		}
		maxAcrossRoot = max(maxAcrossRoot, acrossRoot);
		return max(root->val, max(root->val + left, root->val + right));
	}

	int maxPathSum(TreeNode* root) 
	{
		int maxAcrossRoot = INT_MIN;
		int maxEndByRoot = findMaxSum(root, maxAcrossRoot);
		return max(maxEndByRoot, maxAcrossRoot);
	}

	void BinaryTreeMaximumPathSum()
	{
		TreeNode* root1 = createTree(createVector({ 5, 4, 8, 11, NULL, 13, 4, 7, 2, NULL, NULL, NULL, 1 }), NULL);
		print(maxPathSum(root1));
	}
}