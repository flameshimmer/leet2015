#include "stdafx.h"

//Given two binary strings, return their sum(also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".


namespace Solution1
{
	string addBinary(string a, string b) {
		if (a.length() == 0 || b.length() == 0)
		{
			return a.length() != 0 ? a : b;
		}

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int carry = 0;
		int lenA = a.length();
		int lenB = b.length();
		int index = 0;
		string result = "";
		while ((index < lenA && index < lenB) || carry > 0)
		{
			int num1 = index < lenA ? a[index] - '0' : 0;
			int num2 = index < lenB ? b[index] - '0' : 0;
			result.push_back((num1 + num2 + carry) % 2 + '0');
			carry = (num1 + num2 + carry) / 2;
			index++;
		}
		
		if (index < lenA || index < lenB)
		{
			result.append(index < lenA ? a.substr(index) : b.substr(index));
		}
		reverse(result.begin(), result.end());
		return result;
	}

	void AddBinary()
	{
		string result = addBinary("11", "1");
		cout << result.c_str();
	}
}