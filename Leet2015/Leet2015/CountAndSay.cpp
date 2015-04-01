#include "stdafx.h"

//The count - and - say sequence is the sequence of integers beginning as follows :
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.
namespace Solution1
{
	string countAndSay(int n) 
	{		
		string result = "1";
		for (int i = 1; i < n; i++)
		{
			int len = result.length();
			int count = 1;
			char c = result[0];
			string temp = "";
			for (int j = 1; j < len; j++)
			{
				if (c != result[j])
				{
					temp.push_back(count + '0');
					temp.push_back(c);
					c = result[j];
					count = 1;
				}
				else
				{
					count++;
				}
			}
			temp.push_back(count + '0');
			temp.push_back(c);
			result = temp;
		}
		return result;
	}
	
	void CountAndSay()
	{
		// Error: note to process the result again at the end of the for loop, instead of adding the (i == len-1) in the for loop condition
		//        since it will yeld to incorrect result
		print(countAndSay(3));
	}
}