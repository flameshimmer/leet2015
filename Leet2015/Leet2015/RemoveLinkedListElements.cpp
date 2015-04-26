#include "stdafx.h"

//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//	Return: 1 --> 2 --> 3 --> 4 --> 5

namespace Solution1
{
	ListNode* removeElements(ListNode* head, int val) 
	{
		if (!head){ return NULL; }
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		ListNode* cur = dummy;
		while (cur && cur->next)
		{
			if (cur->next->val == val)
			{
				ListNode* temp = cur->next;
				cur->next = cur->next->next;
				delete temp;
			}
			else
			{
				cur = cur->next;
			}
		}
		ListNode* result = dummy->next;
		delete dummy;
		return result;
	}
	
	
	void RemoveLinkedListElements()
	{
		print(removeElements(createList({1,2,6,3,4,5,6}), 6));
	}
}