#include "stdafx.h"

//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example :
//Given binary tree{ 1, #, 2, 3 },
//		1
//  		 \
//		  2
//		 /
//		3
//return[1, 3, 2].
//
//Note: Recursive solution is trivial, could you do it iteratively ?
//
namespace Solution1
{

	vector<int> inorderTraversal(TreeNode* root) 
	{
		vector<int>result;
		if (!root) { return result; }

		stack<TreeNode*> s;
		TreeNode* cur = root;
		while (!s.empty() || cur != NULL)
		{
			if (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			else
			{
				TreeNode* temp = s.top();
				s.pop();
				result.push_back(temp->val);
				cur = temp->right;
			}
		}
		return result;
	}

	void BinaryTreeInorderTraversal()
	{
		TreeNode* n1 = new TreeNode(1);
		print(inorderTraversal(n1));
	}
}