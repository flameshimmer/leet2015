#include "stdafx.h"

//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest 
//path from the root node down to the farthest leaf node.

namespace Solution1
{
	void findMaxDepth(TreeNode* node, int depth, int& maxDepth)
	{
		if (!node)
		{
			maxDepth = max(depth, maxDepth);
			return;
		}
		findMaxDepth(node->left, depth + 1, maxDepth);
		findMaxDepth(node->right, depth + 1, maxDepth);		
	}

	int maxDepth(TreeNode *root) 
	{
		int maxDepth = 0;
		findMaxDepth(root, 0, maxDepth);
		return maxDepth;
	}

	void MaximumDepthOfBinaryTree()
	{
	}
}