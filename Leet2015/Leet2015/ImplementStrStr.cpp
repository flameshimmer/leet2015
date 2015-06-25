#include "stdafx.h"

//Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack, 
//or - 1 if needle is not part of haystack.

namespace Solution1
{
	namespace old
	{
		vector<int> calcNextTable(string p)
		{
			//int len = p.length();
			//vector<int> next(len, -1);
			//
			//int j = -1;
			//for (int i = 1; i < len; i++)
			//{
			//	while (j >= 0 && p[i] != p[j + 1])
			//	{
			//		j = next[j];
			//	}
			//	if (p[i] == p[j + 1]) { j++; }
			//	next[i] = j;
			//}
			//return next;

			int len = p.length();
			vector<int> next(len, -1);
			int j = -1;
			for (int i = 1; i < len; i++)
			{
				while (j >= 0 && p[i] != p[j + 1])
				{
					j = next[j];
				}
				if (p[i] == p[j + 1]) { j++; }
				next[i] = j;
			}
			return next;
		}

		int strStr(string haystack, string needle)
		{
			/*vector<int> next = calcNextTable(needle);
			int lenh = haystack.length();
			int lenn = needle.length();
			if (lenn == 0) { return 0; }

			int j = -1;
			for (int i = 0; i < lenh; i++)
			{
			while (j >= 0 && haystack[i] != needle[j + 1])
			{
			j = next[j];
			}
			if (haystack[i] == needle[j + 1])
			{
			j++;
			}
			if (j == lenn - 1)
			{
			return (i - lenn + 1);
			}
			}
			return -1;*/

			vector<int> next = calcNextTable(needle);
			int lenh = haystack.length();
			int lenn = needle.length();
			if (lenn == 0) { return 0; }

			int j = -1;
			for (int i = 0; i < lenh; i++)
			{
				while (j >= 0 && haystack[i] != needle[j + 1])
				{
					j = next[j];
				}
				if (haystack[i] == needle[j + 1]) 
				{ 
					j++; 
				}
				if (j + 1 == lenn)
				{
					return (i - lenn + 1);
				}
			}
			return -1;
		}
	}


	vector<int> calcNextTable(string p)
	{
		int len = p.length();
		vector<int> next(len, 0);
		for (int i = 1; i < len; i++)
		{
			int j = next[i - 1];
			while (j>0 && p[i] != p[j])
			{
				j = next[j - 1];
			}
			if (p[i] == p[j]){ j++; }
			next[i] = j;
		}
		return next;
	}

	int strStr(string haystack, string needle)
	{
		int lenn = needle.length();
		if (lenn == 0) { return 0; }
		
		int lenh = haystack.length();
		vector<int> next = calcNextTable(needle);


		int i = 0;
		int j = 0;
		while (i<lenh && j<lenn)
		{
			while (j > 0 && haystack[i] != needle[j])
			{
				j = next[j-1];
			}
			if (haystack[i] == needle[j])
			{			
				j++;
			}
			i++;
		}
		
		if (j == lenn)
		{
			return i - lenn;
		}

		return -1;
	}


	void ImplementStrStr()
	{
		string pattern = "issip";
		print(pattern);
		print(old::calcNextTable(pattern));
		print(calcNextTable(pattern));

		//print(strStr("aaa", "a"));
		print(strStr("mississippi", "issip"));
		
		print(strStr("mississippi", "a"));
		// Error: note that calcNextTable should return empty array when the pattern string is empty
		print(strStr("", ""));
	}
}