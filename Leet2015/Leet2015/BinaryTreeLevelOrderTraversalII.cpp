#include "stdafx.h"

//Given a binary tree, return the bottom - up level order traversal 
//of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example :
//Given binary tree{ 3, 9, 20, #, #, 15, 7 },
//		3
//	   / \
//	  9  20
//		 / \
//	    15   7
//return its bottom - up level order traversal as :
//[
//	[15, 7],
//	[9, 20],
//	[3]
//]
namespace Solution1
{
	vector<vector<int> > levelOrderBottom(TreeNode *root) 
	{
		vector<vector<int> > results;
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
		int start = 0;
		int end = results.size() - 1;
		while (start < end)
		{
			vector<int>tmp = results[start];
			results[start] = results[end];
			results[end] = tmp;
			start++;
			end--;
		}
		return results;
	}

	void BinaryTreeLevelOrderTraversalII()
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		print(levelOrderBottom(root));
	}
}