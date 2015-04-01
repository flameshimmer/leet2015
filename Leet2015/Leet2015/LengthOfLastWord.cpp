#include "stdafx.h"

//Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non - space characters only.
//
//	  For example,
//	  Given s = "Hello World",
//	  return 5.

namespace Solution1
{
	int lengthOfLastWord(const char *s) 
	{
		int start = 0;
		int end = 0;
		int result = 0;
		while (s[end] != '\0')
		{
			while (s[end] != '\0' && s[end] == ' ')
			{
				end++;
			}
			start = end;
			while (s[end] != '\0' && s[end] != ' ')
			{
				end++;
			}
			if (s[start] != '\0')
			{
				result = end - start;
			}			
		}
		return result;
	}

	void LengthOfLastWord()
	{
		print(lengthOfLastWord(string("a ").c_str()));
	}
}