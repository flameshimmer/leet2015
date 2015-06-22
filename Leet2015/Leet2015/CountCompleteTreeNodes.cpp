#include "stdafx.h"

//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia :
//In a complete binary tree every level, except possibly the last, is completely filled, 
//and all nodes in the last level are as far left as possible.It can have between 1 and 2h nodes inclusive at the last level h.
/*
		    1
		 /     \
	    2       3
	  /   \    / \
	 4     5  6   7
	/ \   / 
   8   9 10  

*/
namespace Solution1
{	
	int countNodes(TreeNode* root) {
		if (!root) { return 0; }
		int h = 1;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		while (left && right)
		{
			h++;
			left = left->left;
			right = right->right;
		}
		 
		if (left == right) 
		{ 
			return (1 << h) -1; 
		}

		return countNodes(root->left) + countNodes(root->right) + 1;
	}

	void CountCompleteTreeNodes()
	{
	}
}