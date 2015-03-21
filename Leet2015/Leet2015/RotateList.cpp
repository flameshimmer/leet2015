#include "stdafx.h"

//Given a list, rotate the list to the right by k places, where k is non - negative.
//
//For example :
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

namespace Solution1
{	
	ListNode *rotateRight(ListNode *head, int k) {
		
		if (!head || !head->next || k == 0)
		{
			return head;
		}
		int len = 0;
		ListNode* cur = head;
		while (cur->next)
		{
			len++;
			cur = cur->next;
		}
		len++;

		k = k % len;
		if (k == 0)
		{
			return head;
		}
		ListNode* fast = head;
		ListNode* slow = head;
		for (int i = 0; i < k; i++)
		{
			fast = fast->next;
		}
		while (fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}

		ListNode* newHead = slow->next;
		slow->next = NULL;
		cur->next = head;
		return newHead;
	}

	void RotateList()
	{
		print(rotateRight(createList({ 1, 2, 3, 4, 5 }), 2));

		// Error: did not thought about the rotation count would be 0 case after the mod is been done. 
		//        need to specially handle this case
		print(rotateRight(createList({ 1, 2}), 2));
	}
}