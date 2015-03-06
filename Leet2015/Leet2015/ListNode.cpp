#include "stdafx.h"

//Definition for singly - linked list.
ListNode* createList(initializer_list<int> list)
{
	ListNode* head = NULL;
	ListNode* tail = NULL;
	for (int value : list)
	{
		ListNode* newNode = new ListNode(value);
		if (!head)
		{
			head = newNode;
		}
		else
		{
			tail->next = newNode;
		}
		tail = newNode;
	}
	return head;
}

void deleteList(ListNode* list)
{
	if (!list)
	{
		return;
	}
	while (list)
	{
		ListNode* next = list->next;
		delete list;
		list = next;
	}
}

void print(ListNode* list)
{
	cout << "ListNode: \n";
	if (!list){ return; }
	while (list->next)
	{
		cout << list->val << " -> ";
		list = list->next;
	}
	cout << list->val << "\n";
}



