#include "stdafx.h"

//Given two strings S and T, determine if they are both one edit distance apart.

namespace Solution1
{
	bool isOneEditDistance(string s, string t) 
	{
		int lens = s.length();
		int lent = t.length();

		if (lens - lent > 1 || lens - lent < -1) { return false; }
		
		string longer = lens > lent ? s : t;
		string shorter = lens > lent ? t : s;
		int len = lens > lent ? lent : lens;

		for (int i = 0; i < len; i++)
		{
			if (s[i] != )
		}
	}
	
	void OneEditDistance()
	{
		print(isOneEditDistance("teacher", "detacher"));
	}
}