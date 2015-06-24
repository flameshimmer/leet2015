#include "stdafx.h"

//Given a string S, you are allowed to convert it to a palindrome by adding characters
//in front of it.Find and return the shortest palindrome you can find by performing this transformation.
//
//For example :
//
//Given "aacecaaa", return "aaacecaaa".
//
//Given "abcd", return "dcbabcd".

namespace Solution1
{
	namespace wrong{
		string shortestPalindrome(string s)
		{
			int lens = s.length();
			if (lens < 2) { return s; }

			int start = 0;
			int end = lens - 1;

			while (start < end)
			{
				if (s[start] != s[end])
				{
					s.insert(s.begin() + start, s[end]);
					end++;
				}
				start++;
				end--;
			}
			return s;
		}
	}

	void ShortestPalindrome()
	{
/*		print(shortestPalindrome("adcba"));
		print(shortestPalindrome("abcd"));
		print(shortestPalindrome("aacecaaa"));	*/	
	}
}
