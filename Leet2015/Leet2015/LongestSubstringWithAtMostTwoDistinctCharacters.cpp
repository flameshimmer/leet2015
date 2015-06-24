#include "stdafx.h"

//Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
//
//For example, Given s = “eceba”,
//
//T is "ece" which its length is 3.

namespace Solution1
{

	int lengthOfLongestSubstringTwoDistinct(string s) 
	{
		int lens = s.length();
		if (lens < 2) { return lens; }

		int longest = 0;
		char c1 = NULL;
		int index1;
		char c2 = NULL;
		int index2;

		int start = 0;
		for (int i = 0; i < lens; i++)
		{
			char c = s[i];
			if (c != c1 && c != c2)
			{
				if (c1 == NULL || c2 == NULL)
				{
					if (c1 == NULL)
					{
						c1 = c;
						index1 = i;
					}
					else
					{
						c2 = c;
						index2 = i;
					}
				}
				else
				{
					longest = max(longest, i - start);
					if (index1 < index2)
					{
						start = index1 + 1;
						c1 = c;
						index1 = i;
					}
					else
					{
						start = index2 + 1;
						c2 = c;
						index2 = i;
					}
				}
			}
			else
			{
				if (c == c1) { index1 = i; }
				else { index2 = i; }
			}
		}
		longest = max(longest, lens- start);
		return longest;
	}

	namespace other
	{
		int lengthOfLongestSubstringTwoDistinct(string s) {
			int start = 0;
			int j = -1;
			int maxLen = 0;

			for (int k = 1; k < s.size(); k++)
			{
				if (s[k] == s[k - 1]) { continue; }
				if (j > -1 && s[k] != s[j])
				{
					maxLen = max(maxLen, k - start);
					start = j + 1;
				}
				j = k - 1;
			}
			maxLen = max(maxLen, s.size() - start);
			return maxLen;
		}
	}
	void LongestSubstringWithAtMostTwoDistinctCharacters()
	{		
		// Error: note that at the end of the loop, will need to get the diff between end of string and start again.
		print(lengthOfLongestSubstringTwoDistinct("aa"));
		print(lengthOfLongestSubstringTwoDistinct("aba"));
		print(lengthOfLongestSubstringTwoDistinct("eceba"));
	}
}