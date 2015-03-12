#include "stdafx.h"

//Given an input string, reverse the string word by word.A word is defined as a sequence of non - space characters.
//
//The input string does not contain leading or trailing spaces and the words are always separated by a single space.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Could you do it in - place without allocating extra space ?

namespace Solution1
{
	void reverseII(string& s, int start, int end)
	{
		while (start < end)
		{
			s[start] ^= s[end];
			s[end] ^= s[start];
			s[start] ^= s[end];
			
			start++;
			end--;
		}
	}

	void reverseWordsII(string &s) {
		int front = 0;
		int back = 0;
		int len = s.length();
		while (front < len)
		{
			while (s[front] == ' ' && front < len)
			{
				front++;
			}
			back = front;

			while (s[front] != ' ' && front < len)
			{
				front++;
			}			
			reverseII(s, back, front-1);			
		}
		reverseII(s, 0, len - 1);
	}

	void ReverseWordsInAStringII()
	{
		// Error: forget to add start++ and end-- in the while loop
		// Error: forgot to add front back to where it was after the first reverse. So the sequence should be front--;Reverse;front++,
		//        Or just pass front - 1 into the real reverse function
		string input = "the sky is blue";
		reverseWordsII(input);
		print(input);
	}
};