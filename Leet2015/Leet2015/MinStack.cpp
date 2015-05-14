#include "stdafx.h"

//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.

namespace Solution1
{
	namespace other{
		class MinStack {
		public:
			struct StackNode
			{
				int val;
				int minVal;
				StackNode* next;
				StackNode(int v, int m) : next(NULL), val(v), minVal(m) {};
			};

			StackNode* head;
			MinStack() : head(NULL){};

			void push(int x) {
				if (!head)
				{
					StackNode* newNode = new StackNode(x, x);
					head = newNode;
				}
				else
				{
					StackNode* newNode = new StackNode(x, min(head->minVal, x));
					newNode->next = head;
					head = newNode;
				}
			}

			void pop() {
				if (head != NULL)
				{
					StackNode* temp = head;
					head = head->next;
					delete temp;
				}
			}

			int top() {
				return head->val;
			}

			int getMin() {
				return head->minVal;
			}
		};
	}


	class MinStack {
	public:
		stack<int> s;
		stack<int> m;

		void push(int x) {
			s.push(x);
			if (m.empty() || x <= m.top()) 
			{ 
				m.push(x); 
			}
		}

		void pop() {			
			if (m.top() == s.top())
			{
				m.pop();
			}
			s.pop();
		}

		int top() {
			return s.top();
		}

		int getMin() {
			return m.top();
		}

	};


	void MinStack()
	{
	}
}