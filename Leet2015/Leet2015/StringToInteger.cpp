#include "stdafx.h"

//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases.If you want a challenge, 
//	  please do not see below and ask yourself what are the possible input cases.
//
//  Notes : It is intended for this problem to be specified vaguely
//		  (ie, no given input specs).You are responsible to gather all the input requirements up front.
//
//		  Update(2015 - 02 - 10) :
//		  The signature of the C++ function had been updated.
//		  If you still see your function signature accepts a const char * argument, 
//		  please click the reload button  to reset your code definition.

//Requirements for atoi:
//The function first discards as many whitespace characters as necessary 
//until the first non - whitespace character is found.Then, starting from this character, 
//takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
//and interprets them as a numerical value.
//
//The string can contain additional characters after those that form the integral number, 
//which are ignored and have no effect on the behavior of this function.
//
//If the first sequence of non - whitespace characters in str is not a valid integral number, 
//or if no such sequence exists because either str is empty or it contains only whitespace 
//characters, no conversion is performed.
//
//If no valid conversion could be performed, a zero value is returned.If the correct value
//is out of the range of representable values, INT_MAX(2147483647) or INT_MIN(-2147483648) is returned.

namespace Solution1
{

	int atoi(string str) {
		int len = str.length();
		if (len == 0 ) { return 0; }
		if (len == 1 && str[0] == '-'){ return 0; }

		bool isNeg = false;
		int start = 0;
		while (str[start] == ' ') { start++; }
		if (str[start] == '-') { isNeg = true; start++; }
		else if (str[start] == '+'){ isNeg = false; start++; }
		

		int result = 0;
		for (int i = start; i < len; i++)
		{
			int num = str[i] - '0';
			if (num < 0 || num > 9) { break; }
			if (!isNeg && ((INT_MAX - num) / 10 < result))
			{
				return INT_MAX;
			}
			else if (isNeg && ((INT_MIN + num) / -10 < result))
			{
				return INT_MIN;
			}
			else
			{
				result = result * 10 + num;
			}			
		}
		if (isNeg) { result *= -1; }
		return result;		
	}

	void StringToInteger()
	{
	
	}

}