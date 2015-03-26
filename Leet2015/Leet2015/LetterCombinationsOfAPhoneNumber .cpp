#include "stdafx.h"

//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters(just like on the telephone buttons) is given below.
//
//2-> a, b, c
//3-> d, e, f
//4-> g, h, i
//5 -> j, k, l
//6 -> m, n, o
//7-> p, q, r, s
//8-> t, u, v
//9-> w, x, y, z
//
//Input:Digit string "23"
//  Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//	   Note :
//			Although the above answer is in lexicographical order, your answer could be in any order you want.
//
namespace Solution1
{
	void recurse(string digits, string map[], int level, int maxLevel, string result, vector<string>& results)
	{
		if (level == maxLevel)
		{
			results.push_back(result);
			return;
		}

		char c = digits[level];
		string candidates = map[c - '2'];
		for (char c : candidates)
		{
			recurse(digits, map, level + 1, maxLevel, result + c, results);
		}
	}
	
	vector<string> letterCombinations(string digits) {
		string map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

		vector<string> results;
		if (digits.empty()) { return results; }

		string result;
		recurse(digits, map, 0, digits.length(), result, results);
		return results;
	}

	void LetterCombinationsOfAPhoneNumber()
	{
		// Note: using string[] to store candidate string has a much better run time than using unordered_map
		// Error: forget to return once detected the level is equal to maxLevel
		print(letterCombinations(string("23")));
	}
}