#include "stdafx.h"

//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space.You may not modify 
//the values in the list, only nodes itself can be changed.


namespace Solution1
{
	ListNode *swapPairs(ListNode *head)
	{
		if (!head || !head->next) { return head; }

		ListNode* cur = head;
		ListNode* next = cur->next;
		ListNode* nextNext;
		ListNode* prev = NULL;
		ListNode* newHead = head->next;
		while (next)
		{
			nextNext = next->next;
			next->next = cur;
			cur->next = nextNext;
			if (prev)
			{ 
				prev->next = next; 
			}			
			prev = cur;
			
			cur = nextNext;
			if (cur) 
			{ 
				next = cur->next; 
			}
			else
			{
				next = NULL;
			}
		}
		return newHead;
	}

	namespace other
	{
		ListNode *swapPairs(ListNode *head)
		{
			if (!head || !head->next) { return head; }
			ListNode* cur = head;
			ListNode* next = cur->next;
			ListNode* nextNext = next->next;

			ListNode* newHead = next;
			cur->next = next->next;
			next->next = cur;
			newHead->next->next = swapPairs(nextNext);
			return newHead;
		}
	}

	void SwapNodesInPairs()
	{
		using namespace other;
		print(other::swapPairs(createList({ 1, 2, 3, 4, 5, 6, 7, 8 })));
	}
}