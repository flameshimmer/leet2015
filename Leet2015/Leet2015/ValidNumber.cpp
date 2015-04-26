#include "stdafx.h"

//Validate if a given string is numeric.
//
//Some examples :
//"0" = > true
//" 0.1 " = > true
//"abc" = > false
//"1 a" = > false
//"2e10" = > true
//Note: It is intended for the problem statement to be ambiguous.
//You should gather all requirements up front before implementing one.

namespace Solution1
{
	bool isNumber(string s) 
	{
		enum InputType
		{
			Invalid, // 0s
			Space, // 1
			Sign, // 2
			Digit, //3
			Dot, //4
			E //5
		};
		enum State
		{
			EmptyOrSpace, // 0
			AfterSign, // 1
			AfterDigit, // 2
			AfterDigitDot, //3
			SignAfterE, //4
			AfterE, //5
			DigitAfterDot, //6
			DigitAfterE, //7
			SpaceAfter, //8
			AfterDot //9
		};
		vector<vector<int>> stateTable(10, vector<int>(6, -1));
		stateTable[EmptyOrSpace][Space] = EmptyOrSpace;
		stateTable[EmptyOrSpace][Sign] = AfterSign;
		stateTable[EmptyOrSpace][Digit] = AfterDigit;
		stateTable[EmptyOrSpace][Dot] = AfterDot;
		stateTable[AfterDot][Digit] = DigitAfterDot;

		stateTable[AfterSign][Digit] = AfterDigit;
		stateTable[AfterSign][Dot] = AfterDot;
		stateTable[AfterDigit][Dot] = AfterDigitDot;
		stateTable[AfterDigit][Digit] = AfterDigit;
		stateTable[AfterDigit][Space] = SpaceAfter;
		stateTable[AfterDigitDot][Digit] = DigitAfterDot;
		stateTable[AfterDigitDot][Space] = SpaceAfter;
		stateTable[AfterDigitDot][E] = AfterE;
		stateTable[AfterDigit][E] = AfterE;
		stateTable[DigitAfterDot][E] = AfterE;
		stateTable[DigitAfterDot][Digit] = DigitAfterDot;
		stateTable[DigitAfterDot][Space] = SpaceAfter;

		stateTable[AfterE][Sign] = SignAfterE;
		stateTable[AfterE][Digit] = DigitAfterE;
		stateTable[SignAfterE][Digit] = DigitAfterE;
		stateTable[SignAfterE][Space] = SpaceAfter;

		stateTable[DigitAfterE][Digit] = DigitAfterE;
		stateTable[DigitAfterE][Space] = SpaceAfter;
		stateTable[SpaceAfter][Space] = SpaceAfter;

		int state = EmptyOrSpace;
		
		for (char c : s)
		{
			int input = Invalid;
			if (c == ' '){ input = Space; }
			if (c == '+' || c == '-') { input = Sign; }
			if (c >= '0' && c <= '9') { input = Digit; }
			if (c == '.'){ input = Dot; }
			if (c == 'E' || c == 'e') { input = E; }

			state = stateTable[state][input];
			if (state == -1) { return false; }
		}
		return state == AfterDigit || state == AfterDigitDot || state == DigitAfterDot || state == DigitAfterE || state == SpaceAfter;
	}

	void ValidNumber()
	{
		print(isNumber("46.e3"));
	}
}