#include "stdafx.h"

//Sort a linked list in O(n log n) time using constant space complexity.

namespace Solution1
{
	ListNode *sortList(ListNode *head) 
	{
		if (!head || !head->next) { return head; }
		if (!(head->next->next))
		{
			if (head->val < head->next->val) { return head; }
			else{
				ListNode* temp = head->next;
				head->next->next = head;
				head->next = NULL;
				return temp;
			}
		}
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		
		ListNode* newHead = slow->next;
		slow->next = NULL;
		ListNode* s1 = sortList(head);
		ListNode* s2 = sortList(newHead);

		ListNode* result = NULL;
		ListNode* resultTail = NULL;
		while (s1 && s2)
		{
			ListNode* selected = s1->val < s2->val ? s1 : s2;

			if (!result) { result = selected; }
			else{ resultTail->next = selected; }
			resultTail = selected;

			(selected == s1) ? (s1 = s1->next) : (s2 = s2->next);
		}
		resultTail->next = s1 ? s1 : s2;
		return result;
	}

	void SortList()
	{
		print(sortList(createList({1,2,3,4})));		
	}
}