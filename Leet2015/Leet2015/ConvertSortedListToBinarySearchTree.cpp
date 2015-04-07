#include "stdafx.h"

//Given a singly linked list where elements are sorted in ascending order, 
//convert it to a height balanced BST.

namespace Solution1
{
	TreeNode *sortedListToBST(ListNode *head) 
	{
		if (!head) { return NULL; }

		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* prev = NULL;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}
		
		TreeNode* newNode = new TreeNode(slow->val);
		if (prev)
		{
			prev->next = NULL;
			newNode->left = sortedListToBST(head);
		}
		newNode->right = sortedListToBST(slow->next);
		return newNode;
	}

	namespace bottomUP
	{
		TreeNode* buildBST(ListNode*& head, int start, int end)
		{
			if (!head || end < start) { return NULL; }

			int mid = start + (end - start) / 2;

			TreeNode* leftChild = buildBST(head, start, mid - 1);
			TreeNode* newNode = new TreeNode(head->val);
			newNode->left = leftChild;
			head = head->next;
			TreeNode* rightChild = buildBST(head, mid + 1, end);
			newNode->right = rightChild;
			return newNode;
		}

		TreeNode *sortedListToBST(ListNode *head)
		{
			if (!head) { return NULL; }
			int len = 0;
			ListNode* cur = head;
			while (cur)
			{
				len++;
				cur = cur->next;
			}

			return buildBST(head, 0, len - 1);
		}
	}

	void ConvertSortedListToBinarySearchTree()
	{
		//sortedListToBST(createList({ 0 }));
		using namespace bottomUP;
		bottomUP::sortedListToBST(createList({ 0 }));
	}
}