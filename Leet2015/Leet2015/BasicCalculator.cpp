#include "stdafx.h"

//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open(and closing parentheses), the plus + or minus sign - , non - negative integers and empty spaces .
//
//You may assume that the given expression is always valid.
//
//Some examples :
//"1 + 1" = 2
//" 2-1 + 2 " = 3
//"(1+(4+5+2)-3)+(6+8)" = 23
//Note : Do not use the eval built - in library function

namespace Solution1
{
	namespace tooSlow{
		bool isDigit(char c)
		{
			return  (c - '0' >= 0 && c - '0' <= 9);
		}
		int strToInt(string input)
		{
			int result = 0;
			for (char c : input)
			{
				result = result * 10 + (c - '0');
			}
			return result;
		}
		int calculate(string s) {
			stack<char> signStack;
			vector<string> post;
			int len = s.size();
			for (int i = 0; i < len; i++)
			{
				char c = s[i];
				if (c == '(') { signStack.push(c); }
				else if (c == '+' || c == '-')
				{
					while (!signStack.empty() && (signStack.top() == '+' || signStack.top() == '-'))
					{
						post.push_back(string(1, signStack.top()));
						signStack.pop();
					}
					signStack.push(c);
				}
				else if (isDigit(c))
				{
					string num;
					while (i < len && isDigit(s[i]))
					{
						num.push_back(s[i]);
						i++;
					}
					post.push_back(num);
					i--;
				}
				else if (c == ')')
				{
					while (!signStack.empty() && signStack.top() != '(')
					{
						post.push_back(string(1, signStack.top()));
						signStack.pop();
					}
					signStack.pop();
				}
			}
			while (!signStack.empty())
			{
				post.push_back(string(1, signStack.top()));
				signStack.pop();
			}

			stack<int> calcStack;
			for (string c : post)
			{
				if (c == "+" || c == "-")
				{
					int op1 = calcStack.top();
					calcStack.pop();
					int op2 = calcStack.top();
					calcStack.pop();
					if (c == "+") { calcStack.push(op2 + op1); }
					else if (c == "-") { calcStack.push(op2 - op1); }
				}
				else
				{
					calcStack.push(strToInt(c));
				}
			}
			return calcStack.top();
		}
	}

	int calculate(string s) {
		int len = s.size();
		int result = 0;
		int globalSign = 1;
		int localSign = 1;
		stack<int> signs;

		for (int i = 0; i < len; i++)
		{
			char c = s[i];
			switch (c)
			{
			case '-':
				localSign *= -1;			
			case '+':
			case ' ':
				break;
			case '(':
				signs.push(localSign);
				globalSign *= localSign;
				localSign = 1;
				break;
			case ')':
				globalSign /= signs.top();
				signs.pop();
				break;
			default:
				int num = 0;
				while (i < len && s[i] - '0' >= 0 && s[i] - '0' <= 9)
				{
					num = num * 10 + (s[i] - '0');
					i++;
				}
				result += num * localSign * globalSign;
				localSign = 1;
				i--;
			}
		}
		return result;
	}

	void BasicCalculator()
	{
		// Error: the reseting condition for localSign is any input except '-'. The pushing condition for global sign is (. The poping condition for globalsign is ).
		print(calculate("(7)-(0)+(4)"));
		// Error: note that after advance i when getting the multiple digit, you need to substract i by 1 to offset the increment done by the for loop
		print(calculate("(1)"));
		print(calculate("1 + 1"));
		print(calculate(" 2-1 + 2 "));
		print(calculate("(1+(4+5+2)-3)+(6+8)"));

		// Error: note that the input digit can be multiple digit, so the post should be vector of string, instead of vector of char
		//print(calculate("2147483647"));
	}
}