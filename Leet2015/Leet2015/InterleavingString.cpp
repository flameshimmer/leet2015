#include "stdafx.h"

//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//For example,
//Given:
//s1 = "aabcc",
//s2 = "dbbca",
//
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false.


namespace Solution1
{
	bool isInterleave(string s1, string s2, string s3) 
	{
		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();

		if (len3 != len1 + len2) { return false; }
		if (len1 == 0) { return s2 == s3; }
		if (len2 == 0) { return s1 == s3; }

		vector<bool>M(len2 + 1, false);
		M[0] = true;
		// init array for len1 == 0 case	
		for (int i = 1; i < len2+1; i++)
		{
			M[i] = M[i - 1] && (s2[i-1] == s3[i-1]);			
		}
		// start looping
		for (int i = 1; i < len1 + 1; i++)
		{
			M[0] = M[0] && (s1[i-1] == s3[i-1]);
			for (int j = 1; j < len2 + 1; j++)
			{
				bool b1 = s3[i + j-1] == s2[j-1];
				bool b2 = M[j - 1];
				bool b3 = s3[i + j-1] == s1[i-1];
				bool b4 = M[j];
				M[j] = ( b1 && b2) || (b3 && b4);
			}
		}
		return M[len2];
	}
	void InterleavingString()
	{
		print(isInterleave(string("aa"), string("ab"), string("abaa")));
	}
}




