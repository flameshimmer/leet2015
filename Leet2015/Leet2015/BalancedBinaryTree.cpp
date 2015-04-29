#include "stdafx.h"

//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as a 
//binary tree in which the depth of the two subtrees of every node 
//never differ by more than 1.

namespace Solution1
{
	int getBalanced(TreeNode* node)
	{
		if (!node) { return 0; }
		
		int lh = getBalanced(node->left);
		if (lh == -1) { return -1; }
		int rh = getBalanced(node->right);
		if (rh == -1) { return -1; }
		
		if (lh - rh >1 || rh - lh >1)
		{
			return -1;
		}
		return lh > rh ? lh + 1 : rh + 1;		
	}
	bool isBalanced(TreeNode *root)
	{
		return (getBalanced(root) != -1);
	}

	namespace other{
		int getHeight(TreeNode* root)
		{
			if (!root) { return 0; }

			int leftHeight = getHeight(root->left);
			int rightHeight = getHeight(root->right);
			return max(leftHeight, rightHeight) + 1;
		}

		bool isBalanced(TreeNode *root)
		{
			if (!root) { return true; }

			int leftHeight = getHeight(root->left);
			int rightHeight = getHeight(root->right);
			if (abs(leftHeight - rightHeight) > 1) { return false; }
			return isBalanced(root->left) && isBalanced(root->right);
		}
	}


	void BalancedBinaryTree()
	{
		// Error: note that whehter a tree is balanced is not the diff of the entire 
		//        tree's leaf node height more than 1, it is the height of every sub 
		//        tree that is more than 1.
		// Error: use the diff > 1, instead of diff < 2, because diff < 2 will also 
		//        need to take care of the diff goes into the negative space
		// Trick: use int to return both height and indicate the boolean. (when return value is -1)
		TreeNode* root = new TreeNode(1);
		TreeNode* n1 = new TreeNode(2);
		TreeNode* n2 = new TreeNode(3);
		root->right = n1;
		n1->right = n2;
		print(isBalanced(root));
	}
}