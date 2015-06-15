#include "stdafx.h"

//Invert a binary tree.
//
//					     4
//					   /   \
//					  2     7
//					 / \   / \
//					1   3 6   9
//to
//		  				4
//					  /   \
//					 7     2
//					/ \   / \
//				   9   6 3   1

namespace Solution1
{
	TreeNode* invertTree(TreeNode* root)
	{
		if (!root) { return root; }
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty())
		{
			TreeNode* cur = s.top();
			s.pop();
			if (cur->right){ s.push(cur->right); }
			if (cur->left){ s.push(cur->left); }
			TreeNode* temp = cur->left;
			cur->left = cur->right;
			cur->right = temp;
		}
		return root;
	}

	namespace Recusion{
		TreeNode* invertTree(TreeNode* root)
		{
			if (!root){ return NULL; }

			TreeNode* L = invertTree(root->left);
			TreeNode* R = invertTree(root->right);

			root->right = L;
			root->left = R;
			return root;
		}
	}
	void InvertBinaryTree()
	{
		invertTree(new TreeNode(1));
	}
}