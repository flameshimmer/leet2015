#include "stdafx.h"

//Given a binary tree, flatten it to a linked list in - place.
//
//For example,
//Given
//
//			1
//		   / \
//		  2   5
//		 / \   \
//		3   4   6
//The flattened tree should look like :
//			1
//			 \
//			  2
//			   \
//				3
//				 \
//				  4
//				   \
//					5
//					 \
//					  6
namespace Solution1
{
	TreeNode* getFlat(TreeNode* root)
	{
		if (!root->left && !root->right)
		{
			return root;
		}
		
		TreeNode* L = root->left;
		TreeNode* R = root->right;
		TreeNode* tail = root;
		root->left = NULL;
		if (L)
		{
			tail->right = L;
			tail = getFlat(L);			
		}
		if (R)
		{
			tail->right = R;
			tail = getFlat(R);
		}
		return tail;
	}
	void flatten(TreeNode *root) 
	{
		if (!root) { return; }
		getFlat(root);
	}

	void FlattenBinaryTreeToLinkedList()
	{
		TreeNode* root = new TreeNode(1);
		TreeNode* r = new TreeNode(2);
		root->right = r;
		flatten(root);
	}
}