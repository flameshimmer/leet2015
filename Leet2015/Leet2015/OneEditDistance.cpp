#include "stdafx.h"

//Given two strings S and T, determine if they are both one edit distance apart.
//Replacement cost is counted as 1

namespace Solution1
{
	bool isOneEditDistance(string s, string t)
	{		
		if (s.length() < t.length())
		{
			swap(s, t);
		}

		int lens = s.length();
		int lent = t.length();
		if (lens - lent > 1) { return false; }

		int i = 0; int j = 0;
		int seenDiff = false;
		while (i < lens && j < lent)
		{
			if (s[i] != t[j])
			{
				if (seenDiff) { return false; }
				seenDiff = true;
				if (lens != lent)
				{
					j--;
				}
			}
			i++; 
			j++;
		}
		return seenDiff || lens != lent;
	}
	
	void OneEditDistance()
	{
		print(isOneEditDistance("a", "ba"));
		print(isOneEditDistance("c", "c"));
		print(isOneEditDistance("", "A"));
		print(isOneEditDistance("a", ""));
		print(isOneEditDistance("teacher", "detacher"));
		print(isOneEditDistance("", ""));
	}
}