#include "stdafx.h"

//Given a binary tree, determine if it is a valid binary search tree(BST).
//
//Assume a BST is defined as follows :
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.

namespace Solution1
{
	bool isValid(TreeNode* root, long long& min, long long& max)
	{
		if (!root) { return true; }
		if (root->val <= min || root->val >= max) { return false; }
		
		long long val = root->val;
		return isValid(root->left, min, val) && isValid(root->right, val, max);
	}

	bool isValidBST(TreeNode* root)
	{
		if (!root || (!root->left && !root->right)) { return true; }
		long long min = (long long)INT_MIN - 1;
		long long max = (long long)INT_MAX + 1;
		return isValid(root, min, max);
	}
	void ValidateBinarySearchTree()
	{
		TreeNode* n1 = new TreeNode(0);
		TreeNode* n2 = new TreeNode(-1);
		n1->left = n2;
		print(isValidBST(n1));
	}
}