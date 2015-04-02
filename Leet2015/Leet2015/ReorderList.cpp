#include "stdafx.h"

//Given a singly linked list L : L0→L1→…→Ln - 1→Ln,
//reorder it to : L0→Ln→L1→Ln - 1→L2→Ln - 2→…
//
//You must do this in - place without altering the nodes' values.
//
//For example,
//Given{ 1, 2, 3, 4 }, reorder it to{ 1, 4, 2, 3 }

namespace Solution1
{
	ListNode* reverse(ListNode* head)
	{
		if (!head || !head->next) { return head; }
		ListNode* cur = head;
		ListNode* next = cur->next;
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
	void reorderList(ListNode *head)
	{
		if (!head || !head->next){ return; }
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* newList = slow->next;
		slow->next = NULL;

		newList = reverse(newList);

		if (!newList){ return; }

		ListNode* result = NULL;
		ListNode* resultTail = NULL;
		bool isFirst = true;
		while (head && newList)
		{
			ListNode* selected = isFirst ? head : newList;
			if (!result) { result = selected; }
			else{ resultTail->next = selected; }
			resultTail = selected;

			(selected == head) ? (head = head->next) : (newList = newList->next);
			isFirst = !isFirst;
		}		
		resultTail->next = head ? head : newList;		
	}

	void ReorderList()
	{
		// Error: when revesing the linked list's while loop, note cur is set to next, not nextNext
		// Error: when merging two lists together, be very careful on whether resultTail can be null case
		// Note: with the method of slow advance once and fast advance twice, eventually:
		//       if the nodes has even number of nodes: the slow one will stop at the end of the first half
		//       if the nodes has odd number of nodes: the slow one will stop at the middle node
		//       then depending on which half of the nodes you want to have more, if you pick the middle node to
		//       be the start of the second list, then the second list will have one more node. If you pick the 
		//       middle node's next to be the second list's head, then the second list will have one less node
		//       than the first half. In the case of the need of NULL termination, we can add a prev pointer that
		//       points to the node immediately behind slow to NULL terminate the list if necessary.
		ListNode* list = createList({1, 2, 3, 4, 5});
		reorderList(list);
	}
}