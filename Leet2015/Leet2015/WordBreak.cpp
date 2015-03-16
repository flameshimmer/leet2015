#include "stdafx.h"

//Given a string s and a dictionary of words dict, determine if s can be segmented 
//into a space - separated sequence of one or more dictionary words.
//
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//
//Return true because "leetcode" can be segmented as "leet code".


namespace Solution1
{
	bool recurse(string s, unordered_set<string> map, int start, int end, string result)
	{
		string cur = s.substr(start, end - start + 1);
		if (end == s.length() - 1)
		{
			return (map.count(cur) > 0);
		}

		if (map.count(cur) > 0)
		{
			bool useThisWord = recurse(s, map, end + 1, end + 1, result + " " + cur);
			if (useThisWord) { return true; }
		}
		// If not use this word
		return recurse(s, map, start, end + 1, result);
	}
	
	
	bool wordBreak(string s, unordered_set<string> &dict) {		
		s = "#" + s;
		int len = s.length();
		vector<bool>A(len, false);
		A[0] = true;
		
		for (int n = 1; n < len; n++)
		{
			for (int m = 1; m <= n; m++)
			{
				string cur = s.substr(m, n-m+1);
				if (dict.count(cur) > 0 && A[m - 1])
				{
					A[n] = 1;
					break;
				}
			}
		}

		return A[len-1];
	}

	void WordBreak()
	{
		string s1 = "leetcode";
		unordered_set<string> dict = {"leet", "code"};
		print(wordBreak(s1, dict));

		// Error: recursion solution is not going to make it to the below case in time
		// Note: can consider prepend the input string to conform the look up table for DP solution
		string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
		unordered_set<string> dict2 = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
		print(wordBreak(s2, dict2));
	}
};