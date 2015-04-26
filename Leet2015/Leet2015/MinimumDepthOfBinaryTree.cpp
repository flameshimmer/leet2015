#include "stdafx.h"

//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest 
//path from the root node down to the nearest leaf node.

namespace Solution1
{
	void findMinDepth(TreeNode* node, int curDepth, int& minDepth)
	{
		if (!node->left && !node->right)
		{
			minDepth = min(minDepth, curDepth);
			return;
		}
		if (node->left)
		{
			findMinDepth(node->left, curDepth + 1, minDepth);
		}
		if (node->right)
		{
			findMinDepth(node->right, curDepth + 1, minDepth);
		}
	}
	int minDepth(TreeNode *root) 
	{
		if (!root) { return 0; }
		int minDepth = INT_MAX;
		findMinDepth(root, 1, minDepth);
		return minDepth;
	}

	void MinimumDepthOfBinaryTree()
	{
	}
}