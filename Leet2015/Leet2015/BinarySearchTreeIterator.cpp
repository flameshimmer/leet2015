#include "stdafx.h"

//Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

namespace Solution1
{
	class BSTIterator {
	public:
		stack<TreeNode*> s;
		BSTIterator(TreeNode *root) {
			if (root != NULL)
			{
				TreeNode* cur = root;
				while (cur)
				{
					s.push(cur);
					cur = cur->left;
				}				
			}
		}

		/** @return whether we have a next smallest number */
		bool hasNext() {
			return !(s.empty());
		}

		/** @return the next smallest number */
		int next() {
			TreeNode* top = s.top();
			int result = top->val;
			s.pop();

			TreeNode* right = top->right;
			while (right)
			{
				s.push(right);
				right = right->left;
			}
			return result;
		}
	};

	void BinarySearchTreeIterator()
	{
	}
}