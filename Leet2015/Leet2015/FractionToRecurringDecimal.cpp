#include "stdafx.h"

//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
//If the fractional part is repeating, enclose the repeating part in parentheses.
//
//For example,
//
//Given numerator = 1, denominator = 2, return "0.5".
//Given numerator = 2, denominator = 1, return "2".
//Given numerator = 2, denominator = 3, return "0.(6)".

namespace Solution1
{
	string fractionToDecimal(int numerator, int denominator) 
	{
		if (numerator == 0) { return "0"; }

		unordered_map<int, int> map;
		vector<int> prevNumverator;
		string result = "";
		bool isNeg = (numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0);
		
		// Overflow prevention
		long long curNumerator = numerator;
		if (curNumerator < 0) { curNumerator *= -1; }
		long long curDenominator = denominator;
		if (curDenominator < 0) { curDenominator *= -1; }

		bool hasDot = false;
		while (1)
		{						
			if (map.find(curNumerator) == map.end())
			{				
				prevNumverator.push_back(curNumerator);
				long long curVal = (long long)curNumerator / (long long)curDenominator;
				// Remember the index. This will be the location to insert '(' if necessary
				map[curNumerator] = result.size();
				result += to_string(curVal);				
				curNumerator = curNumerator % curDenominator * 10;
				if (curNumerator == 0) { break; }
				if (!hasDot)
				{
					result += ".";
					hasDot = true;
				}
			}
			else
			{
				int index = map[curNumerator];
				result.insert(result.begin() + index, '(');
				result.push_back(')');
				break;
			}	
		}
		return isNeg ? "-" + result : result;
	}

	void FractionToRecurringDecimal()
	{
		print(fractionToDecimal(1, 2));
		print(fractionToDecimal(2, 1));
		print(fractionToDecimal(2, 3));
		print(fractionToDecimal(22, 7));
		print(fractionToDecimal(INT_MIN, -1));
	}
}