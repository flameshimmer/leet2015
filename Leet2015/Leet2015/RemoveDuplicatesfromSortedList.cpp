#include "stdafx.h"

//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

namespace Solution1
{
	ListNode *deleteDuplicates(ListNode *head) 
	{
		if (!head || !head->next){ return head; }
		ListNode* fast = head->next;
		ListNode* slow = head;
		int lastValue = head->val;
		while (fast)
		{
			if (fast->val != lastValue)
			{
				slow->next = fast;
				slow = fast;
			}
			lastValue = fast->val;
			fast = fast->next;
		}
		slow->next = NULL;
		return head;
	}

	void RemoveDuplicatesfromSortedList()
	{
		// Error: forgot to set slow's next to NULL before returning. Need to remember for linked list we need to specifically
		//        Null terminated the list ending.
		print(deleteDuplicates(createList({1, 1, 2, 3, 3})));
	}
}