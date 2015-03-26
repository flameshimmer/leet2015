#include "stdafx.h"

//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//
namespace Solution1
{
	bool isLeft(char c)
	{
		return ((c == '(') || (c == '[') || (c == '{'));
	}

	bool match(char left, char right)
	{
		if (left == '(') { return right == ')'; }
		if (left == '[') { return right == ']'; }
		if (left == '{') { return right == '}'; }
		return false;
	}

	bool isValid(string s) 
	{
		stack<char> myStack;
		for (char c : s)
		{
			if (isLeft(c))
			{
				myStack.push(c);
			}
			else
			{
				if (!myStack.empty() && match(myStack.top(), c))
				{
					myStack.pop();
				}
				else
				{
					return false;
				}
			}
		}
		return myStack.empty();
	}

	void ValidParentheses()
	{
		/*print(isValid(string("()")));
		print(isValid(string("()[]{}")));
		print(isValid(string("(]")));
		print(isValid(string("([)]")));
		*/print(isValid(string("]")));

	}
};