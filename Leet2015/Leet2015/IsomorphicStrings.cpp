#include "stdafx.h"

//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while
//preserving the order of characters.No two characters may map to the same 
//character but a character may map to itself.
//
//For example,
//Given "egg", "add", return true.
//
//Given "foo", "bar", return false.
//
//Given "paper", "title", return true.
//
//Note:
//You may assume both s and t have the same length.

namespace Solution1
{
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> map;

		int len = s.size();
		if (len == 0) { return true; }
		
		for (int i = 0; i < len; i++)
		{
			char c1 = s[i];
			char c2 = t[i];
			if (map.count(c1) != 0 && map[c1] != c2)
			{
				return false;
			}
			else
			{
				map[c1] = c2;
			}
		}
		unordered_set<char> set;
		for (auto c : map)
		{
			if (set.count(c.second) > 0)
			{
				return false;
			}
			set.insert(c.second);
		}
		return true;
	}

	namespace other
	{
		bool isIsomorphic(string s, string t) {
			int len = s.size();
			if (len < 2) { return true; }

			char mapChar1[256];
			char mapChar2[256];
			memset(mapChar1, '-', sizeof(char) * 256);
			memset(mapChar2, '-', sizeof(bool) * 256);

			for (int i = 0; i < len; i++)
			{
				char c1 = s[i];
				char c2 = t[i];
				if ((mapChar1[c1] != '-' && mapChar1[c1] != c2) || mapChar2[c2] != '-' && mapChar2[c2] != c1)
				{
					return false;
				}
				mapChar1[c1] = c2;
				mapChar2[c2] = c1;
			}
			return true;
		}
	}

	void IsomorphicStrings()
	{
		print(isIsomorphic(string("egg"), string("add")));
		print(isIsomorphic(string("foo"), string("bar")));
		print(isIsomorphic(string("paper"), string("title")));

		print(other::isIsomorphic(string("egg"), string("add")));
		print(other::isIsomorphic(string("foo"), string("bar")));
		print(other::isIsomorphic(string("paper"), string("title")));

		print(other::isIsomorphic(string("ab"), string("aa")));
	}
}