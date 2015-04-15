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
	bool match(string S, string L)
	{
		int lenL = L.size();
		int lenS = S.size();
		if (lenL > lenS) { return false; }
		int cur = 0;
		while (cur < lenL)
		{
			if (S[cur] != L[cur]){ return false; }
			cur++;
		}
		return true;
	}
	bool hasNoCandidates(vector<int>& candidates)
	{
		for (int i : candidates)
		{
			if (i != 0){ return false; }
		}
		return true;
	}
	void recurse(string S, int start, vector<string>& L, vector<int>& candidates, vector<int>& result)
	{
		if (hasNoCandidates(candidates))
		{
			result.push_back(start);
			return;
		}
		for (int i = 0; i < candidates.size(); i++)
		{
			if (candidates[i] == 1 && match(S, L[i]))
			{
				candidates[i] = 0;
				recurse(S, L[i].size(), L, candidates, result);
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
			recurse(S, i, L, candidates, result);

		}
		
		return result;
	}
	void SubstringWithConcatenationOfAllWords()
	{
		vector<string> L = { "foo", "bar" };
		print(findSubstring(string("barfoothefoobarman"), L));
	}
}