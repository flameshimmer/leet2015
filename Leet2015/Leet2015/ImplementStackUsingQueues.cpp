#include "stdafx.h"

//Implement the following operations of a stack using queues.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//empty() --Return whether the stack is empty.
//Notes:
//You must use only standard operations of a queue -- which means only push to back, 
//peek / pop from front, size, and is empty operations are valid.
//Depending on your language, queue may not be supported natively.
//You may simulate a queue by using a list or deque(double - ended queue), as long as you use only standard operations of a queue.
//You may assume that all operations are valid(for example, no pop or top operations will be called on an empty stack).

namespace Solution1
{
	class Stack {
		queue<int> targetq;
		queue<int> bufferq;
		int lastVal;
	public:		
		// Push element x onto stack.
		void push(int x) {
			if (targetq.empty())
			{
				targetq.swap(bufferq);
			}
			
			targetq.push(x);
			lastVal = x;
		}

		// Removes the element on top of the stack.
		void pop() {
			if (targetq.empty())
			{
				targetq.swap(bufferq);
			}
			int size = targetq.size();
			if (size == 0) { return; }
			else if (size == 1) { targetq.pop(); }
			else {
				while (size > 0)
				{					
					if (size >= 2)
					{
						bufferq.push(targetq.front());
						if (size == 2)
						{
							lastVal = targetq.front();
						}
					}					
					targetq.pop();
					size--;
				}
			}			
		}

		// Get the top element.
		int top() {
			return lastVal;
		}

		// Return whether the stack is empty.
		bool empty() {
			return (targetq.empty() && bufferq.empty());
		}
	};
	void ImplementStackUsingQueues()
	{
		Stack s;
		s.push(1);
		print(s.empty());
	}
}