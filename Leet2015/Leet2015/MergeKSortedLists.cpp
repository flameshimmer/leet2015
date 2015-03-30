#include "stdafx.h"

//Merge k sorted linked lists and return it as one sorted list.
//Analyze and describe its complexity.

namespace Solution1
{
	ListNode* mergetTwoList(ListNode* l1, ListNode* l2)
	{
		if (!l1 || !l2) { return l1 ? l1 : l2; }
		ListNode* head = NULL;
		ListNode* tail = NULL;
		while (l1 && l2)
		{
			ListNode* picked = (l1->val < l2->val) ? l1 : l2;
			if (!head) { head = picked; }
			else{ tail->next = picked; }
			tail = picked;
			if (picked == l1) { l1 = l1->next; }
			else { l2 = l2->next; }
		}
		if (l1 || l2)
		{
			tail->next = l1 ? l1 : l2;
		}
		return head;
	}

	ListNode* mergeLists(vector<ListNode*>& lists, int start, int len)
	{
		if (len == 0) { return NULL; }
		if (len == 1) { return lists[start]; }
		if (len == 2) { return mergetTwoList(lists[start], lists[start + 1]); }
		
		int mid = len / 2;
		ListNode* left = mergeLists(lists, start, mid);
		ListNode* right = mergeLists(lists, start+mid, len -  mid);
		return mergetTwoList(left, right);
	}
	
	ListNode *mergeKLists(vector<ListNode *> &lists) 
	{
		int size = lists.size();
		return mergeLists(lists, 0, size);
	}

	namespace other
	{
		typedef bool(*comp)(ListNode* a, ListNode* b);
		static bool compare(ListNode* a, ListNode* b)
		{
			return (a->val>b->val);
		}
		
		ListNode *mergeKLists(vector<ListNode *> &lists)
		{
			priority_queue<ListNode*, std::vector<ListNode*>, comp> myQ(compare);

			for (unsigned int i = 0; i < lists.size(); i++)
			{
				if (lists[i] != NULL)
				{
					myQ.push(lists[i]);
				}				
			}
			ListNode* head = NULL;
			ListNode* tail = NULL;
			while (!myQ.empty())
			{
				ListNode* cur = myQ.top();
				myQ.pop();
				if (!head) { head = cur; }
				else { tail->next = cur; }
				tail = cur;
				if (cur->next)
				{
					myQ.push(cur->next);
				}				
			}
			return head;
		}
	}

	void MergeKSortedLists()
	{
		// Error: Note that function merge list's start index is start, not 0!
		// Perf: divide and conquer to merge two lists is faster than using priority queue
		vector<ListNode*> input = { 
			createList({ -10, -9, -9, -3, -1, -1, 0 }),
			createList({-5}),
			createList({4}),
			createList({-8}),
			createList({}),
			createList({ -9, -6, -5, -4, -2, 2, 3 }),
			createList({ -3, -3, -2, -1, 0 })
		};
		//print(mergeKLists(input));

		using namespace other;
		input = {
			createList({ 1 }),
			createList({ 0 })
		};
		print(other::mergeKLists(input));
	}
}