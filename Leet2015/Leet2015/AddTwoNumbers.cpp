#include "stdafx.h"

//You are given two linked lists representing two non - negative numbers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//   Output : 7 -> 0 -> 8

namespace Solution1
{
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (!l1 || !l2)
		{
			return l1 ? l1 : l2;
		}
		int carry = 0;
		ListNode* result = NULL;
		ListNode* tail = NULL;
		while (l1 != NULL || l2 != NULL || carry > 0)
		{			
			int value1 = l1 ? l1->val : 0;
			int value2 = l2 ? l2->val : 0;
			ListNode* newNode = new ListNode((value1 + value2 + carry) % 10);
			carry = (value1 + value2 + carry) / 10;
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;

			if (!result)
			{
				result = newNode;
			}
			else
			{
				tail->next = newNode;
			}
			tail = newNode;
		}

		tail->next = l1 ? l1 : l2;
		return result;
	}

	void AddTwoNumbers()
	{
		// Error: Forget about the potential to add a new node if the added number has one more digit than both l1 and l2
		print(addTwoNumbers(createList({ 2, 4, 3 }), createList({ 5, 6, 4 })));

		// Error: forget to add carry when calculating carry. The fix is to add carry to calculate the next carry
		print(addTwoNumbers(createList({ 5 }), createList({ 5 })));

		print(addTwoNumbers(createList({ 1 }), createList({ 9, 9 })));
	}
}