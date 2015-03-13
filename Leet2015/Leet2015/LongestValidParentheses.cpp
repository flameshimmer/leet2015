#include "stdafx.h"

//Given a string containing just the characters '(' and ')', find the length of the longest valid(well - formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

namespace Solution1
{
	int longestValidParentheses(string s) {
		int len = s.length();
		if (len == 0){ return 0; }
		
		int result = 0;
		stack<pair<int, bool>> myStack; // pair content is <index, isLeftParenthese>
		s = ')' + s;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '(')
			{
				myStack.push(make_pair(i, true));
			}
			else
			{
				if (myStack.empty() || myStack.top().second == false)
				{
					myStack.push(make_pair(i, false));
				}
				else
				{					
					myStack.pop();					
					result = max(result, i - myStack.top().first);					
				}
			}
		}
		return result;
	}

	// This is solution 2. This solution does not pad the input string, instead, it handles the case when the stack is empty.
	// Since we do insert invalid ')' into the stack, this will help us to successfully distinguish between '()()' and '())()'
	// When we see the stack is empty, we know for sure it is '^()()' situation. Therefore, we known the length of the
	// string is i+1;
	int longestValidParentheses2(string s) {
		int len = s.length();
		if (len == 0){ return 0; }

		int result = 0;
		stack<pair<int, bool>> myStack; // pair content is <index, isLeftParenthese>

		for (int i = 0; i < len; i++)
		{
			if (s[i] == '(')
			{
				myStack.push(make_pair(i, true));
			}
			else
			{
				if (myStack.empty() || myStack.top().second == false)
				{
					myStack.push(make_pair(i, false));
				}
				else
				{
					myStack.pop();
					if (myStack.empty())
					{
						result = max(result, i + 1);
					}
					else
					{
						result = max(result, i - myStack.top().first);
					}
				}
			}
		}
		return result;
	}


	void LongestValidParentheses()
	{
		cout << "Solution1: \n";
		// Error: only considered the invalidate case to be extra ')' shows up. This does not solve the problem
		// when consecutivity is interupted by '(', in which case, there is not enough ')' shows up. Example: '()(()'
		print(longestValidParentheses(")()())"));
		print(longestValidParentheses("(()"));

		// Error: main problem is to never consider also putting the ')' into the stack. In this case, putting the ')'
		// into the stack can easily help to get to know what is the last valid start index. 
		// Also padding the string with a prefix ')' successfully eliminated the branch to handle when stack is empty. 
		// Because in this case the stack will never be empty.
		print(longestValidParentheses("()(()"));
		print(longestValidParentheses("()()"));

		// Solution 2 driver
		cout << "Solution2: \n";
		print(longestValidParentheses2(")()())"));
		print(longestValidParentheses2("(()"));
		print(longestValidParentheses2("()(()"));
		print(longestValidParentheses2("()()"));
	}
}