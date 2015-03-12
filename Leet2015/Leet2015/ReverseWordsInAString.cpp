#include "stdafx.h"

//Given an input string, reverse the string word by word.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Update(2015 - 02 - 12) :
//For C programmers : Try to solve it in - place in O(1) space.

namespace Solution1
{
	void compact(char* input, int len)
	{
		int front = 0;
		int back = 0;
		int whiteSpaceCount = 1;
		while (front < len)
		{
			if (input[front] != ' ' || (input[front] == ' ' && whiteSpaceCount == 0))
			{
				input[back] = input[front];
				whiteSpaceCount = 0;
				back++;
			}
			front++;
		}		
		input[back] = '\0';
	}

	void compact2(string& input)
	{		
		int front = 0;
		int back = 0;
		int whiteSpaceCount = 1;
		int len = input.length();
		while (front < len)
		{
			if (input[front] != ' ' || (input[front] == ' ' && whiteSpaceCount == 0))
			{
				input[back] = input[front];
				whiteSpaceCount = 0;
				back++;
			}
			front++;
		}
		input = input.substr(0, back);
	}

	void reverse(string& s, int start, int end)
	{
		while (start < end)
		{
			char temp = s[start];
			s[start] = s[end];
			s[end] = temp;
			start++;
			end--;
		}
	}
	
	void reverseWords(string &s) {
		int len = s.length();
		string result = "";
		int start = 0;
		int end = 0;

		while (end < len)
		{
			while (s[end] == ' ')
			{
				end++;
			}
			start = end;
			while (s[end] != ' ' && end < len)
			{
				end++;
			}
			end--;
			reverse(s, start, end);
			
			if (end >= start)
			{
				if (result == "")
				{
					result.append(s.substr(start, end - start + 1));
				}
				else
				{
					result.append(" " + s.substr(start, end - start + 1));
				}
			}
			end++;
		}
		s = result;
		reverse(s, 0, s.length() -1);
	}

	void reverseWords2(string &s) {
		int len = s.length();		
		int start = 0;
		int end = 0;

		while (end < len)
		{
			while (s[end] == ' ')
			{
				end++;
			}
			start = end;
			while (s[end] != ' ' && end < len)
			{
				end++;
			}
			end--;
			reverse(s, start, end);
			end++;
		}
		reverse(s, 0, len - 1);
		//compact((char*)s.c_str(), len);
		compact2(s);
	}

	void ReverseWordsInAString()
	{
		// Error: did not notice the question need clarification on whether to compact spaces
		string input = "the sky is blue";
		reverseWords(input);
		print(input);

		// Error: forget to copy compacted string back on input string
		// Error: should do the copy before the final revers
		// Error: note that in the final reverse, we are reversing the compacted string so the length has changed.
		// Error: early return based on if (input.length() < 2){return;} would not work since this will miss the string compact logic
		input = " ";
		reverseWords(input);
		printWithSpace(input);

		input = "hi!";
		reverseWords(input);
		print(input);

		// Error: should only append to result if(start<=end), otherwise weird value is going to get copied
		input = "1 ";
		reverseWords(input);
		print(input);

		
		// Solution2		
		cout << "\n\n\nSolution 2 using compact string array starts here\n";
		
		// Error: used '==' for assignment instead of '='
		input = "the sky is blue";
		reverseWords2(input);
		print(input);

		input = " ";
		reverseWords2(input);
		printWithSpace(input);

		input = "hi!";
		reverseWords2(input);
		print(input);
		
		input = "1 ";
		reverseWords2(input);
		printWithSpace(input);
	}
}