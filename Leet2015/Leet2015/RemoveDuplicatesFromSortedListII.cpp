#include "stdafx.h"

//Given a sorted linked list, delete all nodes that have duplicate 
//numbers, leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3

namespace Solution1
{
	ListNode *deleteDuplicatesII(ListNode *head) 
	{
		if (!head || !head->next){ return head; }
		ListNode* newHead = NULL;
		ListNode* tail = NULL;
		ListNode* cur = head;
		ListNode* last = NULL;
		while (cur)
		{
			if ((!cur->next || cur->val != cur->next->val) && (!last || cur->val != last->val))
			{
				if (!newHead) { newHead = cur; }
				else{ tail->next = cur; }
				tail = cur;					
			}
			last = cur;
			cur = cur->next;
		}
		if (tail)
		{
			tail->next = NULL;
		}
		return newHead;
	}

	void RemoveDuplicatesFromSortedListII()
	{
		print(deleteDuplicatesII(createList({ 1, 2, 3, 3, 4, 4, 5 })));
		print(deleteDuplicatesII(createList({ 1, 1,1,2,3 })));

		// Error: since the list can be empty, when setting tail's next, need to check whether tail is NULL first
		// Error: since the cur can be the last element, need to ensure cur->next exists before calling cur->next->val
		print(deleteDuplicatesII(createList({ 1, 1})));
	}
}