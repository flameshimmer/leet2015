#include "stdafx.h"

//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.

namespace Solution1
{
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
	{
		if (!l1 || !l2){ return l1 ? l1 : l2; }

		ListNode* head = NULL;
		ListNode* tail = NULL;
		while (l1 && l2)
		{
			ListNode* picked = (l1->val < l2->val) ? l1 : l2;
			if (!head) { head = picked;}
			else{ tail->next = picked; }
			tail = picked;
			(picked == l1) ? (l1 = l1->next) : (l2 = l2->next);
		}
		ListNode* remain = l1 ? l1 : l2;
		tail->next = remain;
		return head;
	}

	void MergeTwoSortedLists()
	{
	}
}