#include "stdafx.h"

//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//
//The matching should cover the entire input string(not partial).
//
//The function prototype should be :
//bool isMatch(const char *s, const char *p)
//
//Some examples :
//isMatch("aa", "a") → false
//isMatch("aa", "aa") → true
//isMatch("aaa", "aa") → false
//isMatch("aa", "a*") → true
//isMatch("aa", ".*") → true
//isMatch("ab", ".*") → true
//isMatch("aab", "c*a*b") → true

namespace Solution1
{
	bool matches(const char* s, const char* p)
	{
		return (*s == *p) || (*s != '\0' && *p == '.');
	}

	bool isMatch(const char *s, const char *p) {
		if (*p == '\0') { return *s == '\0'; }

		if (p[1] != '*')
		{
			return matches(s, p) && isMatch(s + 1, p + 1);
		}

		while (matches(s, p))
		{
			if (isMatch(s, p + 2)) { return true; }
			s++;
		}
		return isMatch(s, p + 2);
	}

	bool matches(char a, char b)
	{
		return (a == b || a == '.' || b == '.');
	}

	bool isMatchDP(const char* s, const char* p)
	{
		int lens = strlen(s);
		int lenp = strlen(p);
		vector<vector<bool>> F(lens + 1, vector<bool>(lenp + 1, false));

		F[0][0] = true;

		for (int i = 0; i < lens + 1; i++)
		{
			for (int j = 1; j < lenp + 1; j++)
			{
				if (i>= 1 && matches(s[i-1], p[j-1]) && F[i - 1][j - 1])
				{
					F[i][j] = true;
					continue;
				}
				if (i>= 1 && j>=2 && (p[j - 1] == '*' && matches(s[i - 1], p[j - 2])) && F[i - 1][j]) // Match 1+ with *
				{
					F[i][j] = true;
					continue;
				}
				if (j>=2 && p[j - 1] == '*' && F[i][j - 2]) // Match none with *
				{
					F[i][j] = true;
					continue;
				}
			}
		}
		return F[lens][lenp];
	}

	void RegularExpressionMatching()
	{
		// Error: test whether end of the string, use (*s == '\0') insteat of !s
		// Error: prevent s goes outside of null termniation
		string s = "bbbba";
		string p = ".*a*a";
		//print(isMatchDP(s.c_str(), p.c_str()));
 
		s = "aa";
		p = "a*";
		//print(isMatchDP(s.c_str(), p.c_str()));

		s = "aab";
		p = "c*a*b";
		print(isMatchDP(s.c_str(), p.c_str()));

	}
};