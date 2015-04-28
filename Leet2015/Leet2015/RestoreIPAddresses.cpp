#include "stdafx.h"

//Given a string containing only digits, restore it by returning 
//all possible valid IP address combinations.
//
//For example :
//Given "25525511135",
//
//return["255.255.11.135", "255.255.111.35"]. (Order does not matter)

namespace Solution1
{
	bool isValidSubString(string& s)
	{
		if (s.length() > 1 && s[0] == '0') { return false; }

		int val = 0;		
		for (char c : s)
		{
			val = val * 10 + c - '0';
			if (val > 255) { return false; }
		}
		return true;
	}
	void getIp(string s, int start, int len, int level, int maxLevel, string result, vector<string>& set)
	{		
		if (level == maxLevel && start == len)
		{
			set.push_back(result);
			return;
		}

		if (len - start < maxLevel - level || len - start > 3 * (maxLevel - level) || level == maxLevel)
		{
			return;
		}

		for (int i = start; i < len; i++)
		{
			string cur = s.substr(start, i - start + 1);
			if (isValidSubString(cur))
			{
				string newResult = result +  ((result == "") ? cur : "." + cur);
				getIp(s, i + 1, len, level + 1, maxLevel, newResult, set);
			}
		}
	}
	vector<string> restoreIpAddresses(string s) 
	{
		int len = s.length();
		vector<string> results;
		if (len < 4 || len > 12)
		{
			return results;
		}
		string result;
		unordered_set<string> set;
		getIp(s, 0, s.length(), 0, 4, result, results);
		return results;
	}

	void RestoreIPAddresses()
	{
		//print(restoreIpAddresses(string("25525511135")));
		print(restoreIpAddresses(string("010010")));
	}
}