#include "stdafx.h"

//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists :
//
//A : a1 → a2
//	↘
//	c1 → c2 → c3
//	↗
//B : b1 → b2 → b3
//	begin to intersect at node c1.
//
//
//Notes :
//
//	  If the two linked lists have no intersection at all, return null.
//	  The linked lists must retain their original structure after the function returns.
//	  You may assume there are no cycles anywhere in the entire linked structure.
//	  Your code should preferably run in O(n) time and use only O(1) memory.
//  Credits :
//		  Special thanks to @stellari for adding this problem and creating all test cases.

namespace Solution1
{
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
		if (!headA || !headB) { return NULL; }
		int lenA = 0;
		int lenB = 0;
		ListNode* curA = headA;
		ListNode* curB = headB;
		while (curA)
		{
			curA = curA->next;
			lenA++;
		}
		while (curB)
		{
			curB = curB->next;
			lenB++;
		}

		bool Alonger = lenA > lenB;
		ListNode* longer = Alonger ? headA : headB;
		int diff = Alonger ? lenA - lenB : lenB - lenA;
		ListNode* shorter = Alonger ? headB : headA;

		while (diff)
		{
			longer = longer->next;
			diff--;
		}
		while (longer && shorter && longer != shorter)
		{
			longer = longer->next;
			shorter = shorter->next;
		}
		return longer;
	}

	void IntersectionOfTwoLinkedLists()
	{
	
	}
}