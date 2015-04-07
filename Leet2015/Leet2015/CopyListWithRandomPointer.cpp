#include "stdafx.h"


namespace Solution1
{
	RandomListNode *copyRandomList(RandomListNode *head) 
	{
		if (!head) { return NULL; }
		
		// Insert cloned node
		RandomListNode* cur = head;
		while (cur)
		{
			RandomListNode* newNode = new RandomListNode(cur->label);
			newNode->next = cur->next;
			cur->next = newNode;
			cur = newNode->next;
		}

		// Add random pointers to the cloned node
		cur = head;
		while (cur)
		{
			if (cur->random)
			{
				cur->next->random = cur->random->next;
			}			
			cur = cur->next->next;
		}

		// Separate the cloned node from the list
		RandomListNode* newHead = NULL;
		RandomListNode* tail = NULL;
		cur = head;
		while (cur)
		{
			if (!newHead) { newHead = cur->next; }
			else
			{
				tail->next = cur->next;
			}
			tail = cur->next;
			
			cur->next = cur->next->next;
			cur = cur->next;
		}
		tail->next = NULL;
		return newHead;
	}

	void CopyListWithRandomPointer()
	{
		// Error: Only copy random when the current node has random. But don't put it as the while loop condition, since even a node does not have random, we still want to check the following nodes.
		// Error: The problem requires the original lists getting restored.
		copyRandomList(new RandomListNode(-1));
	}
}