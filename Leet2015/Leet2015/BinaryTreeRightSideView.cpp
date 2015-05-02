#include "stdafx.h"

//Given a binary tree, imagine yourself standing on the right side of it, 
//return the values of the nodes you can see ordered from top to bottom.
//
//For example :
//Given the following binary tree,
//		1            <-- -
//	   / \
//	  2   3         <-- -
//	  \     \
//	   5     4       <-- -
//You should return[1, 3, 4].

namespace Solution1
{
	void printRightEdge(TreeNode* node, bool print, int curLevel, int& maxLevel, vector<int>& result)
	{
		if (!node) { return; }
		curLevel++;
		if (print || curLevel > maxLevel)
		{
			result.push_back(node->val);
		}
		maxLevel = max(maxLevel, curLevel);
		printRightEdge(node->right, print, curLevel, maxLevel, result);
		printRightEdge(node->left, print && (node->right ? false : true), curLevel, maxLevel, result);
	}
	
	
	vector<int> rightSideView(TreeNode* root) 
	{
		vector<int> result;
		int maxLevel = INT_MIN;
		printRightEdge(root, true, 0, maxLevel, result);
		return result;
	}

	namespace other
	{
		vector<int> rightSideView(TreeNode* root)
		{
			vector<int> result;
			if (!root) { return result; }

			queue<TreeNode*> q;
			q.push(root);
			int count = 1;
			int pushedCount = 0;
			int lastVal = root->val;
			while (!q.empty())
			{
				TreeNode* cur = q.front();
				lastVal = cur->val;
				q.pop();
				if (cur->left) { q.push(cur->left); pushedCount++; }
				if (cur->right) { q.push(cur->right); pushedCount++; }
				count--;
				if (count == 0)
				{
					count = pushedCount;
					pushedCount = 0;
					result.push_back(lastVal);
				}
			}
			return result;
		}
	}

	void BinaryTreeRightSideView()
	{
		// Note: the other way to do it is to get a level order print, and collect the right most element of each level
		int index = 0;
		TreeNode* n1 = new TreeNode(1);
		TreeNode* n2 = new TreeNode(2);
		TreeNode* n3 = new TreeNode(3);
		TreeNode* n4 = new TreeNode(4);
		TreeNode* n5 = new TreeNode(5);
		TreeNode* n6 = new TreeNode(6);
		n1->left = n2;
		n1->right = n3;
		n2->left = n4;
		print(rightSideView(n1));
	}
}