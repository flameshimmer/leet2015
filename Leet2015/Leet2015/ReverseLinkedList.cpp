#include "stdafx.h"

//Reverse a singly linked list.

namespace Solution1
{
	ListNode* reverseList(ListNode* head)
	{
		if (!head || !head->next) { return head; }
		ListNode* cur = head;
		ListNode* next = head->next;
		ListNode* nextNext;

		cur->next = NULL;
		while (next)
		{
			nextNext = next->next;
			next->next = cur;
			cur = next;
			next = nextNext;
		}
		return cur;
	}

	namespace other
	{
		ListNode* reverseList(ListNode* head)
		{
			if (!head || !head->next) { return head; }
			
			ListNode* next = head->next;
			ListNode* newNext = reverseList(head->next);

			head->next = NULL;
			next->next = head;
			return newNext;
		}
	}

	void ReverseLinkedList()
	{
	}
}