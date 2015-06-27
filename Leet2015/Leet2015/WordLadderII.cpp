#include "stdafx.h"

//Given two words(start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that :
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary
//For example,
//
//Given :
//	  start = "hit"
//	  end = "cog"
//	  dict = ["hot", "dot", "dog", "lot", "log"]
//	  Return
//	  [
//		  ["hit", "hot", "dot", "dog", "cog"],
//		  ["hit", "hot", "lot", "log", "cog"]
//	  ]
//Note:
//All words have the same length.
//All words contain only lowercase alphabetic characters.

namespace Solution1
{
	vector<string> getChildren(unordered_set<string>& dict, string target)
	{
		vector<string> result;

		for (int i = 0; i < target.length(); i++)
		{
			string cur = target;
			char c = target[i];
			for (int j = 0; j < 26; j++)
			{
				char n = j + 'a';
				if (n != c)
				{
					cur[i] = n;
					if (dict.find(cur) != dict.end())
					{
						result.push_back(cur);
					}
				}				
			}
			cur[i] = c;
		}
		return result;
	}


	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordDict)
	{
		vector<vector<string>> results;
		wordDict.insert(beginWord);
		wordDict.insert(endWord);
		
		queue<string> q;
		q.push(beginWord);
		while (!q.empty())
		{
			string cur = q.front();
			vector<string>
		}

		return results;
	}

	void WordLadderII()
	{

	}
}