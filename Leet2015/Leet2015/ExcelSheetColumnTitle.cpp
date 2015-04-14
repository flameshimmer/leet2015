#include "stdafx.h"

//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example :
//
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB
//

namespace Solution1
{
	string convertToTitle(int n) 
	{
		string result = "";
		while (n)
		{
			n--;
			result.insert(result.begin(), (n % 26 + 'A'));
			n /= 26;						
		}
		return result;
	}

	void ExcelSheetColumnTitle()
	{
		// Error: note that since the index start with bound 1, we need to do n-- before the assembling.
		print(convertToTitle(2));
		print(convertToTitle(26));
		print(convertToTitle(28));
	}
}