#include "stdafx.h"

//Given two words word1 and word2, find the minimum number of steps required 
//to convert word1 to word2. (each operation is counted as 1 step.)
//
//You have the following 3 operations permitted on a word :
//
//a) Insert a character
//b) Delete a character
//c) Replace a character

namespace Solution1
{
	int minDistance(string word1, string word2) {
		int len1 = word1.length();
		int len2 = word2.length();
		word1 = " " + word1;
		word2 = " " + word2;
		if (len1 == 0 || len2 == 0)
		{
			return ((len1 == 0) ? len2 : len1);
		}

		vector<int>A;
		for (int i = 0; i <= len1; i++)
		{
			A.push_back(i);
		}

		for (int i = 1; i <= len2; i++)
		{
			int matchCost = i-1;
			for (int j = 1; j <= len1; j++)
			{
				int temp = A[j];
				if (word1[j] != word2[i])
				{
					matchCost += 1;
				}
				int prev = 1+ ( (j == 1) ? i : A[j - 1]);
				int cur = A[j] + 1;
				A[j] = min(min(prev, cur), matchCost);
				matchCost = temp;
			}
			print(A);
		}
		return A[len1];
	}

	void EditDistance()
	{
		//print(minDistance(string(""), string("a")));

		// Error: forget to prefix both strings.
		// Error: notice the replacement cost is 1, not 2
		//print(minDistance(string("a"), string("b")));
 
		// Error: need to implement the proper way to get the min out of the three
		//print(minDistance(string("a"), string("ab")));

		// Error: Note that match cost should be += 1, not =1
		//print(minDistance(string("ab"), string("bc")));

		// Error: Note that the match cost for each row start with a different value. It is not always 0
		print(minDistance(string("park"), string("spake")));
	}
};