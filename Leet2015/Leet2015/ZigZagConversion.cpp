#include "stdafx.h"

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
//like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line : "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows :
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

namespace Solution1
{
	//1 3 5
	//2 4 6
	
	//1   5    9    13
	//2 4 6 8 10 12 14
	//3   7   11    15

	//1    7      13      19
	//2	 6 8   12 14   18 20
	//3	5  9 11   15 17   21
	//4    10     16      22

	//1     9         17        24
	//2	  8 10     16 18     23 25
	//3	 7  11   15   19   22   26
	//4 6   12 14     20 22     27
	//5     13        21        28


	string convert(string s, int nRows) {
		if (nRows == 0) { return ""; }
		if (nRows == 1) { return s; }
		string result = "";
		int len = s.length();
		int distanceOnFirstAndLastRow = (nRows - 1) * 2;
		for (int i = 1; i <= nRows; i++)
		{
			int curValue = i;
			// first and last row
			if (i == 1 || i == nRows)
			{				
				while (curValue <= len)
				{
					result.push_back(s[curValue-1]);
					curValue += distanceOnFirstAndLastRow;
				}
			}
			else
			{
				bool isLeftTurn = true;
				int distanceLeft = distanceOnFirstAndLastRow - 2 * (i-1);
				int distanceRight = distanceOnFirstAndLastRow - distanceLeft;
				while (curValue <= len)
				{
					result.push_back(s[curValue-1]);
					curValue += isLeftTurn ? distanceLeft : distanceRight;
					isLeftTurn = !isLeftTurn;
				}
			}
		}		
		return result;
	}

	void ZigZagConversion()
	{
		// Error: did not notice the nRows == 1 condition, in which case infinite loop appears
		// Error: note that the distanceLeft should be calculated with i-1, instead of i
		// Error: note that the result should be pushed with s[index], instead of the index itself
		print(convert(string("123456"), 1));
		print(convert(string("123456"), 2));
		print(convert(string("123456789"), 3));
		print(convert(string("PAYPALISHIRING"), 3));
	}
};