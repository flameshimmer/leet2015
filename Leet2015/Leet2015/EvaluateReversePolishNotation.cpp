#include "stdafx.h"


//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are + , -, *, / .Each operand may be an integer or another expression.
//
//Some examples :
//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//

namespace Solution1
{
	int str2int(string str)
	{
		int len = str.size();
		if (len == 0) { return 0; }
		bool isNeg = false;
		int start = 0;
		if (str[0] == '-') { isNeg = true; start = 1; }

		int result = 0;
		for (int i = start; i < len; i++)
		{
			result = result * 10 + (str[i] - '0');
		}		
		return isNeg ? (-1 * result) : result;
	}

	int evalRPN(vector<string>& tokens) 
	{
		int len = tokens.size();
		if (len == 0) { return 0; }

		stack<int> s;
		int result = 0;

		for (string str : tokens)
		{
			if (str != "+" && str != "-" &&str != "*" &&str != "/")
			{
				int val = str2int(str);
				s.push(val);
			}
			else
			{
				int op1 = s.top();
				s.pop();
				int op2 = s.top();
				s.pop();
				if (str == "+")
				{
					s.push(op2 + op1);
				}
				else if (str == "-")
				{
					s.push(op2 - op1);
				}
				else if (str == "*")
				{
					s.push(op2 * op1);
				}
				else if (str == "/")
				{
					s.push(op2 / op1);
				}
			}
		}
		result = s.top();
		return result;
	}

	void EvaluateReversePolishNotation()
	{
		vector<string> input = { "2", "1", "+", "3", "*" };
		print(evalRPN(input));

		vector<string> input2 = { "4", "13", "5", "/", "+" };
		print(evalRPN(input2));
	}
}