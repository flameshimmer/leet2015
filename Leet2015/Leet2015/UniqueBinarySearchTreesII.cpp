#include "stdafx.h"

//Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//For example,
//Given n = 3, your program should return all 5 unique BST's shown below.
//
//	1         3     3      2      1
//	 \       /     /      / \      \
//	  3     2     1      1   3      2
//	 /     /       \                 \
//	2     1         2                 3

namespace Solution1
{
	vector<TreeNode*> getTree(int start, int end)
	{
		vector<TreeNode*> results;
		if (end < start) 
		{
			results.push_back(NULL);
			return results;
		}
		else
		{
			for (int i = start; i <= end; i++)
			{				
				vector<TreeNode*> leftSubs = getTree(start, i - 1);
				vector<TreeNode*> rightSubs = getTree(i+1, end);
				for (int j = 0; j < leftSubs.size(); j++)
				{					
					for (int k = 0; k < rightSubs.size(); k++)
					{
						TreeNode* root = new TreeNode(i);
						root->left = leftSubs[j];
						root->right = rightSubs[k];
						results.push_back(root);
					}
				}
			}
		}
		return results;
	}

	vector<TreeNode*> generateTrees(int n) 
	{
		return getTree(1, n);
	}

	void UniqueBinarySearchTreesII()
	{
		// Error: we need to create a root node per tree. 
		//		  instead of just creating one root node and changing its left and right subtree. 
		//        Otherwise the previously stored answer will be changed underneath when processing the new results
		vector<TreeNode*> result = generateTrees(3);
		print(result.size());
	}
}