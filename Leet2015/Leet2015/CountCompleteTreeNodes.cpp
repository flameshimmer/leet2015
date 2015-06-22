#include "stdafx.h"

//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia :
//In a complete binary tree every level, except possibly the last, is completely filled, 
//and all nodes in the last level are as far left as possible.It can have between 1 and 2h nodes inclusive at the last level h.

namespace Solution1
{
	void countNodes(TreeNode* node, int curHeight, int& maxHeight, int& maxHeightCount, int& extra)
	{
		if (!node->left && !node->right)
		{
			if (maxHeight < 0)
			{
				maxHeight = curHeight;
			}
		}
		if (curHeight == maxHeight)
		{
			if (!node->left && !node->right)
			{
				maxHeightCount++;
			}
			else
			{
				if (node->left) { extra++; }
				if (node->right) { extra++; }
				return;
			}
		}
		else if (curHeight < maxHeight)
		{
			countNodes(node->right, curHeight+1, maxHeight, maxHeightCount, extra);
			countNodes(node->left, curHeight + 1, maxHeight, maxHeightCount, extra);
		}
	}

	int countNodes(TreeNode* root) {
		if (!root) { return 0; }

		int count = 1;
		int maxHeight = 1;
		int maxHeightCount = 1;
		int extra = 0;
		countNodes(root->right, 1, maxHeight, maxHeightCount, extra);
		countNodes(root->left, 1, maxHeight, maxHeightCount, extra);
		return count;
	}

	void CountCompleteTreeNodes()
	{
	}
}