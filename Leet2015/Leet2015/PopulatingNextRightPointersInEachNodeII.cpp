#include "stdafx.h"

//Given a binary tree
//
//struct TreeLinkNode {
//	TreeLinkNode *left;
//	TreeLinkNode *right;
//	TreeLinkNode *next;
//}
//Populate each next pointer to point to its next right node.
//If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//
//You may only use constant extra space.
//The input binary tree could be any binary tree
//For example,
//Given the following perfect binary tree,
//				1
//			   / \
//			  2   3
//			 / \   \
//			4  5    7
//After calling your function, the tree should look like :
//				1->NULL
//			   /  \
//			  2 -> 3->NULL
//			 / \    \
//			4-->5--->7->NULL

namespace Solution1
{
	namespace II
	{
		TreeLinkNode* getNext(TreeLinkNode* root, TreeLinkNode* target)
		{
			TreeLinkNode* cur = root;
			while (cur)
			{
				if (cur->left && cur->left != target) { return cur->left; }
				if (cur->right && cur->right != target) { return cur->right; }
				cur = cur->next;
			}
			return NULL;
		}
		void connect(TreeLinkNode *root) {
			if (!root) return;
			TreeLinkNode *backupRoot = root;
			while (root)
			{
				if (root->left)
				{
					root->left->next = getNext(root, root->left);
				}
				if (root->right)
				{
					root->right->next = getNext(root->next, root->right);
				}
				root = root->next;
			}
			connect(getNext(backupRoot, NULL));
		}
		namespace other
		{
			TreeLinkNode* getNext(TreeLinkNode* root, TreeLinkNode* target)
			{
				TreeLinkNode* cur = root;
				while (cur)
				{
					if (cur->left && cur->left != target) { return cur->left; }
					if (cur->right && cur->right != target) { return cur->right; }
					cur = cur->next;
				}
				return NULL;
			}
			void connect(TreeLinkNode *root) {
				TreeLinkNode* L = root;
				while (L)
				{
					TreeLinkNode* cur = L;
					while (cur)
					{
						if (cur->left)
						{
							cur->left->next = getNext(cur, cur->left);
						}
						if (cur->right)
						{
							cur->right->next = getNext(cur->next, cur->right);
						}
						cur = cur->next;
					}
					L = getNext(L, NULL);
				}
			}
		}
	}
	void PopulatingNextRightPointersInEachNodeII()
	{
		TreeLinkNode* n1 = new TreeLinkNode(2);
		TreeLinkNode* n2 = new TreeLinkNode(1);
		TreeLinkNode* n3 = new TreeLinkNode(3);
		TreeLinkNode* n4 = new TreeLinkNode(0);
		TreeLinkNode* n5 = new TreeLinkNode(7);
		TreeLinkNode* n6 = new TreeLinkNode(9);
		TreeLinkNode* n7 = new TreeLinkNode(1);
		TreeLinkNode* n8 = new TreeLinkNode(2);
		TreeLinkNode* n9 = new TreeLinkNode(1);
		TreeLinkNode* n10 = new TreeLinkNode(0);
		TreeLinkNode* n11 = new TreeLinkNode(8);
		TreeLinkNode* n12 = new TreeLinkNode(8);

		linkTreeNodes(n1, n2, n3);
		linkTreeNodes(n2, n4, n5);
		linkTreeNodes(n3, n6, n7);
		linkTreeNodes(n4, n8, NULL);
		linkTreeNodes(n5, n9, n10);
		linkTreeNodes(n7, n11, n12);
		II::connect(n1);

		TreeLinkNode* m1 = new TreeLinkNode(3);
		TreeLinkNode* m2 = new TreeLinkNode(9);
		TreeLinkNode* m3 = new TreeLinkNode(20);
		TreeLinkNode* m4 = new TreeLinkNode(15);
		TreeLinkNode* m5 = new TreeLinkNode(7);
		linkTreeNodes(m1, m2, m3);
		linkTreeNodes(m3, m4, m5);
		II::other::connect(m1);		
	}
}