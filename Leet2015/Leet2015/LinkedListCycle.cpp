#include "stdafx.h"

//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?

namespace Solution1
{
	bool hasCycle(ListNode *head) 
	{
		if (!head || !head->next)
		{
			return false;
		}

		ListNode* fast = head;
		ListNode* slow = head;

		while (fast && slow)
		{			
			if (fast->next == slow || (fast->next && fast->next->next == slow))
			{
				return true;
			}
			
			if (!fast->next) { return false; }
			fast = fast->next->next;
			slow = slow->next;
		}
		return false;
	}

	void LinkedListCycle()
	{
		ListNode* list = createList({3, 2, 0, -4});
		ListNode* last = getLastNode(list);
		ListNode* nodeAtIndexOne = getListNodeAt(list, 1);
		last->next = nodeAtIndexOne;
		print(hasCycle(list));
	}
};