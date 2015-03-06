#include "stdafx.h"

//Given an array of strings, return all groups of strings that are anagrams.
//
//Note: All inputs will be in lower - case.


namespace Solution1
{
	/// abc, cab, aaa, bbb
	vector<string> anagrams(vector<string> &strs) {
		vector<string> result;
		int len = strs.size();
		if (len == 0) { return result; }

		unordered_map<string, vector<string>> map;
		for (string str : strs)
		{
			string key = str;
			sort(key.begin(), key.end());
			if (map.count(key) > 0)
			{
				map[key].push_back(str);
			}
			else
			{
				vector<string> content;
				content.push_back(str);
				map[key] = content;
			}			
		}

		for (auto it = map.begin(); it != map.end(); it++)
		{
			vector<string> content = it->second;
			if (content.size() > 1)
			{
				result.insert(result.end(), content.begin(), content.end());
			}
		}
		return result;
	}

	void Anagrams()
	{
		
		vector<string> input = createVector({ string("aaa"), string("bbb"), string("abc"), string("cba") });
		print(anagrams(input));
	}
};