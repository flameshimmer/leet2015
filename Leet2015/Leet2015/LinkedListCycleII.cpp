#include "stdafx.h"

//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//
//Follow up :
//Can you solve it without using extra space ?

namespace Solution1
{
	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next) { return NULL; }

		ListNode* slow = head;
		ListNode* fast = head;

		while (slow && fast)
		{
			slow = slow->next;
			if (!fast->next){ return NULL; }
			fast = fast->next->next;
			if (fast == slow)
			{
				break;
			}
		}
		if (!slow || !fast) { return NULL; }
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}

	void LinkedListCycleII()
	{
		// Error: need to put the fast and slow on the same node before starting the while loop. Otherwise the math is not going to be right.
		//        To avoid direct jumping out of the while loop before any node advancement, put the check whether fast and slow node are equal
		//        logic after the node advancement in the while loop.
		// Error: did not do null check when break out of the first while loop. Note that the first while loop can be broken out of either due 
		//        to fast has caught up with slow, or the linked list does not have cycles inside.
		ListNode* list = createListWithCycle({1, 2}, 1, 0);
		ListNode* loopStart = detectCycle(list);
		print(loopStart->val);

		list = createList({ 1, 2 });
		loopStart = detectCycle(list);
	}
};