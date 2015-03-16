#include "stdafx.h"

//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.
//
//Symbols are placed from left to right in order of value, starting with the largest.However, 
// in a few specific cases, [2] to avoid four characters being repeated in succession(such as IIII or XXXX)
// these can be reduced using subtractive notation as follows : [3][4]
//
//the numeral I can be placed before V and X to make 4 units(IV) and 9 units(IX) respectively
//X can be placed before L and C to make 40 (XL)and 90 (XC)respectively
//C can be placed before D and M to make 400 (CD)and 900 (CM)according to the same pattern[5]
//
//An example using the above rules would be 1904 : this is composed of 1 (one thousand), 
//9 (nine hundreds), 0 (zero tens), and 4 (four units).To write the Roman numeral, each of the non-zero 
// digits should be treated separately.Thus 1, 000 = M, 900 = CM, and 4 = IV.Therefore, 1904 is MCMIV.
//
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
	string intToRoman(int num) 
	{
		unordered_map<int, string> myMap;
		myMap[1] = "I";
		myMap[5] = "V";
		myMap[10] = "X";
		myMap[50] = "L";
		myMap[100] = "C";
		myMap[500] = "D";
		myMap[1000] = "M";
		myMap[4] = "IV";
		myMap[9] = "IX";
		myMap[40] = "XL";
		myMap[90] = "XC";
		myMap[400] = "CD";
		myMap[900] = "CM";
		
		int divider[7] = { 1000, 500, 100, 50, 10, 5, 1 };
		int remainder[6] = { 900, 400, 90, 40, 9, 4 };
		string result = "";
		
		for (int i = 0; i < 7; i++)
		{
			int div = divider[i];
			if (num >= div)
			{
				int count = num / div;
				num %= div;
				for (int i = 0; i < count; i++) { result += myMap[div]; }
			}
			
			if (i < 6 && num / remainder[i] == 1)
			{
				result += myMap[remainder[i]];
				num -= remainder[i];
			}
		}
		return result;
	}

	void IntegerToRoman()
	{
		print(intToRoman(1904));
		print(intToRoman(1));
		
		// Error: when checking the special case, only check with the current i instead of all possible case.
		print(intToRoman(5));
	}
};