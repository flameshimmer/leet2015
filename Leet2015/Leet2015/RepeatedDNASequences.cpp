#include "stdafx.h"

//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
//for example: "ACGAATTCCG".When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//Write a function to find all the 10 - letter - long sequences(substrings) that occur more than once in a DNA molecule.
//
//For example,
//
//Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//
//Return:
//["AAAAACCCCC", "CCCCCAAAAA"].

namespace Solution1
{
	vector<string> findRepeatedDnaSequences(string s)
	{
		int len = s.size();
		vector<string> result;
		if (len < 11) { return result; }
		unordered_map<int, int> map;

		int cur = 0;
		for (int i = 0; i < 10; i++)
		{
			cur <<= 3;
			cur |= s[i] & 7;
		}
		map[cur] = 1;
		for (int i = 1; i <=len - 10; i++)
		{
			cur &= 0x07FFFFFF;
			cur <<= 3;
			cur |= s[i+9] & 7;

			if (map[cur] == 1)
			{
				result.push_back(s.substr(i,10));
				
			}
			map[cur]++;
		}
		return result;
	}

	namespace MemoryLimitExceeded{
		vector<string> findRepeatedDnaSequences(string s)
		{
			int len = s.size();
			vector<string> result;
			if (len < 20) { return result; }
			unordered_set<string> set;

			for (int i = 0; i <= len - 1 - 10; i++)
			{
				string str = s.substr(i, 10);
				if (set.find(str) == set.end())
				{
					set.insert(str);
				}
				else
				{
					result.push_back(str);
				}
			}
			return result;
		}
	}
	void RepeatedDNASequences()
	{
		//print(findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
		//print(findRepeatedDnaSequences("AAAAAAAAAAA"));
		print(findRepeatedDnaSequences("AAAAAAAAAAAA"));
	}
}