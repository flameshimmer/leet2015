#include "stdafx.h"

//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.
//
//Note:
//Have you consider that the string might be empty ? This is a good question to ask during an interview.
//
//For the purpose of this problem, we define empty string as valid palindrome.


namespace Solution1
{
	bool isPalindrome(string s) {
		int len = s.length();
		if (len <= 1) { return true; }

		int start = 0;
		int end = len - 1;

		while (start <= end)
		{
			while (!isalnum(s[start]) && start < end)
			{
				start++;
			}
			while (!isalnum(s[end]) && end > start)
			{
				end--;
			}
			if (tolower(s[start]) != tolower(s[end]) || !isalnum(s[start]))
			{
				return false;
			}
			start++;
			end--;
		}

		return true;
	}

	void ValidPalindrome()
	{
		print(isPalindrome(string(".,")));
		print(isPalindrome(string("A man, a plan, a canal : Panama")));
		print(isPalindrome(string("race a car")));
	}
};