#include "stdafx.h"

//You are given a string, S, and a list of words, L, that are all of 
//the same length.Find all starting indices of substring(s) in S that
//is a concatenation of each word in L exactly once and without any 
//intervening characters.
//
//For example, given:
//S : "barfoothefoobarman"
//L : ["foo", "bar"]
//
//	You should return the indices : [0, 9].
//	(order does not matter).

namespace Solution1
{
	vector<int> findSubstring(string s, vector<string>& words)
	{
		vector<int>result;
		int lenw = words.size();
		int lens = s.size();
		int wordLen = words[0].length();
		if (lenw == 0 || ((wordLen * lenw) > lens)) { return result; }


		unordered_map<string, int> toBeFound;
		for (string str : words)
		{
			if (toBeFound.count(str) == 0)
			{
				toBeFound[str] = 1;
			}
			else
			{
				toBeFound[str]++;
			}
		}

		unordered_map<string, int> hasFound;
		for (auto it : toBeFound)
		{
			hasFound[it.first] = 0;
		}

		int found = 0;
		for (int start = 0, end = 0; end + wordLen - 1 < lens;)
		{
			string cur = s.substr(end, wordLen);
			if (toBeFound.count(cur) == 0) { end++; continue; }
			if (hasFound[cur] < toBeFound[cur])
			{
				found++;
			}
			hasFound[cur]++;

			if (found == lenw)
			{
				string cur2 = s.substr(start, wordLen);
				while (toBeFound.count(cur2) == 0 || hasFound[cur] > toBeFound[cur])
				{
					if (toBeFound.count(cur2) == 0)
					{
						start++;
					}
					else
					{
						hasFound[cur]--;
						start += wordLen;
					}

					cur2 = s.substr(start, wordLen);
				}

				if (end + wordLen - start == wordLen * lenw)
				{
					result.push_back(start);
				}
			}
			end += wordLen;
		}
		return result;
	}


	void SubstringWithConcatenationOfAllWords()
	{
		vector<string> L = { "foo", "bar" };
		print(findSubstring(string("barfoothefoobarman"), L));	

		vector<string> L2 = { "fooo", "barr", "wing", "ding", "wing" };
		print(findSubstring(string("lingmindraboofooowingdingbarrwingmonkeypoundcake"), L2));

		vector<string> L3 = { "a"};
		print(findSubstring(string("a"), L3));
	}
}