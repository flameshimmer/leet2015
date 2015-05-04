#include "stdafx.h"

//Two elements of a binary search tree(BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Note:
//A solution using O(n) space is pretty straight forward.Could you devise a constant space solution ?

namespace Solution1
{
	void inOrder(TreeNode* node, TreeNode*& prev, TreeNode*& first, TreeNode*& second)
	{
		if (!node) { return; }
		inOrder(node->left, prev, first, second);
				
		if (prev && (prev->val > node->val))
		{
			if (!first) { first = prev; }
			second = node;
		}
		prev = node;

		inOrder(node->right, prev, first, second);
	}

	void recoverTree(TreeNode *root) {
		TreeNode* first = NULL;
		TreeNode* second = NULL;
		TreeNode* prev = NULL;
		inOrder(root, prev, first, second);
		if (first && second)
		{
			int temp = first->val;
			first->val = second->val;
			second->val = temp;
		}
	}

	namespace other
	{
		void recoverTree(TreeNode* root) {
			TreeNode* cur = root;
			TreeNode* pre = NULL;
			TreeNode* prev = NULL;
			TreeNode* first = NULL;
			TreeNode* second = NULL;

			while (cur)
			{
				if (!cur->left)
				{
					if (prev && !first && prev->val > cur->val)
					{
						first = prev;
					}
					if (prev && prev->val > cur->val)
					{
						second = cur;
					}
					prev = cur;

					cur = cur->right;
				}
				else
				{
					pre = cur->left;
					while (pre->right && pre->right != cur)
					{
						pre = pre->right;
					}

					if (pre->right == NULL)
					{
						pre->right = cur;
						cur = cur->left;
					}
					else
					{
						if (prev && !first && prev->val > cur->val)
						{
							first = prev;
						}
						if (prev && prev->val > cur->val)
						{
							second = cur;
						}
						prev = cur;

						pre->right = NULL;
						cur = cur->right;
					}
				}
			}
			if (first && second)
			{
				int temp = first->val;
				first->val = second->val;
				second->val = temp;
			}
		}
	}
	
	void RecoverBinarySearchTree()
	{
		TreeNode* root = createTree(createVector({3, 1, 2}), NULL);
		recoverTree(root);
	}
}