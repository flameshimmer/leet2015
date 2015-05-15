#include "stdafx.h"

//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//For example, given s = "aab",
//Return
//
//[
//	["aa", "b"],
//	["a", "a", "b"]
//]

namespace Solution1
{
	bool isPalindromeStr(string s)
	{
		int start = 0;
		int end = s.size() - 1;
		while (start < end)
		{
			if (s[start] != s[end]) { return false; }
			start++;
			end--;
		}
		return true;
	}

	void partitionRecurse(string s, int start, int len, vector<string>& result, vector<vector<string>>& results)
	{
		if (start == len)
		{
			results.push_back(result);
			return;
		}
		for (int i = start; i < len; i++)
		{
			string cur = s.substr(start, i - start + 1);
			if (isPalindromeStr(cur))
			{
				result.push_back(cur);
				partitionRecurse(s, i + 1, len, result, results);
				result.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) 
	{
		int len = s.size();
		vector<vector<string>>results;
		if (len == 0) { return results; }
		vector<string>result;
		partitionRecurse(s, 0, len, result, results);
		return results;
	}

	void PalindromePartitioning()
	{
		print(partition(string("aab")));
	}
}