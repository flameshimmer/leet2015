#include "stdafx.h"

//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list : 1->2->3->4->5
//
//For k = 2, you should return : 2->1->4->3->5
//
//For k = 3, you should return : 3->2->1->4->5

namespace Solution1
{
	/**
	* Definition for singly-linked list.
	* struct ListNode {
	*     int val;
	*     ListNode *next;
	*     ListNode(int x) : val(x), next(NULL) {}
	* };
	*/
	void reverseLinkedList(ListNode** head, ListNode** tail)
	{
		(*tail)->next = NULL;
		ListNode* cur = *head;
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
		ListNode* temp = *tail;
		*tail = *head;
		*head = temp;
	}
	
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (!head) { return NULL; }
		ListNode* cur = head;
		ListNode* newHead = NULL;
		ListNode* newTail = NULL;
		while (cur)
		{
			ListNode* curHead = cur;
			int count = 0;
			while (cur && count < k-1)
			{
				cur = cur->next;
				count++;
			}
			if (!cur)
			{				
				return newHead ? newHead : head;
			}
			else
			{
				ListNode* next = cur->next;
				reverseLinkedList(&curHead, &cur);
				if (!newHead) { newHead = curHead; }
				if (newTail) { newTail->next = curHead; }
				newTail = cur;				
				cur = next;
				newTail->next = cur;
			}
		}
		return newHead;
	}

	void ReverseNodesInKGroup()
	{
		// Error: forget to return from the function
		// Error: to include every k node, the pointer need to advance k-1 times, not k times
		// Error: when ready to advance cur, we should remember what is cur's next to connect the link list back together before next loop
		// Error: should use if(cur) instead of the count check to determine whether the remaining link is not long enough. 
		ListNode* input = createList({ 1, 2, 3, 4, 5 });
		print(input);
		print(reverseKGroup(input, 2));
	}
};