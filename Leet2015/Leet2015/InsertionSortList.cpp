#include "stdafx.h"

//Sort a linked list using insertion sort.

namespace Solution1
{
	ListNode *insertionSortList(ListNode *head) 
	{
		if (!head || !head->next){ return head; }

		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* cur = dummy;
		
		while (cur->next)
		{
			ListNode* scan = dummy;
			while (scan->next != cur->next)
			{
				if (scan->next->val > cur->next->val)
				{
					ListNode* temp = cur->next;
					cur->next = cur->next->next;
					temp->next = scan->next;
					scan->next = temp;
					break;
				}
				scan = scan->next;
			}
			if (scan->next == cur->next)
			{
				cur = cur->next;
			}
		}
		ListNode* result = dummy->next;
		delete dummy;
		return result;
	}

	void InsertionSortList()
	{
		print(insertionSortList(createList({ 3, 2, 1 })));
		print(insertionSortList(createList({ 6, 5, 3, 1, 8, 7, 2, 4 })));
	}
}