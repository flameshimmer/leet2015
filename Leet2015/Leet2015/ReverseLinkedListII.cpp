#include "stdafx.h"


//Reverse a linked list from position m to n.Do it in - place and in one - pass.
//
//For example :
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note :
//	 Given m, n satisfy the following condition :
//1 ≤ m ≤ n ≤ length of list

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
	void reverseLinkList(ListNode** head, ListNode** tail)
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
		ListNode* temp = *head;
		*head = *tail;
		*tail = temp;
	}

	ListNode* reverseBetween(ListNode *head, int m, int n) {
		ListNode* preHead = NULL;
		ListNode* postTail = NULL;
		ListNode* cur = head;		
		int i = 1;
		while (cur)
		{
			if (i == m - 1 && i > 0)
			{
				preHead = cur;
			}
			if (i == n)
			{
				postTail = cur->next;
				break;
			}
			cur = cur->next;
			i++;
		}
		
		ListNode* rStart = preHead ? preHead->next : head;
		ListNode* rEnd = cur;
		reverseLinkList(&rStart, &rEnd);
		if (preHead)
		{
			preHead->next = rStart;
		}
		else
		{
			head = rStart;
		}
		rEnd->next = postTail;
		return head;
	}

	void ReverseLinkedListII()
	{
		// Error: need to check whether preHead is NULL before calling next pointer on it
		// Error: in the reverseList function, set the new *tail to cur while at that time cur is NULL.
		//        Fixed by using a temp node to exchange the head and tail value.
		ListNode* input = createList({1, 2, 3, 4, 5});
		print(input);
		print(reverseBetween(input, 2, 4));

		// Error: Note that the traditional link list reversal algorithms only works for the link list that is NULL terminated. 
		//        Always ensure the link list end is point to NULL when you do this. Otherwise when start and end are equal, it 
		//        still do at least one swap, which is what we don't want.
		// Error: Need to consider the case where the m is the beginning of the linked list. In this case the head pointer of
		//        the list need to be updated. 
		input = createList({ 3, 5 });
		print(input);
		print(reverseBetween(input, 1, 1));
	}
};