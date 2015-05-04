#include "stdafx.h"

//Given a binary tree, return the postorder traversal of its nodes' values.
//
//For example :
//Given binary tree{ 1, #, 2, 3 },
//		1
//       \
//		  2
//		 /
//		3
//return [3,2,1].
//
//Note: Recursive solution is trivial, could you do it iteratively ?
//

namespace Solution1
{
	vector<int> postorderTraversal(TreeNode* root) 
	{
		vector<int> result;
		if (!root) { return result; }
		stack<TreeNode* > s;
		TreeNode* cur = root;
		TreeNode* lastVisitedNode = NULL;

		while (!s.empty() || cur != NULL)
		{
			if (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			else
			{
				TreeNode* top = s.top();
				if (top->right && top->right != lastVisitedNode)
				{
					cur = top->right;
				}
				else
				{
					s.pop();
					result.push_back(top->val);					
					lastVisitedNode = top;
				}
			}
		}
		return result;
	}

	void BinaryTreePostorderTraversal()
	{
	}
}