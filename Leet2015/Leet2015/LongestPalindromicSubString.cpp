#include "stdafx.h"

//Given a string S, find the longest palindromic substring in S.
//You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.


namespace Solution1
{
	string getPalindromeLength(string s, int left, int right)
	{
		while (left >= 0 && right < s.length())
		{
			if (s[left] != s[right])
			{
				break;
			}
			left--;
			right++;
		}

		left++;
		right--;
		string result = s.substr(left, right - left + 1);
		return result;
	}

	string getLonger(string s1, string s2)
	{
		if (s2.length() > s1.length())
		{
			return s2;
		}
		else
		{
			return s1;
		}
	}

	string longestPalindrome(string s) 
	{		
		if (s.length() < 2)
		{
			return s;
		}
		
		string longest = "";
		for (int i = 0; i < s.length(); i++)
		{
			int curLen = longest.length();		
			longest = getLonger(longest, getPalindromeLength(s, i, i));
			if (i + 1 < s.length())
			{
				longest = getLonger(longest, getPalindromeLength(s, i, i + 1));
			}			
		}
		return longest;
	}

	void LongestPalindromeSubString()
	{
		// Error: when coming out of the while loop, the index of left and right are in the invalid state. Will need to ++ left and --right 
		// to get it back to the state when it was valid
		print(longestPalindrome(string("bb")));
	}
}