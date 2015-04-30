#include "stdafx.h"

//Given a binary tree, return the zigzag level order traversal of its nodes'
//values. (ie, from left to right, then right to left for the next level and alternate between).
//
//For example :
//Given binary tree{ 3, 9, 20, #, #, 15, 7 },
//			 3
//			/ \
//		   9  20
//		  / \
//		15   7
//return its zigzag level order traversal as :
//[
//	[3],
//	[20, 9],
//	[15, 7]
//]

namespace Solution1
{
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
	{
		vector<vector<int>> results;
		if (!root) { return results; }

		queue<TreeNode*> q;
		q.push(root);
		int count = 1;
		int pushedCount = 0;
		vector<int> result;
		bool flip = false;
		while (!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();
			result.push_back(cur->val);
			if (cur->left) { q.push(cur->left); pushedCount++; }
			if (cur->right) { q.push(cur->right); pushedCount++; }
			count--;
			if (count == 0)
			{
				if (flip)
				{
					int start = 0;
					int end = result.size() - 1;
					while (start < end)
					{
						int temp = result[start];
						result[start] = result[end];
						result[end] = temp;
						start++;
						end--;
					}
				}
				results.push_back(result);
				result.clear();
				count = pushedCount;
				pushedCount = 0;
				flip = !flip;
			}
		}
		return results;
	}

	void BinaryTreeZigzagLevelOrderTraversal()
	{
	}
}