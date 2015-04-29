#include "stdafx.h"

//Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.
//
//For example :
//Given the below binary tree and sum = 22,
//			5
//		   / \
//		  4   8
//		 /   / \
//		11  13  4
//	   / \     / \
//	  7   2   5   1
//return
//[
//	[5, 4, 11, 2],
//	[5, 8, 4, 5]
//]
namespace Solution1
{
	void findPath(TreeNode* root, int curSum, int sum, vector<int>& result, vector<vector<int>>& results)
	{
		curSum += root->val;
		result.push_back(root->val);
		if (!root->left && !root->right && curSum == sum)
		{
			results.push_back(result);
			return;
		}
		
		int size = result.size();
		if (root->left)
		{
			findPath(root->left, curSum, sum, result, results);
		}
		if (root->right)
		{
			result.resize(size);
			findPath(root->right, curSum, sum, result, results);
		}
	}
	
	vector<vector<int> > pathSum(TreeNode *root, int sum) 
	{
		vector<vector<int>> results;
		vector<int>result;

		if (!root) { return results; }
		findPath(root, 0, sum, result, results);
		return results;
	}

	void PathSumII()
	{
		TreeNode* root = new TreeNode(1);
		TreeNode* l = new TreeNode(2);
		TreeNode* r = new TreeNode(3);
		root->left = l;
		root->right = r;
		print(pathSum(root, 3));
	}
}