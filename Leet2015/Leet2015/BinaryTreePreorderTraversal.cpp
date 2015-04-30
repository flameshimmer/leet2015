#include "stdafx.h"

namespace Solution1
{
	vector<int> preorderTraversal(TreeNode *root) 
	{
		vector<int> result;
		if (!root) { return result; }

		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty())
		{
			TreeNode* cur = s.top();
			s.pop();
			result.push_back(cur->val);
			if (cur->right)
			{
				s.push(cur->right);
			}
			if (cur->left)
			{
				s.push(cur->left);
			}
		}
		return result;
	}

	void BinaryTreePreorderTraversal()
	{

	}
}