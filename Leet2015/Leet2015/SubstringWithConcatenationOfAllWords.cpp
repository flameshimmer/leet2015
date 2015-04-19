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
	
	
	vector<int> findSubstring(string S, vector<string> &L)
	{
		vector<int> result;
		unordered_map<string, bool> dict;
		for (string s : L)
		{
			dict[s] = true;
		}
		int Slen = S.length();
		int len = L[0].length();

		int start = 0;
		int dictSize = L.size();
		int filledSize = 0;
		while (start < Slen - len)
		{
			int cur = start;

			string curStr = S.substr(cur, len);
			if (dict.count(curStr) > 0 && dict[curStr] == true)
			{
				dict[curStr] = false;
				filledSize++;
				if (filledSize == dictSize)
				{
					result.push_back(start);
					filledSize = 0;
					start++;
					for (auto r : dict)
					{
						r.second = true;
					}
				}
				else
				{
					cur += len;
				}				
			}
			else
			{
				for (auto r : dict)
				{
					r.second = true;
				}
				start++;
				filledSize = 0;
			}
		}
		return result;
	}
	
	
	namespace recursive{
		bool match(string S, int start, string L)
		{
			int lenL = L.size();
			int lenS = S.size() - start;
			if (lenL > lenS) { return false; }
			int cur = 0;
			while (cur < lenL)
			{
				if (S[start + cur] != L[cur]){ return false; }
				cur++;
			}
			return true;
		}
		bool hasNoCandidates(vector<int>& candidates)
		{
			for (int i : candidates)
			{
				if (i == 1){ return false; }
			}
			return true;
		}
		void recurse(string S, int start, int curStart, vector<string>& L, vector<int>& candidates, vector<int>& result)
		{
			if (hasNoCandidates(candidates))
			{
				result.push_back(start);
				return;
			}
			for (int i = 0; i < candidates.size(); i++)
			{
				if (candidates[i] == 1 && match(S, curStart, L[i]))
				{
					candidates[i] = 0;
					recurse(S, start, curStart + L[i].size(), L, candidates, result);
					candidates[i] = 1;
				}
			}
		}
		vector<int> findSubstring(string S, vector<string> &L)
		{
			vector<int> result;
			vector<int> candidates(L.size(), 1);
			for (int i = 0; i < S.size(); i++)
			{
				recurse(S, i, i, L, candidates, result);
			}

			return result;
		}
	}

	void SubstringWithConcatenationOfAllWords()
	{
		vector<string> L = { "foo", "bar" };
		print(findSubstring(string("barfoothefoobarman"), L));

		using namespace recursive;
		//print(recursive::findSubstring(string("barfoothefoobarman"), L));
	}
}