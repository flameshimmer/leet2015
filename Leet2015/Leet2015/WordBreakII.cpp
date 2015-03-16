#include "stdafx.h"

//Given a string s and a dictionary of words dict, add spaces in s to 
//construct a sentence where each word is a valid dictionary word.
//
//Return all such possible sentences.
//
//For example, given
//s = "catsanddog",
//dict = ["cat", "cats", "and", "sand", "dog"].
//
//A solution is["cats and dog", "cat sand dog"]

namespace Solution1
{
	void recurse(string s, unordered_set<string> dict, int start, int len, string result, vector<string>& results, vector<bool>& possible)
	{
		if (start == len)
		{
			results.push_back(result.substr(0, result.length() - 1));
		}

		for (int i = start; i < len; i++)
		{
			string cur = s.substr(start, i - start + 1);
			if (dict.count(cur) > 0 && possible[i + 1])
			{
				int oldSize = results.size();
				recurse(s, dict, i + 1, len, result + cur + " ", results, possible);
				if (results.size() == oldSize)
				{
					possible[i + 1] = false;
				}
			}
		}
	}

	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> results;
		string result = "";
		int len = s.length();
		vector<bool>possible(len+1, true);

		recurse(s, dict, 0, len, result, results, possible);
		return results;
	}

	void WordBreakII()
	{		
		string s1 = "catsanddog";
		unordered_set<string> dict = { "cat", "cats", "and", "sand", "dog" };
		print(wordBreak(s1, dict));

		// Error: timed out due to didn't early terminate the recursion using a memory table.
		//        Note that the recursive condition is important. Using the concept of "which position to put white space" 
		//        instead of "whehter to put white space at current location"
		string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
		unordered_set<string> dict2 = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
		print(wordBreak(s2, dict2));
	}
}