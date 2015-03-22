#include "stdafx.h"

//A message containing letters from A - Z is being encoded to numbers using the following mapping :
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given an encoded message containing digits, determine the total number of ways to decode it.
//
//For example,
//Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//The number of ways decoding "12" is 2.

namespace Solution1
{
	int numDecodings(string s) {
		int len = s.length();
		if (len == 0 || s[0] == '0') { return 0; }

		vector<int>A(len+1, 0);
		A[0] = 1;
		A[1] = 1;

		for (int i = 2; i < len+1; i++)
		{
			if (s[i - 1] != '0')
			{
				A[i] = A[i - 1];
			}
			bool lastTwoCanMakeSense = (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] - '0' <= 6));
			if (i >= 2 && lastTwoCanMakeSense)
			{
				A[i] += A[i - 2];
			}
		}
		return A[len];
	}

	void DecodeWays()
	{		
		// Error: Special case "0", "10", "101". Basic rule is f(n-1) (when s[i] is not '0') + f(n-2) (when the last two digit can be legit)
		//        The key part is forgetting 0 does not corresponding to any letter by itself. 
		// Error: Note that the processing start with when the input has at least two character, this means we need to specially process when
		//        the input is "0", because all of the following calc would expect the first char is not '0'
		print(numDecodings(string("12")));
		print(numDecodings(string("10")));
		print(numDecodings(string("101")));
	}
}