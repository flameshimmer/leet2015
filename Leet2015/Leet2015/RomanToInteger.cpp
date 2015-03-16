#include "stdafx.h"

//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

//Symbol Value
//I	1
//V	5
//X	10
//L	50
//C	100
//D	500
//M	1000


namespace Solution1
{
	int romanToInt(string s) 
	{
		unordered_map<char, int> myMap;
		myMap['I'] = 1;
		myMap['V'] = 5;
		myMap['X'] = 10;
		myMap['L'] = 50;
		myMap['C'] = 100;
		myMap['D'] = 500;
		myMap['M'] = 1000;

		int len = s.length();
		int result = 0;
		for (int i = 0; i < len; i++)
		{
			if (i + 1 < len)
			{
				if (myMap[s[i]] >= myMap[s[i + 1]])
				{
					result += myMap[s[i]];
				}
				else
				{
					result += myMap[s[i + 1]] - myMap[s[i]];
					i++;
				}
			}
			else
			{
				result += myMap[s[i]];
			}
		}
		return result;
	}

	void RomanToInteger()
	{
		// Error: when come into the case of minus, note that it should be the big - small, which means is the myMap[s[i+1]] - myMap[s[i]]
		//        instead of wise-versa
		// Error: do not process two at a time unless it is the minus case. Otherwise the incorrect partition will result in incorrect result.
		print(romanToInt(string("MCMXCVI")));
	}
}