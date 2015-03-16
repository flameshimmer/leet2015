#include "stdafx.h"

//Given a non - negative number represented as an array of digits, plus one to the number.
//
//The digits are stored such that the most significant digit is at the head of the list

namespace Solution1
{
	vector<int> plusOne(vector<int> &digits) 
	{
		int len = digits.size();
		int i = len - 1;
		int carry = 0;
		do
		{
			if (i < 0)
			{ 
				digits.insert(digits.begin(), 1); 
				break;
			}
			carry = (digits[i] + 1) / 10;
			digits[i] = (digits[i] + 1) % 10;
			
			i--;
		} while (carry != 0);
		return digits;
	}

	void PlusOne()
	{
		// Error: forget to return the value
		// Error: recalculated and modified digits[i] before calculating carry. This has result in carry being calculated with incorrect value.
		//        Fix is to calculate the carry first.
		print(plusOne(createVector({ 9 })));
	}
};