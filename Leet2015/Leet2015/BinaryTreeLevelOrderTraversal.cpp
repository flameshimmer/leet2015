#include "stdafx.h"

//Given a binary tree, return the level order traversal of its nodes'
//values. (ie, from left to right, level by level).
//
//For example :
//Given binary tree{ 3, 9, 20, #, #, 15, 7 },
//	  3
//   / \
//  9  20
// / \
//15   7
//
//return its level order traversal as :
//[
//	[3],
//	[9, 20],
//	[15, 7]
//]

namespace Solution1
{
	vector<vector<int> > levelOrder(TreeNode *root) 
	{
		vector<vector<int>> results;
		if (!root) { return results; }

		queue<TreeNode*> q;
		q.push(root);
		int count = 1;
		int pushedCount = 0;
		vector<int> result;

		while (!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();
			result.push_back(cur->val);
			if (cur->left)
			{
				q.push(cur->left);
				pushedCount++;
			}
			if (cur->right)
			{
				q.push(cur->right);
				pushedCount++;
			}

			count--;			
			if (count == 0)
			{
				results.push_back(result);
				result.clear();
				count = pushedCount;
				pushedCount = 0;
			}
		}
		return results;
	}

	void BinaryTreeLevelOrderTraversal()
	{
	}
}