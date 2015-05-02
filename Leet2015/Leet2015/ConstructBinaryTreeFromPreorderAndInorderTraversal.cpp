#include "stdafx.h"

//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

namespace Solution1
{
	TreeNode* buildTree(vector<int>& preorder, int& index, vector<int>& inorder, int start, int end, int len)
	{
		if (index == len || start > end) { return NULL; }

		int target = preorder[index];
		index++;

		int targetIndex = start;
		while (targetIndex <= end)
		{
			if (inorder[targetIndex] == target)
			{
				break;
			}
			targetIndex++;
		}

		TreeNode* root = new TreeNode(target);
		root->left = buildTree(preorder, index, inorder, start, targetIndex - 1, len);
		root->right = buildTree(preorder, index, inorder, targetIndex + 1, end, len);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		int index = 0;
		int len = inorder.size();
		return buildTree(preorder, index, inorder, 0, len - 1, len);
	}

	void ConstructBinaryTreeFromPreorderAndInorderTraversal()
	{
	}
}