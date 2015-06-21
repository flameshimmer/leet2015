#include "stdafx.h"

//Given a string S and a string T, count the number of distinct subsequences of T in S.
//
//A subsequence of a string is a new string which is formed from the original string by
//deleting some(can be none) of the characters without disturbing the relative positions
//of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//Here is an example :
//S = "rabbbit", T = "rabbit"
//
//Return 3.

namespace Solution1
{
	int numDistinct(string s, string t) {
		int lens = s.size();
		int lent = t.size();
		if (lens < lent) { return 0; }

		vector<int>M(lent+1, 0);
		M[0] = 1;
		for (int j = 1; j <= lens; j++)
		{
			for (int i = lent; i >= 1; i--)
			{
				if (t[i-1] == s[j-1])
				{
					M[i] += M[i - 1];
				}
			}
		}
		return M[lent];
	}

	void DistinctSubsequences()
	{
		print(numDistinct("rabbbit", "rabbit"));
	}
}