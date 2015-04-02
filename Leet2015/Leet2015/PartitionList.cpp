#include "stdafx.h"

//Given a linked list and a value x, partition it such that all 
//nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes 
//in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.

namespace Solution1
{
	ListNode *partition(ListNode *head, int x) 
	{
		if (!head || !head->next){ return head; }
		ListNode* less = NULL;
		ListNode* lessTail = NULL;
		ListNode* more = NULL;
		ListNode* moreTail = NULL;

		ListNode* cur = head;
		while (cur)
		{
			if (cur->val < x)
			{
				if (!less) { less = cur; }
				else{ lessTail->next = cur; }
				lessTail = cur;
			}
			else
			{
				if (!more){ more = cur; }
				else{ moreTail->next = cur; }
				moreTail = cur;
			}
			cur = cur->next;
		}

		if (lessTail){ lessTail->next = more; }
		if (moreTail) { moreTail->next = NULL; }
		return less ? less : more;
	}

	namespace other
	{
		ListNode *partition(ListNode *head, int x)
		{
			if (!head || !head->next) { return head; }
			ListNode* tail = head;
			int count = 1;
			while (tail->next)
			{
				tail = tail->next;
				count++;
			}

			ListNode* dummy = new ListNode(-1);
			dummy->next = head;
			ListNode* cur = dummy;
			ListNode* newTail = tail;
			ListNode* newHead = NULL;
			ListNode* firstInsert = NULL;
			while (cur->next && count)
			{
				if (cur->next->val >= x)
				{
					if (!firstInsert) { firstInsert = cur->next; }
					newTail->next = cur->next;
					newTail = cur->next;
					cur->next = cur->next->next;
				}
				else 
				{
					if (!newHead)
					{
						newHead = cur->next;
					}
					cur = cur->next;
				}

				count--;
			}
			newTail->next = NULL;
			delete dummy;
			return newHead ? newHead : firstInsert;
		}
	}

	void PartitionList()
	{
		//Given 1->4->3->2->5->2 and x = 3,
		//return 1->2->2->4->3->5.
		print(partition(createList({1,4,3,2,5,2}), 3));
		using namespace other;
		//print(other::partition(createList({ 1, 4, 3, 2, 5, 2 }), 3));
		print(other::partition(createList({ 1, 2 }), 0));
	}
}