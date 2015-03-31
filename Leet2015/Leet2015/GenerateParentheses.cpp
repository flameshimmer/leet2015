#include "stdafx.h"

//Given n pairs of parentheses, write a function to 
//generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//"((()))", "(()())", "(())()", "()(())", "()()()"

namespace Solution1
{
	void recurse(int maxCount, int leftCount, int rightCount, string& result, vector<string>& results)
	{
		if (leftCount == maxCount && rightCount == maxCount)
		{
			results.push_back(result);
			return;
		}

		if (leftCount < maxCount)
		{
			result.push_back('(');
			recurse(maxCount, leftCount + 1, rightCount, result, results);
			result.pop_back();
		}

		if (rightCount < maxCount && rightCount < leftCount)
		{
			result.push_back(')');
			recurse(maxCount, leftCount, rightCount + 1, result, results);
			result.pop_back();
		}
	}
	
	vector<string> generateParenthesis(int n) 
	{
		vector<string> results;
		if (n == 0) { return results; }
		string result;
		recurse(n, 0, 0, result, results);
		return results;
	}

	void GenerateParentheses()
	{
		print(generateParenthesis(3));
	}
}