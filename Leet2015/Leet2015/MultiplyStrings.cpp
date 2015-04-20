#include "stdafx.h"

//Given two numbers represented as strings, 
//return multiplication of the numbers as a string.
//
//Note: The numbers can be arbitrarily large and are non - negative.

namespace Solution1
{
	string add(string num1, string num2)
	{
		int len1 = num1.length();
		int len2 = num2.length();
		
		if (len1 == 0 || len2 == 0) { return len1 == 0 ? num2 : num1; }

		len1--;
		len2--;
		int carry = 0;
		string result;
		while (len1 >=0 || len2 >= 0 || carry > 0)
		{
			int val1 = (len1 >= 0) ? num1[len1] - '0' : 0;
			int val2 = (len2 >= 0) ? num2[len2] - '0' : 0;
			int val = val1 + val2 + carry;
			result.insert(result.begin(), (val % 10) + '0');
			carry = val / 10;
			len1--;
			len2--;
		}
		return result;
	}

	string multiply(string num1, string num2) 
	{
		string result;
		int len1 = num1.length();
		int len2 = num2.length();

		for (int i = len2-1; i >=0; i--)
		{
			int carry = 0;
			string curResult;
			int d2 = num2[i] - '0';
			for (int j = len1 - 1; j >= 0; j--)
			{
				int d1 = num1[j] - '0';
				int val = (d1 * d2 + carry);
				curResult.insert(curResult.begin(), val % 10 + '0');
				carry = val / 10;
			}
			if (carry > 0)
			{
				curResult.insert(curResult.begin(), carry + '0');
			}
			// pad 0
			int padCount = len2 - 1 - i;
			while (padCount > 0)
			{
				curResult.push_back('0');
				padCount--;
			}
	
			// get rid of the prefix 0 for curResult;
			int k = 0;
			while (k < curResult.length())
			{
				if (curResult[k] != '0')
				{
					break;
				}
				k++;
			}
			if (k == curResult.length()) 
			{ 
				curResult = "0"; 
			}
			else{ 
				curResult = curResult.substr(k, curResult.length() - k); 
			}

			// add curResult to result
			result = add(result, curResult);
		}
		return result;
	}

	void MultiplyStrings()
	{
		// Error: notice in the case of "0", need to get rid of the prefix "0"s, instead of going through normal calculation and get "0000"
		// Note: when use string to do the big number calculation, remember to get rid of the prefix 0s
		print(multiply(string("9133"), string("0")));
		print(multiply(string("12"), string("34")));
		print(multiply(string("99"), string("78")));		
	}
}