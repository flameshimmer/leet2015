#include "stdafx.h"

//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

namespace Solution1
{
	namespace i2p{
		TreeNode* buildTree(vector<int>& postorder, int& index, vector<int>& inorder, int start, int end, int len)
		{
			if (start > end || index == len) { return NULL; }

			int target = postorder[index];
			index--;

			int targetIndex = start;
			while (targetIndex <= end)
			{
				if (inorder[targetIndex] == target) { break; }
				targetIndex++;
			}

			TreeNode* root = new TreeNode(target);
			root->right = buildTree(postorder, index, inorder, targetIndex + 1, end, len);
			root->left = buildTree(postorder, index, inorder, start, targetIndex - 1, len);
			return root;
		}

		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
		{
			int len = inorder.size();
			int index = len - 1;
			return buildTree(postorder, index, inorder, 0, len - 1, len);
		}
	}
	void ConstructBinaryTreeFromInorderAndPostorderTraversal()
	{
	}
}