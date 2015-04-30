#include "stdafx.h"

//Given a binary tree where all the right nodes are either leaf nodes with a sibling
//(a left node that shares the same parent node) or empty, flip it upside down and 
//turn it into a tree where the original right nodes turned into left leaf nodes.
//
//Return the new root.
//
//For example :
//Given a binary tree{ 1, 2, 3, 4, 5 },
//				1
//	  		   / \
//			  2   3
//			 / \
//			4   5
//return the root of the binary tree[4, 5, 2, #, #, 3, 1].
//				4
//			   / \
//			  5   2
//			     / \
//			    3   1

namespace Solution1
{
	TreeNode *upsideDownBinaryTree(TreeNode *root) 
	{
		if (!root || (!root->left && !root->right)) { return root; }

		TreeNode* L = root->left;
		TreeNode* R = root->right;
		root->left = NULL;
		root->right = NULL;

		TreeNode* newRoot = upsideDownBinaryTree(L);
		L->left = R;
		L->right = root;
		return newRoot;
	}

	void BinaryTreeUpsideDown()
	{
	}
}