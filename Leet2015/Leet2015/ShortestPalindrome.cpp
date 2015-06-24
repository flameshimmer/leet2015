#include "stdafx.h"

//Given a string S, you are allowed to convert it to a palindrome by adding characters
//in front of it.Find and return the shortest palindrome you can find by performing this transformation.
//
//For example :
//
//Given "aacecaaa", return "aaacecaaa".
//
//Given "abcd", return "dcbabcd".

namespace Solution1
{

	string shortestPalindrome(string s)
	{
		string rev = s;
		reverse(rev.begin(), rev.end());
		string l = s + "+" + rev;

		vector<int> p(l.size(), 0);
		for (int i = 1; i < l.size(); i++)
		{
			int j = p[i - 1];
			while (j>0 && l[i] != l[j])
			{
				j = p[j - 1];
			}
			if (l[i] == l[j]) { j++; }
			p[i] = j;
		}

		string fr = rev.substr(0, s.size() - p[l.size() - 1]);
		return fr + s;
	}


	void ShortestPalindrome()
	{		
		print(shortestPalindrome("aacecaaa"));
		print(shortestPalindrome("abcd"));
		print(shortestPalindrome("adcba"));
	}
}
