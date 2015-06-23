
#include "stdafx.h"

//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non - negative integers, +, -, *, / 
//operators and empty spaces.The integer division should truncate toward zero.
//
//You may assume that the given expression is always valid.
//
//Some examples :
//"3+2*2" = 7
//" 3/2 " = 1
//" 3+5 / 2 " = 5
//Note : Do not use the eval built - in library function.

namespace Solution1
{
	namespace BII {
		int getNum(string s, int& i)
		{
			int result = 0;
			while (s[i] - '0' >= 0 && s[i] - '0' <= 9)
			{
				result = result * 10 + s[i] - '0';
				i++;
			}
			return result;
		}

		int calculate(string s)
		{
			int result = 0;
			int lastOp;
			int isMul = 0;
			bool isNeg = false;
			for (int i = 0; i < s.length(); i++)
			{
				char c = s[i];
				switch (c)
				{
				case '*':
					isMul = 1;
					break;
				case '/':
					isMul = 2;
					break;
				case ' ':
					continue;
				case '+':
					result += lastOp;
					isNeg = false;
					break;
				case '-':
					if (isNeg) { lastOp *= -1; }
					result += lastOp;
					isNeg = true;
					break;
				default:
					int op = getNum(s, i);
					if (isMul != 0)
					{
						if (isMul == 1)
						{
							lastOp *= op;
						}
						else
						{
							lastOp /= op;
						}
						isMul = 0;
					}
					else
					{
						lastOp = op;
					}
					break;
				}
			}
			if (isNeg) { lastOp *= -1; }
			result += lastOp;
			return result;
		}
	}

	namespace II
	{
		int calculate(string s)
		{
			istringstream in(s + '+');
			long long lastOp = 0;
			long long sign = 1;
			long long nextOp = 0;

			in >> lastOp;
			char op;
			int result = 0;
			while (in >> op)
			{
				if (op == '+' || op == '-')
				{
					result += sign * lastOp;
					sign = (op == '+') ? 1 : -1;
					in >> lastOp;
				}
				else
				{
					in >> nextOp;
					if (op == '*') { lastOp *= nextOp; }
					else if (op == '/') { lastOp /= nextOp; }
				}
			}
			return result;
		}
	}

	void BasicCalculatorII()
	{
		print(BII::calculate("100000000/1/2/3/4/5/6/7/8/9/10"));
		print(BII::calculate("3+2*2"));
		print(BII::calculate(" 3/2 "));
		print(BII::calculate(" 3+5 / 2 "));
	}
}