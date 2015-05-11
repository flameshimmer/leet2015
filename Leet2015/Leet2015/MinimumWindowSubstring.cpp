#include "stdafx.h"

//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//For example,
//S = "ADOBECODEBANC"
//T = "ABC"
//Minimum window is "BANC".
//
//Note:
//If there is no such window in S that covers all characters in T, return the emtpy string "".
//
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.


namespace Solution1
{
	string minWindow(string s, string t) 
	{
		int lens = s.size();
		int lent = t.size();
		string result;
		if (lens < lent) { return result; }

		int toBeFound[256] = { 0 };
		int hasFound[256] = { 0 };
		for (char c : t)
		{
			toBeFound[c]++;
		}

		int count = 0;
		int minLen = INT_MAX;
		for (int start = 0, end = 0; end < lens; end++)
		{
			char c = s[end];
			if (toBeFound[c] == 0) { continue; }

			if (toBeFound[c] > hasFound[c])
			{
				count++;
			}
			hasFound[c]++;

			if (count == lent)
			{
				char b = s[start];
				while (toBeFound[b] == 0 || hasFound[b] > toBeFound[b])
				{
					if (hasFound[b] > toBeFound[b])
					{
						hasFound[b]--;
					}
					start++;
					b = s[start];
				}

				int len = end - start + 1;
				if (len < minLen)
				{
					minLen = len;
					result = s.substr(start, len);
				}
			}
		}
		return result;
	}

	void MinimumWindowSubstring()
	{
		print(minWindow(string("ADOBECODEBANC"), string("ABC")));
		// ERROR: the string to look up can contain duplicated char, so if use a hash table, it can't get the correct answer. 
		//        Example input: ["a", "aa"]
		print(minWindow(string("a"), string("aa")));

		print(minWindow(string("ab"), string("a")));
		print(minWindow(string("ab"), string("b")));
		print(minWindow(string("bba"), string("ab")));

	}
}