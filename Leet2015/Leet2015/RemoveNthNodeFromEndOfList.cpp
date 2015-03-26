#include "stdafx.h"

//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note :
//	 Given n will always be valid.
//	 Try to do this in one pass.

namespace Solution1
{
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (n == 0) { return head; }

		ListNode* fast = NULL;
		ListNode* slow = NULL;

		for (int i = 0; i < n; i++)
		{
			if (!fast)
			{
				fast = head;
			}
			else
			{
				fast = fast->next;
			}			
		}
		while (fast->next)
		{
			fast = fast->next;
			if (!slow)
			{
				slow = head;
			}
			else
			{
				slow = slow->next;
			}
		}
		
		if (!slow) { return head->next; }
		if (slow->next)
		{
			slow->next = slow->next->next;
		}
		else
		{
			slow->next = NULL;
		}		
		return head;
	}

	void RemoveNthNodeFromEndOfList()
	{
		print(removeNthFromEnd(createList({1, 2,3,4,5}), 2));
		print(removeNthFromEnd(createList({ 1 }), 1));
		print(removeNthFromEnd(createList({ 1, 2 }), 2));

	}
};