#include "stdafx.h"

//Write a function to find the longest common prefix string amongst an array of strings.
// "aa", "ab", "abc"
namespace Solution1
{
	string longestCommonPrefix(vector<string> &strs) 
	{
		string result;
		int len = strs.size();
		if (len == 0)
		{
			return result;
		}
		else if (len == 1)
		{
			return strs[0];
		}

		string target = strs[0];
		for (unsigned int i = 0; i < target.length(); i++)
		{
			char c = target[i];
			for (int j = 1; j < len; j++)
			{
				string cur = strs[j];
				if (i > cur.length() || cur[i] != c)
				{
					return result;
				}
			}
			result.push_back(c);
		}
		return result;
	}

	void LongestCommonPrefix()
	{
		print(longestCommonPrefix(createVector({string("aa"), string("ab"), string("ac")})));
	}
}