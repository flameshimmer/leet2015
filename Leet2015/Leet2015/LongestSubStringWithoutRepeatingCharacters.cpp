#include "stdafx.h"


//Given a string, find the length of the longest substring without repeating characters.
//For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
//which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

namespace Solution1
{
	int lengthOfLongestSubstring(string s) 
	{
		int len = s.length();
		if (len < 2) { return len; }

		int longest = 0;
		int start = 0;
		unordered_map<char, int> map;
		for (int end = 0; end < len; end++)
		{
			if (map.count(s[end]) == 0)
			{
				map[s[end]] = 1;
			}
			else
			{
				longest = max(longest, (end - 1) - start + 1);
				while (s[start] != s[end])
				{
					//map[s[start]] = 0;
					map.erase(s[start]);
					start++;
				}
				start++;
				map[s[end]] = 1;
			}
		}
		if (start < len)
		{
			longest = max(longest, len - 1 - start + 1);
		}
		return longest;
	}

	void LongestSubStringWithoutRepeatingCharacters()
	{
		// Error: did not put the first character into the map. The end index should start with 0
		//print(lengthOfLongestSubstring(string("abcabcbb")));
		//print(lengthOfLongestSubstring(string("bbbbb")));
		//print(lengthOfLongestSubstring(string("au")));
		
		// Error: should use unordered_map's erase function to get rid of a entry, instead of just setting the value to be 0.
		// map.count is still 1 if the value of the slot is 0. 
		// so to check entry exist use count. to get rid of an entry use erase.
		print(lengthOfLongestSubstring(string("tmmzuxt")));
	}
}